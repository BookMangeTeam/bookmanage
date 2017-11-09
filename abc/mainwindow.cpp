#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QStackedWidget>
#include <QStandardItemModel>
#include <QHeaderView>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    this->ui->friendList->setSelectionBehavior(QAbstractItemView::SelectRows);  //单击选择一行
//    this->ui->friendList->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
//    this->ui->friendList->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置每行内容不可更改
//    this->ui->friendList->setAlternatingRowColors(true);//设置隔一行变一颜色，即：一灰一白



    ui->stackedWidgetPermary->setCurrentIndex(0);

    //借书信息表
    //设置表头
    QStandardItemModel *bookInformationborrow = new QStandardItemModel();
    bookInformationborrow->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("索引号")));
    bookInformationborrow->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationborrow->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    bookInformationborrow->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版日期")));
    bookInformationborrow->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("状态")));//已借，可借

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationborrow->setModel(bookInformationborrow);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->bookInformationborrow->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->bookInformationborrow->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->bookInformationborrow->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->bookInformationborrow->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->bookInformationborrow->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    //设置表格的各列的宽度值
    ui->bookInformationborrow->setColumnWidth(0,110);
    ui->bookInformationborrow->setColumnWidth(1,230);
    ui->bookInformationborrow->setColumnWidth(2,230);
    ui->bookInformationborrow->setColumnWidth(3,130);
    ui->bookInformationborrow->setColumnWidth(4,80);

    //设置选中时为整行选中
    ui->bookInformationborrow->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑（用户不能编辑，管理员可以）
    ui->bookInformationborrow->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置隔一行变一颜色，即：一灰一白
    ui->bookInformationborrow->setAlternatingRowColors(true);

    //设置只能选择一行，不能多行选中
    ui->bookInformationborrow->setSelectionMode(QAbstractItemView::SingleSelection);

    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->bookInformationborrow->setContextMenuPolicy(Qt::CustomContextMenu);


    //还书信息表
    //设置表头
    QStandardItemModel *bookInformationRepay = new QStandardItemModel();
    bookInformationRepay->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("索引号")));
    bookInformationRepay->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationRepay->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    bookInformationRepay->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版日期")));
    bookInformationRepay->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("最后还书日期")));
    bookInformationRepay->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("状态")));//超期，未超期

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationRepay->setModel(bookInformationRepay);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->bookInformationRepay->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->bookInformationRepay->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->bookInformationRepay->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->bookInformationRepay->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->bookInformationRepay->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->bookInformationRepay->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    //设置表格的各列的宽度值
    ui->bookInformationRepay->setColumnWidth(0,110);
    ui->bookInformationRepay->setColumnWidth(1,180);
    ui->bookInformationRepay->setColumnWidth(2,180);
    ui->bookInformationRepay->setColumnWidth(3,125);
    ui->bookInformationRepay->setColumnWidth(4,125);
    ui->bookInformationRepay->setColumnWidth(5,80);

    //设置选中时为整行选中
    ui->bookInformationRepay->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->bookInformationRepay->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置隔一行变一颜色，即：一灰一白
    ui->bookInformationRepay->setAlternatingRowColors(true);

    //设置只能选择一行，不能多行选中
    ui->bookInformationRepay->setSelectionMode(QAbstractItemView::SingleSelection);


    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->bookInformationRepay->setContextMenuPolicy(Qt::CustomContextMenu);



    //续借信息表
    //设置表头
    QStandardItemModel *bookInformationRenew = new QStandardItemModel();
    bookInformationRenew->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("索引号")));
    bookInformationRenew->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationRenew->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    bookInformationRenew->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版日期")));
    bookInformationRenew->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("最后还书日期")));
    bookInformationRenew->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("状态")));//可续借，不可续借（超过续借次数）

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationRenew->setModel(bookInformationRepay);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->bookInformationRenew->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->bookInformationRenew->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->bookInformationRenew->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->bookInformationRenew->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->bookInformationRenew->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->bookInformationRenew->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    //设置表格的各列的宽度值
    ui->bookInformationRenew->setColumnWidth(0,110);
    ui->bookInformationRenew->setColumnWidth(1,180);
    ui->bookInformationRenew->setColumnWidth(2,180);
    ui->bookInformationRenew->setColumnWidth(3,125);
    ui->bookInformationRenew->setColumnWidth(4,125);
    ui->bookInformationRenew->setColumnWidth(5,80);

    //设置选中时为整行选中
    ui->bookInformationRenew->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->bookInformationRenew->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置隔一行变一颜色，即：一灰一白
    ui->bookInformationRenew->setAlternatingRowColors(true);

    //设置只能选择一行，不能多行选中
    ui->bookInformationRenew->setSelectionMode(QAbstractItemView::SingleSelection);

    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->bookInformationRenew->setContextMenuPolicy(Qt::CustomContextMenu);


    //借书记录表
    //设置表头
    QStandardItemModel *bookInformationBorrowR = new QStandardItemModel();
    bookInformationBorrowR->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("索引号")));
    bookInformationBorrowR->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationBorrowR->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    bookInformationBorrowR->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("借/续书日期")));
    bookInformationBorrowR->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("最后还书日期")));
    bookInformationBorrowR->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("状态")));//借，续
    bookInformationBorrowR->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("扣费")));

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationBorrowR->setModel(bookInformationBorrowR);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);
    //设置表格的各列的宽度值
    ui->bookInformationBorrowR->setColumnWidth(0,80);
    ui->bookInformationBorrowR->setColumnWidth(1,180);
    ui->bookInformationBorrowR->setColumnWidth(2,180);
    ui->bookInformationBorrowR->setColumnWidth(3,100);
    ui->bookInformationBorrowR->setColumnWidth(4,100);
    ui->bookInformationBorrowR->setColumnWidth(5,80);
    ui->bookInformationBorrowR->setColumnWidth(6,80);

    //设置选中时为整行选中
    ui->bookInformationBorrowR->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->bookInformationBorrowR->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置隔一行变一颜色，即：一灰一白
    ui->bookInformationBorrowR->setAlternatingRowColors(true);

    //设置只能选择一行，不能多行选中
    ui->bookInformationBorrowR->setSelectionMode(QAbstractItemView::SingleSelection);

    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->bookInformationBorrowR->setContextMenuPolicy(Qt::CustomContextMenu);


    //欠费记录表
    //设置表头
    QStandardItemModel *inDebtInformation = new QStandardItemModel();
    inDebtInformation->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("索引号")));
    inDebtInformation->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    inDebtInformation->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    inDebtInformation->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("还书日期")));
    inDebtInformation->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("状态")));
    inDebtInformation->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("扣费")));
    inDebtInformation->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("余额")));

    //利用setModel()方法将数据模型与QTableView绑定
    ui->inDebtInformation->setModel(inDebtInformation);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->inDebtInformation->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->inDebtInformation->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->inDebtInformation->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->inDebtInformation->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->inDebtInformation->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->inDebtInformation->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->inDebtInformation->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);
    //设置表格的各列的宽度值
    ui->inDebtInformation->setColumnWidth(0,80);
    ui->inDebtInformation->setColumnWidth(1,180);
    ui->inDebtInformation->setColumnWidth(2,180);
    ui->inDebtInformation->setColumnWidth(3,100);
    ui->inDebtInformation->setColumnWidth(4,100);
    ui->inDebtInformation->setColumnWidth(5,80);
    ui->inDebtInformation->setColumnWidth(6,80);

    //设置选中时为整行选中
    ui->inDebtInformation->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->inDebtInformation->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置隔一行变一颜色，即：一灰一白
    ui->inDebtInformation->setAlternatingRowColors(true);

    //设置只能选择一行，不能多行选中
    ui->inDebtInformation->setSelectionMode(QAbstractItemView::SingleSelection);

    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->inDebtInformation->setContextMenuPolicy(Qt::CustomContextMenu);


    //缴费记录表
    //设置表头
    QStandardItemModel *paymentInformation = new QStandardItemModel();
    paymentInformation->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("缴费时间")));
    paymentInformation->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("缴费金额")));
    paymentInformation->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("余额")));
    paymentInformation->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("状态")));//成功 失败


    //利用setModel()方法将数据模型与QTableView绑定
    ui->paymentInformation->setModel(paymentInformation);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->paymentInformation->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->paymentInformation->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->paymentInformation->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->paymentInformation->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);


    //设置表格的各列的宽度值
    ui->paymentInformation->setColumnWidth(0,110);
    ui->paymentInformation->setColumnWidth(1,110);
    ui->paymentInformation->setColumnWidth(2,110);
    ui->paymentInformation->setColumnWidth(3,110);


    //设置选中时为整行选中
    ui->paymentInformation->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->paymentInformation->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置隔一行变一颜色，即：一灰一白
    ui->paymentInformation->setAlternatingRowColors(true);

    //设置只能选择一行，不能多行选中
    ui->paymentInformation->setSelectionMode(QAbstractItemView::SingleSelection);

    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->paymentInformation->setContextMenuPolicy(Qt::CustomContextMenu);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_borrowButton_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(1);
}


void MainWindow::on_returnButtonBorrow_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(0);
}


void MainWindow::on_repayButton_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(2);
}
void MainWindow::on_returnButtonRepay_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(0);
}


void MainWindow::on_renewButton_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(3);
}

void MainWindow::on_returnButtonRenew_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(0);
}

void MainWindow::on_borrowRecordButton_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(4);
}

void MainWindow::on_returnBottonBorrowR_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(0);
}

void MainWindow::on_moneyBotton_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(5);
}

void MainWindow::on_returnButtonMoney_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(0);
}

void MainWindow::on_quitButton_clicked()
{
    exit(0);
}
