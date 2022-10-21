#ifndef PARSERTXT_H
#define PARSERTXT_H

#include "parser.h"


class ParserTxt : public Parser {
public:
    ParserTxt() = default;
    ~ParserTxt() = default;
    QStringList& getData(const QString& path) override;
    void addData(const QString& path, const QString &filename) override;
};

#endif // PARSERTXT_H
