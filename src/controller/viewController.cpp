#include "viewController.h"
#include "ui_viewController.h"
#include <QMessageBox>
#include <QFileDialog>
#include "../thirdpart/hellper.h"

ViewController::ViewController(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewController) {
    ui->setupUi(this);
    m_facade = new Facade();
    initializationItemWidget();
    initializationFileWidget();
}

ViewController::~ViewController() {
    delete ui;
    delete m_infoItemModel;
    delete m_instructionModel;
    delete m_firmwareModel;
    delete m_facade;
}

void ViewController::initializationItemWidget() {
    setItemModel();
    auto itemInfoPair = m_facade->getItemInfo("database/mt_5_can/info.txt", Parser_TXT);
    if (itemInfoPair.second.isEmpty()) {
        showMessageBox(this, itemInfoPair.first);
        return;
    }
    ui->itemLabel->setText(itemInfoPair.first);
    for (auto& element : itemInfoPair.second) {
        m_infoItemModel->addItem(element);
    }
}

void ViewController::setItemModel() {
    m_infoItemModel = new ItemModel(this);
    ui->itemListView->setModel(m_infoItemModel);
}

void ViewController::showMessageBox(QWidget *window, QString message) {
    QMessageBox msg_box(window);
    msg_box.setText(message);
    msg_box.exec();
}

void ViewController::initializationFileWidget() {
    m_instructionModel = new ItemModel(this);
    ui->instructionsListView->setModel(m_instructionModel);
    m_firmwareModel= new ItemModel(this);
    ui->firmwareListView->setModel(m_firmwareModel);
}

void ViewController::setInstructionsList(const QString& item) {
    m_instructionModel->clearItem();
    auto instructionPair = m_facade->getFiles(StringWorker::getPathString(item, Instructions_ID), Parser_TXT);
    if (instructionPair.second.isEmpty()) {
        showMessageBox(this, instructionPair.first);
        return;
    }
    for (auto& element : instructionPair.second) {
        m_instructionModel->addItem(element);
    }
}

void ViewController::setFirmwareList(const QString& item) {
    m_firmwareModel->clearItem();
    auto firmwarePair = m_facade->getFiles(StringWorker::getPathString(item, Firmware_ID), Parser_TXT);
    if (firmwarePair.second.isEmpty()) {
        showMessageBox(this, firmwarePair.first);
        return;
    }
    for (auto& element : firmwarePair.second) {
        m_firmwareModel->addItem(element);
    }
}

void ViewController::on_itemListView_clicked(const QModelIndex &index) {
    auto text = m_infoItemModel->data(index);
    QPair<QString, QStringList> instructionPair;
    if (ui->firmwareTab->isVisible()) {
        setFirmwareList(text.toString());
    } else {
        setInstructionsList(text.toString());
    }
}


void ViewController::on_fileTabWidget_currentChanged(int index) {
    auto item = ui->itemListView->currentIndex().data().toString();
    if (item.isEmpty()) {
        return;
    }
    if (index == Instructions_ID) {
        setInstructionsList(item);
    } else {
        setFirmwareList(item);
    }
}


void ViewController::on_fileButton_clicked() {
    auto path = QFileDialog::getOpenFileName(this, ("Добавить файл"));
    if (path.isEmpty()) {
        return;
    }
    auto fixFilename = StringWorker::getFixFilename(path);
    auto index = ui->fileTabWidget->currentIndex();
    auto item = ui->itemListView->currentIndex().data().toString();
    if (item.isEmpty()) {
        return;
    }
    if (index == Instructions_ID) {
        getAddFilenameInstructions(fixFilename, item);
    } else {
        getAddFilenameFirmware(fixFilename, item);
    }
}

void ViewController::getAddFilenameInstructions(const QString& fixFilename, const QString& item) {
    auto err = m_facade->writeInFile(StringWorker::getPathString(item, Instructions_ID), fixFilename, Parser_TXT);
    if (!err.isEmpty()) {
        showMessageBox(this, err);
        return;
    }
    m_instructionModel->addItem(fixFilename);
}

void ViewController::getAddFilenameFirmware(const QString &fixFilename, const QString &item) {
    auto err = m_facade->writeInFile(StringWorker::getPathString(item, Firmware_ID), fixFilename, Parser_TXT);
    if (!err.isEmpty()) {
        showMessageBox(this, err);
        return;
    }
    m_firmwareModel->addItem(fixFilename);
}
