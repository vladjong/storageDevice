#ifndef PARSER_H
#define PARSER_H

#include <QStringList>


class Parser {
public:
    Parser() = default;
    virtual ~Parser() = default;
    virtual QStringList& getData(const QString& path) = 0;
    virtual void addData(const QString& path, const QString &filename) = 0;
protected:
    QStringList m_data;
};

#endif // PARSER_H
