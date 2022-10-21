#include "facade.h"
#include "parserTxt.h"


const QPair<QString, QStringList> Facade::getItemInfo(const QString &filename, Parser_ID id) {
    auto pairInfo = getParserQStringList(filename, id);
    if (pairInfo.first.isEmpty()) {
        return parsingListItemInfo(pairInfo.second);
    }
    return pairInfo;
}

const QPair<QString, QStringList> Facade::getFiles(const QString &filename, Parser_ID id) {
    auto pairInfo = getParserQStringList(filename, id);
    if (pairInfo.first.isEmpty()) {
        return {"", pairInfo.second};
    }
    return pairInfo;
}

const QString Facade::writeInFile(const QString &path, const QString &filename, Parser_ID id) {
    Parser *parser = nullptr;
    try {
        parser = createParser(id);
        parser->addData(path, filename);
        delete parser;
    } catch(std::invalid_argument &ex) {
        delete parser;
        return QString::fromStdString(ex.what());
    }
    return "";

}

Parser *Facade::createParser(Parser_ID id) {
    Parser* parser;
    if (id == Parser_TXT) {
        parser = new ParserTxt();
    } else {
        throw std::invalid_argument("Ошибка: данный вид парсера не существует");
    }
    return parser;
}

const QPair<QString, QStringList> Facade::parsingListItemInfo(const QStringList &list) {
    QString itemName;
    QStringList processList;
    for (auto i = 0; i < list.size(); i++) {
        if (i == 0) {
            itemName = list[i];
            continue;
        }
        processList.append(list[i]);
    }
    return {itemName, processList};
}

const QPair<QString, QStringList> Facade::getParserQStringList(const QString &filename, Parser_ID id) {
    QStringList list;
    Parser *parser = nullptr;
    try {
        parser = createParser(id);
        list = parser->getData(filename);
        delete parser;
    } catch(std::invalid_argument &ex) {
        delete parser;
        return {QString::fromStdString(ex.what()), list};
    }
    return {"", list};
}
