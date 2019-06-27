#ifndef LOGFILEWRITER_H
#define LOGFILEWRITER_H

#include <QObject>
#include <QTime>
#include <QDebug>
#include <QFile>
#include <QDateTime>

class LogFileWriter : public QObject
{
    Q_OBJECT
public:
    explicit LogFileWriter(QStringList *strList,
                           bool lev1,
                           bool lev2,
                           bool lev3,
                           QString firstDateString,
                           QString secondDateString,
                           QObject *parent = nullptr);
    QStringList getLogList();

private:
    QStringList strList;
    QStringList logList;

    bool level1 = true;
    bool level2 = true;
    bool level3 = true;

    QDateTime firstDate;
    QDateTime secondDate;

    void selectionLogList();
    void selectionDate();

signals:

public slots:
};

#endif // LOGFILEWRITER_H
