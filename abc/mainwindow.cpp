#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QStackedWidget>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QMessageBox>
#include "qstring.h"
#include <b_plus_tree.h>
#include <global_variable.h>
#include <QDateTime>
#include <QDate>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    this->ui->friendList->setSelectionBehavior(QAbstractItemView::SelectRows);  //单击选择一行
//    this->ui->friendList->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
//    this->ui->friendList->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置每行内容不可更改
//    this->ui->friendList->setAlternatingRowColors(true);//设置隔一行变一颜色，即：一灰一白


    //首页界面
    ui->stackedWidgetPermary->setCurrentIndex(0);

    //续借信息表
    //设置表头
    QStandardItemModel *bookInformationRenew_model = new QStandardItemModel();
    bookInformationRenew_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("索引号")));
    bookInformationRenew_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationRenew_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    bookInformationRenew_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版日期")));
    bookInformationRenew_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("最后还书日期")));
    bookInformationRenew_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("状态")));//可续借，不可续借（超过续借次数）

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationRenew->setModel(bookInformationRenew_model);

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
    QStandardItemModel *bookInformationBorrowR_model = new QStandardItemModel();
    bookInformationBorrowR_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("索引号")));
    bookInformationBorrowR_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationBorrowR_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    bookInformationBorrowR_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("借/续书日期")));
    bookInformationBorrowR_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("最后还书日期")));
    bookInformationBorrowR_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("状态")));//借，续
    bookInformationBorrowR_model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("扣费")));

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationBorrowR->setModel(bookInformationBorrowR_model);

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
    QStandardItemModel *inDebtInformation_model = new QStandardItemModel();
    inDebtInformation_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("索引号")));
    inDebtInformation_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    inDebtInformation_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    inDebtInformation_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("还书日期")));
    inDebtInformation_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("状态")));
    inDebtInformation_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("扣费")));
    inDebtInformation_model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("余额")));

    //利用setModel()方法将数据模型与QTableView绑定
    ui->inDebtInformation->setModel(inDebtInformation_model);

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
    QStandardItemModel *paymentInformation_model = new QStandardItemModel();
    paymentInformation_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("缴费时间")));
    paymentInformation_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("缴费金额")));
    paymentInformation_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("余额")));
    paymentInformation_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("状态")));//成功 失败


    //利用setModel()方法将数据模型与QTableView绑定
    ui->paymentInformation->setModel(paymentInformation_model);

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

    //借书信息表
    //设置表头
    QStandardItemModel *bookInformationborrow_model = new QStandardItemModel();
    bookInformationborrow_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("编号")));
    bookInformationborrow_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationborrow_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("作者")));
    bookInformationborrow_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版社")));
    bookInformationborrow_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("状态")));//已借，可借

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationborrow->setModel(bookInformationborrow_model);

    //设置表格的各列的宽度值
    ui->bookInformationborrow->setColumnWidth(0,110);
    ui->bookInformationborrow->setColumnWidth(1,230);
    ui->bookInformationborrow->setColumnWidth(2,130);
    ui->bookInformationborrow->setColumnWidth(3,230);
    ui->bookInformationborrow->setColumnWidth(4,80);
}


void MainWindow::on_returnButtonBorrow_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(0);
}


