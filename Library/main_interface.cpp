#include "main_interface.h"
#include "ui_main_interface.h"
#include "qtablewidget.h"

main_interface::main_interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main_interface)
{
    ui->setupUi(this);
}

main_interface::~main_interface()
{
    delete ui;
}

void main_interface::on_main_search_btn_clicked()
{
    QTableWidget *tableWidget = new QTableWidget(10,5); // 构造了一个QTableWidget的对象，并且设置为10行，5列
        //    也可用下面的方法构造QTableWidget对象
        //    QTableWidget *tableWidget = new QTableWidget;
        //    tableWidget->setRowCount(10);     //设置行数为10
        //    tableWidget->setColumnCount(5);   //设置列数为5
        tableWidget->setWindowTitle("QTableWidget & Item");
        tableWidget->resize(600, 300);  //设置表格
        QStringList header;
        header<<"Month"<<"Description";
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
        tableWidget->setHorizontalHeaderLabels(header);
            tableWidget->setItem(0,0,new QTableWidgetItem("Jan"));
            tableWidget->setItem(1,0,new QTableWidgetItem("Feb"));
            tableWidget->setItem(2,0,new QTableWidgetItem("Mar"));
        tableWidget->show();

}
