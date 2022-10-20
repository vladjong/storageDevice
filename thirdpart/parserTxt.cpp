#include "parserTxt.h"
#include <QFile>
#include <QByteArray>
#include <QString>
#include <QTextStream>
#include <QDebug>


QStringList &ParserTxt::getData(const QString &path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        throw std::invalid_argument("Ошибка: файл не существует");
    }
    QTextStream stream(&file);
    while(!file.atEnd()) {
        QStringList list = stream.readAll().split("\n");
        QListIterator<QString> li(list);
        while(li.hasNext()) {
            auto text = li.next();
            if (text.isEmpty()) {
                continue;
            }
            m_data.append(text);
        }
    }
    file.close();
    return m_data;
}

void ParserTxt::addData(const QString &path, const QString &filename) {
    QFile file(path);
    if (!file.open(QIODevice::Append)) {
        throw std::invalid_argument("Ошибка: файл не существует");
    }
    QTextStream out(&file);
    out << filename << "\n";
    file.close();
}
