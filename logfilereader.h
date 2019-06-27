#ifndef LOGFILEREADER_H
#define LOGFILEREADER_H

#include <QObject>
#include <QTime>
#include <QDebug>
#include <QFile>

class LogFileReader : public QObject
{
    Q_OBJECT
public:
    explicit LogFileReader(QObject *parent = nullptr);
    QStringList getLogList();
    QStringList getDateList();

private:
    const int dataSize = 23;    // Размер даты и времени
    const char *fileName = "logFile.txt";
    QStringList strList;
    QStringList dateList;

signals:

public slots:
};

#endif // LOGFILEREADER_H
