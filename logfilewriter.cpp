#include "logfilewriter.h"

LogFileWriter::LogFileWriter(QStringList *strList,
                             bool lev1,
                             bool lev2,
                             bool lev3,
                             QString firstDateString,
                             QString secondDateString,
                             QObject *parent)
                            : QObject(parent)
{
    this->strList = *strList;
    level1 = lev1;
    level2 = lev2;
    level3 = lev3;
    firstDate = QDateTime::fromString(firstDateString, "yyyy-MM-dd");
    secondDate = QDateTime::fromString(secondDateString, "yyyy-MM-dd");

    selectionDate();
    selectionLogList();
}

QStringList LogFileWriter::getLogList()
{
    return logList;
}

void LogFileWriter::selectionLogList()
{
    // Сортировка лог файла по уровню лога
    for (int i = 0; i < strList.size(); ++i)
    {
        if (strList.at(i).contains("LEVEL1") && level1) {
            logList.append(strList.at(i));
        }
        if (strList.at(i).contains("LEVEL2") && level2) {
            logList.append(strList.at(i));
        }
        if (strList.at(i).contains("LEVEL3") && level3) {
            logList.append(strList.at(i));
        }
    }
}

void LogFileWriter::selectionDate()
{
    // Сортировка лог файла по выбранному промежутку дат
    const int dataSize = 10;
    QStringList dateList;
    for (int i = 0; i < strList.size(); ++i)
    {
        QString strDate;
        QString strLog = strList.at(i);
        for (int j = 0; j < dataSize; ++j)
        {
            strDate.push_back(strLog.at(j));
        }
        QDateTime curDate = QDateTime::fromString(strDate, "yyyy-MM-dd");
        if ((curDate >= firstDate) && (curDate <= secondDate)) {
            dateList.append(strLog);
        }
    }
    strList = dateList;
}
