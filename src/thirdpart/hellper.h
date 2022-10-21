#ifndef HELLPER_H
#define HELLPER_H

#include <QString>

enum Tab_ID { Instructions_ID = 0, Firmware_ID = 1 };

class StringWorker {
public:
    StringWorker() = default;
    ~StringWorker() = default;
    static const QString getPathString(const QString& item, Tab_ID id);
    static const QString getFixFilename(const QString &fileName);
};

#endif // HELLPER_H
