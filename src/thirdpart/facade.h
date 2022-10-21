#ifndef FACADE_H
#define FACADE_H

#include "parser.h"
#include <QPair>

enum Parser_ID {Parser_TXT=0};

class Facade {
public:
    Facade() = default;
    ~Facade() = default;

    const QPair<QString, QStringList> getItemInfo(const QString& filename, Parser_ID id);
    const QPair<QString, QStringList> getFiles(const QString& filename, Parser_ID id);
    const QString writeInFile(const QString &path, const QString &filename, Parser_ID id);
private:
    Parser* createParser(Parser_ID id);
    const QPair<QString, QStringList> parsingListItemInfo(const QStringList& list);
    const QPair<QString, QStringList> getParserQStringList(const QString& filename, Parser_ID id);
};

#endif // FACADE_H
