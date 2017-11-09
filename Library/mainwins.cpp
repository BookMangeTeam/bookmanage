#include "mainwins.h"
#include "ui_mainwins.h"
#include "qtablewidget.h"

MainWins::MainWins(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWins)
{
    ui->setupUi(this);

}

MainWins::~MainWins()
{
    delete ui;
}

void MainWins::on_search_btn_clicked()
{
    //QTableWidget *tableWidget = new QTableWidget(10,5); // 构造了一个QTableWidget的对象，并且设置为10行，5列
        //    也可用下面的方法构造QTableWidget对象
        //    QTableWidget *tableWidget = new QTableWidget;
        //    tableWidget->setRowCount(10);     //设置行数为10
        //    tableWidget->setColumnCount(5);   //设置列数为5

    ui->mainTableWidget->setRowCount(10);
    ui->mainTableWidget->setColumnCount(5);
    ui->mainTableWidget->resize(780, 410);  //设置表格
    QStringList header;
    header<<"书名"<<"作者"<<"出版社"<<"出版时间"<<"借阅状态";
    ui->mainTableWidget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
    ui->mainTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->mainTableWidget->setHorizontalHeaderLabels(header);
    ui->mainTableWidget->setItem(0,0,new QTableWidgetItem("Jan"));
    ui->mainTableWidget->setItem(1,0,new QTableWidgetItem("Feb"));
    ui->mainTableWidget->setItem(2,0,new QTableWidgetItem("Mar"));
}
