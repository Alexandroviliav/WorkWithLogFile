#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "logfilereader.h"
#include "logfilewriter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonOpenLog_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    LogFileReader *reader;
    void setCheckBoxItems();
};
#endif // MAINWINDOW_H