void MainWindow::on_repayButton_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(2);
    //书籍编号 书名 作者 出版社 最后还书时间 是否超期
    //还书信息表
        //设置表头
        QStandardItemModel *bookInformationRepay_model = new QStandardItemModel();
        bookInformationRepay_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("索引号")));
        bookInformationRepay_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
        bookInformationRepay_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
        bookInformationRepay_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("作者")));
        bookInformationRepay_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("最后还书日期")));
        bookInformationRepay_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("状态")));//超期，未超期

        //利用setModel()方法将数据模型与QTableView绑定
        ui->bookInformationRepay->setModel(bookInformationRepay_model);

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
    int i,line = 0;
    ui->stackedWidgetPermary->setCurrentIndex(2);

    BPlusTree<int> Borrow;
    Borrow.SetTableName(string("Borrow"));
    Borrow.ReadHead();  //读取文件

    const char* record_username_s = record_username.toStdString().data();//who登录的转const char*
    vector<pair< int,vector<Undecide> > > all;
    all = Borrow.AllLeaf();//遍历借书表查找此用户借的书
    for(int i = 0; i < all.size(); i++)
    {
        cout << (all[i].second)[1].s;
        cout << record_username_s;
        if(((all[i].second)[1].s) == record_username)//找到此人
        {
            //all[i].first为借的书的key
            //(all[i].second)[0].s为书籍编号
            QString bookNumber_q = QString::fromStdString((all[i].second)[0].s);//string转qstring
            bookInformationRepay_model->setItem(line,0,new QStandardItem(bookNumber_q)); //图书编号

            //(all[i].second)[2].s为借阅时间
            //最后还书日期
            char* borrowTime = const_cast<char*>((all[i].second)[2].s);//const char*转char*
            QString borrowTime_q = QString(QLatin1String(borrowTime));//char*转QString
            QDateTime borrowTime_qq = QDateTime::fromString(borrowTime_q, "yyyy/MM/dd");//借书时间QString转化为QDateTime
            QDateTime lastTime = borrowTime_qq.addDays(30);
            QString lastTime_q = lastTime.toString("yyyy/MM/dd");
            bookInformationRepay_model->setItem(line,4,new QStandardItem(lastTime_q));

            //获取当前时间
            QDateTime current_date_time = QDateTime::currentDateTime();
//            QString current_date = current_date_time.toString("yyyy/MM/dd");
//            const char *current_date_s = current_date.toStdString().data();

            if(lastTime.operator <=(current_date_time))
            {
                int days;
                bookInformationRepay_model->setItem(line,5,new QStandardItem("超期"));
                days = lastTime.daysTo(current_date_time);
                //根据天数计算钱
            }
            else
            {
                bookInformationRepay_model->setItem(line,5,new QStandardItem("未超期"));
            }

            //BookA里查isbn
            BPlusTree<string> BookA;
            BookA.SetTableName(string("BookA"));
            BookA.ReadHead();  //读取文件

            Return3 result1 = BookA.Search((all[i].second)[0].s,BookA.GetRootName());
            if(result1.Succ)
            {
                //result1.ve[4].s为isbn
                //去BookB表查询书籍信息
                BPlusTree<string> BookB;
                BookB.SetTableName(string("BookB"));
                BookB.ReadHead();  //读取文件
                Return3 result2 = BookB.Search(result1.ve[4].s,BookB.GetRootName());

                if(result2.Succ)
                {
                    //书名
                    char* bookName = const_cast<char*>(result2.ve[0].s);//const char*转char*
                    QString bookName_q = QString(QLatin1String(bookName));//char*转QString
                    bookInformationRepay_model->setItem(line,1,new QStandardItem(bookName_q));
                    //作者
                    char* author = const_cast<char*>(result2.ve[2].s);//const char*转char*
                    QString author_q = QString(QLatin1String(author));//char*转QString
                    bookInformationRepay_model->setItem(line,2,new QStandardItem(author_q));
                    //出版社
                    char* publishHouse = const_cast<char*>(result2.ve[1].s);//const char*转char*
                    QString publishHouse_q = QString(QLatin1String(publishHouse));//char*转QString
                    bookInformationRepay_model->setItem(line,3,new QStandardItem(publishHouse_q));
                }
            }
        }
    }

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

void MainWindow::on_searchButtonPermary_clicked()
{

    //获取搜索框的信息
    QString search_info = ui->searchLineEditPermary->text();
//    if(search_info == NULL)
//    {
//        //输入内容为空
//        QMessageBox::critical(this, "critical", "输入内容不能为空!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
//    }
//    else
//    {
//        //根据输入内容到数据库进行搜索并且返回内容显示到该页面上
//        ui->stackedWidgetPermary->setCurrentIndex(1);
//        ui->searchLineEditBorrow->setText(search_info);
//        //ui->searchLineEditBorrow->setCursorMoveStyle(Qt::CursorMoveStyle );

//    }

}


