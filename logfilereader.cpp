#include "logfilereader.h"

LogFileReader::LogFileReader(QObject *parent) : QObject(parent)
{
    // Если дата при чтении меньше текущей на месяц,
    // то запись в лист не производится
    QDateTime curData = QDateTime::currentDateTime();
    QDateTime oldDate = curData.addMonths(-1);

    QFile file(fileName);
    if (file.open(QIODevice::ReadWrite)) {
        while (!file.atEnd()) {
            QString strLog = file.readLine();
            QString strDate;
            QString dateForCheckBox;

            for (int i = 0; i < dataSize; ++i)
            {
                strDate.push_back(strLog.at(i));
            }

            QDateTime logDate;
            logDate = QDateTime::fromString(strDate,"yyyy-MM-dd hh:mm:ss.zzz");
            dateForCheckBox = logDate.toString("yyyy-MM-dd");

            if (logDate > oldDate) {
                strList.append(strLog);
                if (!dateList.contains(dateForCheckBox)) {
                    dateList.append(dateForCheckBox);
                }
            }
        }
//        if (strList.at(strList.size() - 1).contains("END PROGRAMM")) {
//            qDebug() << "END PROGRAMM";
//        }
    }
    file.close();
    file.remove();

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream textStream(&file);
        for (int i = 0; i < strList.size(); ++i)
        {
            textStream << strList.at(i);
        }
    }
    file.close();
}

QStringList LogFileReader::getLogList()
{
    return strList;
}

QStringList LogFileReader::getDateList()
{
    return dateList;
}
