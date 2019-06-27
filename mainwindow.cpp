#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("LogFileReader");
//    qDebug() << "MainWindow::LEVEL2::startRadiography";
    reader = new LogFileReader;
    setCheckBoxItems();
}

MainWindow::~MainWindow()
{
//    qDebug() << "LEVEL1::END PROGRAMM";
    delete ui;
}

void MainWindow::on_pushButtonOpenLog_clicked()
{
    ui->listWidget->clear();
    QStringList logListBeforeSelection = reader->getLogList();

    bool lev1 = ui->checkBoxLevel1->isChecked();
    bool lev2 = ui->checkBoxLevel2->isChecked();
    bool lev3 = ui->checkBoxLevel3->isChecked();
    QString firstDate = ui->comboBox_2->currentText();
    QString secondDate = ui->comboBox->currentText();

    LogFileWriter writer(&logListBeforeSelection, lev1, lev2, lev3, firstDate, secondDate);
    QStringList logListAfterSelection = writer.getLogList();

    for (int i = 0; i < logListAfterSelection.size(); ++i)
    {
       ui->listWidget->addItem(logListAfterSelection.at(i));
    }
}

void MainWindow::setCheckBoxItems()
{
    QStringList listForCheckBox = reader->getDateList();
    for (int i = 0; i < listForCheckBox.size(); ++i)
    {
        ui->comboBox_2->addItem(listForCheckBox.at(i));
    }
}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
   // При изменении комбобокса выбора первой даты,
   // вторая дата должна быть не меньше первой
   QString curDataComboBox = ui->comboBox->currentText();
   ui->comboBox->clear();
   QStringList listForCheckBox = reader->getDateList();
   QDateTime firstDate = QDateTime::fromString(arg1, "yyyy-MM-dd");

   for (int i = 0; i < listForCheckBox.size(); ++i)
   {
       QDateTime secondDate = QDateTime::fromString(listForCheckBox.at(i), "yyyy-MM-dd");
       if (secondDate >= firstDate) {
           ui->comboBox->addItem(listForCheckBox.at(i));
       }
   }
   for (int i = 0; i < ui->comboBox->count() - 1; ++i)
   {
       if (ui->comboBox->currentText() != curDataComboBox) {
          ui->comboBox->setCurrentIndex(ui->comboBox->currentIndex() + 1);
       }
   }
}
