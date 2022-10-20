#include "hellper.h"
#include <QDir>
#include <QDebug>

const QString StringWorker::getPathString(const QString& item, Tab_ID id) {

    QDir temDir("database/mt_5_can/");
    QString firmware = "firmware/";
    QString instruction = "instruction/";
    QString txtFormat = ".txt";
    QString path = filePath + instruction + item + txtFormat;
    qDebug() << path;
    if (id == Instructions_ID) {
        return path;
    } else if (id == Firmware_ID) {
        return path;
    }
    throw std::invalid_argument("Ошибка: такой формы не существует");
}

const QString StringWorker::getFixFilename(const QString &fileName) {
    qsizetype n = fileName.lastIndexOf('/') + 1;
    QString fixFilename = fileName.right(fileName.size() - n);
    return fixFilename;
}