void MainWindow::on_searchButtonBorrow_clicked()
{
//    QStandardItemModel *bookInformationborrow_model;
//    ui->bookInformationborrow->setModel(bookInformationborrow_model);
    QStandardItemModel *bookInformationborrow_model = new QStandardItemModel();
    bookInformationborrow_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("编号")));
    bookInformationborrow_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationborrow_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("作者")));
    bookInformationborrow_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版社")));
    bookInformationborrow_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("状态")));//已借，可借

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationborrow->setModel(bookInformationborrow_model);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->bookInformationborrow->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->bookInformationborrow->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->bookInformationborrow->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->bookInformationborrow->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->bookInformationborrow->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    //设置表格的各列的宽度值
    ui->bookInformationborrow->setColumnWidth(0,110);
    ui->bookInformationborrow->setColumnWidth(1,230);
    ui->bookInformationborrow->setColumnWidth(2,130);
    ui->bookInformationborrow->setColumnWidth(3,230);
    ui->bookInformationborrow->setColumnWidth(4,80);

    //设置选中时为整行选中
    ui->bookInformationborrow->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑（用户不能编辑，管理员可以）
    ui->bookInformationborrow->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置隔一行变一颜色，即：一灰一白
    ui->bookInformationborrow->setAlternatingRowColors(true);

    //设置只能选择一行，不能多行选中
    ui->bookInformationborrow->setSelectionMode(QAbstractItemView::SingleSelection);

    int line = 0;
    //在借书页面的搜索按钮
    QString search_info = ui->searchLineEditBorrow->text();
    if(search_info == NULL)
    {
        //输入内容为空
        QMessageBox::critical(this, "critical", "输入内容不能为空!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else
    {
        //根据输入内容到数据库进行搜索并且返回内容显示到table中
                const char *search_info_s = search_info.toStdString().data();
                BPlusTree<string> BookB;
                BookB.SetTableName(string("BookB"));
                BookB.ReadHead();  //读取文件

                Return3 result1 = BookB.Search(search_info_s,BookB.GetRootName());
                if(result1.Succ)
                {
                    BPlusTree<string> BookA;
                    BookA.SetTableName(string("BookA"));
                    BookA.ReadHead();  //读取文件
                    vector<pair< string,vector<Undecide> > > all;
                    all = BookA.AllLeaf();
                    for(int i = 0; i < all.size(); i++)
                    {
                        if((all[i].second)[4].s == search_info)//有
                        {
                            QString bookNumber_q = QString::fromStdString(all[i].first);//string转QString
                            bookInformationborrow_model->setItem(line,0,new QStandardItem(bookNumber_q));


                            char* bookName = const_cast<char*>(result1.ve[0].s);//const char*转char*
                            QString bookName_q = QString(QLatin1String(bookName));//char*转QString
                            bookInformationborrow_model->setItem(line,1,new QStandardItem(bookName_q));

                            char* author = const_cast<char*>(result1.ve[1].s);//const char*转char*
                            QString author_q = QString(QLatin1String(author));//char*转QString
                            bookInformationborrow_model->setItem(line,2,new QStandardItem(author_q));

                            char* publishHouse = const_cast<char*>(result1.ve[2].s);//const char*转char*
                            QString publishHouse_q = QString(QLatin1String(publishHouse));//char*转QString
                            bookInformationborrow_model->setItem(line,3,new QStandardItem(publishHouse_q));

                            if((all[i].second)[2].is == 0)
                            {
                                bookInformationborrow_model->setItem(line,4,new QStandardItem("可借"));
                            }
                            else
                            {
                                bookInformationborrow_model->setItem(line,4,new QStandardItem("不可借"));
                            }
                            line++;
                        }
                    }
                }
        }
}

void MainWindow::on_affirmBottonBorrow_clicked()
{
    BPlusTree<int> Borrow;
    Borrow.SetTableName(string("Borrow"));
    Borrow.ReadHead();

    int row = ui->bookInformationborrow->currentIndex().row();//选中行的行号
    //获取书的编号
    QAbstractItemModel *model = ui->bookInformationborrow->model();
    QModelIndex index = model->index(row,0);//选中行第一列的内容
    QVariant data = model->data(index);
    const char *data_s = data.toString().toStdString().data();//先转Qstring再转const char*

    BPlusTree<string> BookA;
    BookA.SetTableName(string("BookA"));
    BookA.ReadHead();
    Return3 result1 = BookA.Search(data_s,BookA.GetRootName());
    if(result1.Succ)
    {
        if(result1.ve[2].is == 0)
        {
            //导入信息到borrow表
            vector<Undecide>borrowv;
            Undecide te1,te2,te3;
            strcpy(te1.s,data_s);//书的编号
            const char *record_username_s = record_username.toStdString().data();
            strcpy(te2.s,record_username_s);//借书人
            QDateTime current_date_time = QDateTime::currentDateTime();
            QString current_date = current_date_time.toString("yyyy/MM/dd");
            const char *current_date_s = current_date.toStdString().data();
            strcpy(te3.s,current_date_s);//借书时间*/
            borrowv.push_back(te1);
            borrowv.push_back(te2);
            borrowv.push_back(te3);
            Borrow.Insert(borrow_key,borrowv);
            Borrow.SaveHead();//一定要记得保存！

            QMessageBox::information(this, "提示", "借书成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

            vector<Undecide>Bookav;//将BookA中的是否可借的值改为false
            Undecide te4,te5,te6,te7,te8,te9;
            strcpy(te4.s,data_s);
            strcpy(te5.s,result1.ve[0].s);
            strcpy(te6.s,result1.ve[1].s);
            te7.is = 1;
            te8.is = result1.ve[3].is;
            strcpy(te9.s,result1.ve[4].s);
            Bookav.push_back(te5);
            Bookav.push_back(te6);
            Bookav.push_back(te7);
            Bookav.push_back(te8);
            Bookav.push_back(te9);
            BookA.Update(data_s,Bookav);
            BookA.SaveHead();
        }
        else
        {
            QMessageBox::information(this, "提示", "该书不可被借！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }

    }
    borrow_key++;

}

void MainWindow::on_affirmBottonRepay_clicked()
{

}
