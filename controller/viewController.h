#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QMainWindow>

#include "../model/itemmodel.h"
#include "../thirdpart/facade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ViewController; }
QT_END_NAMESPACE

class ViewController : public QMainWindow {
    Q_OBJECT

public:
    ViewController(QWidget *parent = nullptr);
    ~ViewController();

private slots:
    void on_itemListView_clicked(const QModelIndex &index);
    void on_fileTabWidget_currentChanged(int index);
    void on_fileButton_clicked();

private:
    Ui::ViewController *ui;
    ItemModel *m_infoItemModel;
    ItemModel *m_instructionModel;
    ItemModel *m_firmwareModel;
    Facade *m_facade;

    void initializationItemWidget();
    void setItemModel();
    void showMessageBox(QWidget *window, QString message);
    void initializationFileWidget();
    void setInstructionsList(const QString& item);
    void setFirmwareList(const QString& item);
    void getAddFilenameInstructions(const QString& fixFilename, const QString& item);
    void getAddFilenameFirmware(const QString& fixFilename, const QString& item);
};

#endif // VIEWCONTROLLER_H
