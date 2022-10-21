#include "hellper.h"
#include <QDir>

const QString StringWorker::getPathString(const QString& item, Tab_ID id) {
    QString filePath = "database/mt_5_can/";
    QString firmware = "firmware/";
    QString instruction = "instruction/";
    QString txtFormat = ".txt";
    if (id == Instructions_ID) {
        return filePath + instruction + item + txtFormat;
    } else if (id == Firmware_ID) {
        return filePath + firmware + item + txtFormat;
    }
    throw std::invalid_argument("Ошибка: такой формы не существует");
}

const QString StringWorker::getFixFilename(const QString &fileName) {
    auto n = fileName.lastIndexOf('/') + 1;
    QString fixFilename = fileName.right(fileName.size() - n);
    return fixFilename;
}
