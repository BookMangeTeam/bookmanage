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
#include <QDebug>
#include <QCryptographichash.h> //md5加密封装类
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
    bookInformationborrow_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("图书编号")));
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
        bookInformationRepay_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("图书编号")));
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
    int line = 0;
    ui->stackedWidgetPermary->setCurrentIndex(2);

    BPlusTree<int> Borrow;
    Borrow.SetTableName(string("Borrow"));
    Borrow.ReadHead();  //读取文件

    const char* record_username_s = record_username.toStdString().data();//who登录的转const char*
    vector<pair< int,vector<Undecide> > > all;
    all = Borrow.AllLeaf();//遍历借书表查找此用户借的书
    for(int i = 0; i < all.size(); i++)
    {
        if(((all[i].second)[1].s) == record_username)//找到此人
        {
            BPlusTree<string> BookA;
            BookA.SetTableName(string("BookA"));
            BookA.ReadHead();  //读取文件
            Return3 result3 = BookA.Search((all[i].second)[0].s,BookA.GetRootName());
            if(result3.Succ)
            {
                //没还并且最新借阅人为此人就显示
                if((result3.ve[2].num == 1) && (result3.ve[0].s == record_username)&&((all[i].second)[4].num == 0))
                {
                    //all[i].first为借的书的key
                    //(all[i].second)[0].s为书籍编号
                    QString bookNumber_q = QString::fromStdString((all[i].second)[0].s);//string转qstring
                    bookInformationRepay_model->setItem(line,0,new QStandardItem(bookNumber_q)); //图书编号

                    //(all[i].second)[2].s为借阅时间
                    //最后还书日期
                    char* lastTime = const_cast<char*>((all[i].second)[3].s);//const char*转char*
                    QString lastTime_q = QString(QLatin1String(lastTime));//char*转QString
                    QDateTime lastTime_qq = QDateTime::fromString(lastTime_q, "yyyy/MM/dd");//借书时间QString转化为QDateTime
//                    QDateTime lastTime = borrowTime_qq.addDays(30);
//                    QString lastTime_q = lastTime.toString("yyyy/MM/dd");
                    bookInformationRepay_model->setItem(line,4,new QStandardItem(lastTime_q));

                    //获取当前时间
                    QDateTime current_date_time = QDateTime::currentDateTime();
        //            QString current_date = current_date_time.toString("yyyy/MM/dd");
        //            const char *current_date_s = current_date.toStdString().data();

                    if(lastTime_qq.operator <=(current_date_time))
                    {
                        bookInformationRepay_model->setItem(line,5,new QStandardItem("超期"));
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
                    line++;
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
    //续借信息表
    //设置表头
    QStandardItemModel *bookInformationRenew_model = new QStandardItemModel();
    bookInformationRenew_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("图书编号")));
    bookInformationRenew_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationRenew_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("作者")));
    bookInformationRenew_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版社")));
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
    ui->bookInformationRenew->setColumnWidth(2,125);
    ui->bookInformationRenew->setColumnWidth(3,180);
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

    //图书编号 书名  作者 出版社 最后还书日期 状态
    int line = 0;
    const char* record_username_s = record_username.toStdString().data();//who登录的转const char*
    BPlusTree<int> Borrow;
    Borrow.SetTableName(string("Borrow"));
    Borrow.ReadHead();  //读取文件
    //在borrow中找这个用户所借或借过的书
    vector<pair< int,vector<Undecide> > > all;
    all = Borrow.AllLeaf();
    for(int i = 0; i < all.size(); i++)
    {
        if((all[i].second)[1].s == record_username)
        {
            if((all[i].second)[3].num == 0)
            {
                //(all[i].second)[0].s这个人借的书的编号
                //显示图书编号
                char* bookNumber = const_cast<char*>((all[i].second)[0].s);//const char*转char*
                QString bookNumber_q = QString(QLatin1String(bookNumber));//char*转QString
                bookInformationRenew_model->setItem(line,0,new QStandardItem(bookNumber_q));
                //最后还书日期
                char* lastTime = const_cast<char*>((all[i].second)[2].s);//const char*转char*
                QString lastTime_q = QString(QLatin1String(lastTime));//char*转QString
                bookInformationRenew_model->setItem(line,4,new QStandardItem(lastTime_q));

                BPlusTree<string> BookA;
                BookA.SetTableName(string("BookA"));
                BookA.ReadHead();

                Return3 result1 = BookA.Search((all[i].second)[0].s,BookA.GetRootName());
                if(result1.Succ)
                {
                    BPlusTree<string> BookB;
                    BookB.SetTableName(string("BookB"));
                    BookB.ReadHead();
                    //result1.ve[4].s为isbn
                    Return3 result2 = BookB.Search(result1.ve[4].s,BookB.GetRootName());
                    if(result2.Succ)
                    {
                        //显示书名
                        char* bookName = const_cast<char*>(result2.ve[0].s);//const char*转char*
                        QString bookName_q = QString(QLatin1String(bookName));//char*转QString
                        bookInformationRenew_model->setItem(line,1,new QStandardItem(bookName_q));
                        //作者
                        char* author = const_cast<char*>(result2.ve[1].s);//const char*转char*
                        QString author_q = QString(QLatin1String(author));//char*转QString
                        bookInformationRenew_model->setItem(line,2,new QStandardItem(author_q));
                        //出版社
                        char* publishHouse = const_cast<char*>(result2.ve[2].s);//const char*转char*
                        QString publishHouse_q = QString(QLatin1String(publishHouse));//char*转QString
                        bookInformationRenew_model->setItem(line,3,new QStandardItem(publishHouse_q));
                    }
                }
                QDateTime current_date_time = QDateTime::currentDateTime();
                QDateTime lastTime_qq = QDateTime::fromString(lastTime_q, "yyyy/MM/dd");//借书时间QString转化为QDateTime
                int days = lastTime_qq.daysTo(current_date_time);
                cout<< days;
                if(days <= 0)
                {
                    //没超期并且没还可续借
                        bookInformationRenew_model->setItem(line,5,new QStandardItem("可续借"));
                }
                else
                {
                    //超期了
                    bookInformationRenew_model->setItem(line,5,new QStandardItem("不可续借"));
                    //更新borrow表 不可续借
                    vector<Undecide>borrowv;
                    Undecide te1,te2,te3,te4,te5,te6;
                    te1.num = all[i].first;
                    strcpy(te2.s,(all[i].second)[0].s);
                    strcpy(te3.s,(all[i].second)[1].s);

                    strcpy(te4.s,(all[i].second)[2].s);
                    te5.num = (all[i].second)[3].num;
                    te6.num = 0;
                    borrowv.push_back(te2);
                    borrowv.push_back(te3);
                    borrowv.push_back(te4);
                    borrowv.push_back(te5);
                    borrowv.push_back(te6);
                    Borrow.Update(all[i].first,borrowv);
                    Borrow.SaveHead();
                }
                line++;
            }
        }
    }
}

void MainWindow::on_returnButtonRenew_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(0);
}

void MainWindow::on_borrowRecordButton_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(4);
    //借书记录表
    //设置表头
    QStandardItemModel *bookInformationBorrowR_model = new QStandardItemModel();
    bookInformationBorrowR_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("图书编号")));
    bookInformationBorrowR_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationBorrowR_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    bookInformationBorrowR_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("借书日期")));
    bookInformationBorrowR_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("还书日期")));
    bookInformationBorrowR_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("扣费")));

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationBorrowR->setModel(bookInformationBorrowR_model);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->bookInformationBorrowR->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    //设置表格的各列的宽度值
    ui->bookInformationBorrowR->setColumnWidth(0,100);
    ui->bookInformationBorrowR->setColumnWidth(1,200);
    ui->bookInformationBorrowR->setColumnWidth(2,200);
    ui->bookInformationBorrowR->setColumnWidth(3,110);
    ui->bookInformationBorrowR->setColumnWidth(4,110);
    ui->bookInformationBorrowR->setColumnWidth(5,80);

    //设置选中时为整行选中
    ui->bookInformationBorrowR->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->bookInformationBorrowR->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置隔一行变一颜色，即：一灰一白
    ui->bookInformationBorrowR->setAlternatingRowColors(true);

    //设置只能选择一行，不能多行选中
    ui->bookInformationBorrowR->setSelectionMode(QAbstractItemView::SingleSelection);

    int line = 0;
    //从History中找出用户
    BPlusTree<int> History;
    History.SetTableName(string("History"));
    History.ReadHead();

    vector<pair< int,vector<Undecide> > > all;
    all = History.AllLeaf();
    const char *record_username_s = record_username.toStdString().data();//Qstring转const char*
    for(int i = 0; i < all.size(); i++){
        if((all[i].second)[1].s == record_username)
        {
            //(all[i].second)[0].s为图书编号
            char* bookNumber = const_cast<char*>((all[i].second)[0].s);//const char*转char*
            QString bookNumber_q = QString(QLatin1String(bookNumber));//char*转QString
            bookInformationBorrowR_model->setItem(line,0,new QStandardItem(bookNumber_q));
            //BookA里查isbn
            BPlusTree<string> BookA;
            BookA.SetTableName(string("BookA"));
            BookA.ReadHead();
            Return3 result1 = BookA.Search((all[i].second)[0].s,BookA.GetRootName());
            if(result1.Succ)
            {
                //result1.ve[4].s  isbn
                BPlusTree<string> BookB;
                BookB.SetTableName(string("BookB"));
                BookB.ReadHead();
                Return3 result2 = BookB.Search(result1.ve[4].s,BookB.GetRootName());
                //书名
                char* bookName = const_cast<char*>(result2.ve[0].s);//const char*转char*
                QString bookName_q = QString(QLatin1String(bookName));//char*转QString
                bookInformationBorrowR_model->setItem(line,1,new QStandardItem(bookName_q));
                //作者
                char* publishHousse = const_cast<char*>(result2.ve[2].s);//const char*转char*
                QString publishHousse_q = QString(QLatin1String(publishHousse));//char*转QString
                bookInformationBorrowR_model->setItem(line,2,new QStandardItem(publishHousse_q));
            }
            //借阅时间
            char* borrowTime = const_cast<char*>((all[i].second)[2].s);//const char*转char*
            QString borrowTime_q = QString(QLatin1String(borrowTime));//char*转QString
            bookInformationBorrowR_model->setItem(line,3,new QStandardItem(borrowTime_q));

            //还书时间
            char* returnTime = const_cast<char*>((all[i].second)[3].s);//const char*转char*
            QString returnTime_q = QString(QLatin1String(returnTime));//char*转QString
            bookInformationBorrowR_model->setItem(line,4,new QStandardItem(returnTime_q));

            //扣费
            QString deduction = QString::number((all[i].second)[4].dou,10,2);
            bookInformationBorrowR_model->setItem(line,5,new QStandardItem(deduction));
            line++;
        }
    }




}

void MainWindow::on_returnBottonBorrowR_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(0);
}

void MainWindow::on_moneyBotton_clicked()
{
    ui->stackedWidgetPermary->setCurrentIndex(5);
    //欠费记录表
    //设置表头
    QStandardItemModel *inDebtInformation_model = new QStandardItemModel();
    inDebtInformation_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("图书编号")));
    inDebtInformation_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    inDebtInformation_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    inDebtInformation_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("借书日期")));
    inDebtInformation_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("还书日期")));
    inDebtInformation_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("超期罚款")));
    inDebtInformation_model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("总欠款")));

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



    //缴费记录表
    //设置表头
    QStandardItemModel *paymentInformation_model = new QStandardItemModel();
    paymentInformation_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("缴费时间")));
    paymentInformation_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("缴费金额")));
    paymentInformation_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("状态")));
    paymentInformation_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("总欠款")));//成功 失败


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

    int line1 = 0,line2 = 0;
    //从History中找出用户
    BPlusTree<int> History;
    History.SetTableName(string("History"));
    History.ReadHead();

    vector<pair< int,vector<Undecide> > > all;
    all = History.AllLeaf();
    const char *record_username_s = record_username.toStdString().data();//Qstring转const char*
    //表1
    for(int i = 0; i < all.size(); i++)
    {
        if((all[i].second)[1].s == record_username)
        {
            //(all[i].second)[0].s为图书编号
            char* bookNumber = const_cast<char*>((all[i].second)[0].s);//const char*转char*
            QString bookNumber_q = QString(QLatin1String(bookNumber));//char*转QString
            inDebtInformation_model->setItem(line1,0,new QStandardItem(bookNumber_q));
            //BookA里查isbn
            BPlusTree<string> BookA;
            BookA.SetTableName(string("BookA"));
            BookA.ReadHead();
            Return3 result1 = BookA.Search((all[i].second)[0].s,BookA.GetRootName());
            if(result1.Succ)
            {
                //result1.ve[4].s  isbn
                BPlusTree<string> BookB;
                BookB.SetTableName(string("BookB"));
                BookB.ReadHead();
                Return3 result2 = BookB.Search(result1.ve[4].s,BookB.GetRootName());
                //书名
                char* bookName = const_cast<char*>(result2.ve[0].s);//const char*转char*
                QString bookName_q = QString(QLatin1String(bookName));//char*转QString
                inDebtInformation_model->setItem(line1,1,new QStandardItem(bookName_q));
                //作者
                char* publishHousse = const_cast<char*>(result2.ve[2].s);//const char*转char*
                QString publishHousse_q = QString(QLatin1String(publishHousse));//char*转QString
                inDebtInformation_model->setItem(line1,2,new QStandardItem(publishHousse_q));
            }
            //借阅时间
            char* borrowTime = const_cast<char*>((all[i].second)[2].s);//const char*转char*
            QString borrowTime_q = QString(QLatin1String(borrowTime));//char*转QString
            inDebtInformation_model->setItem(line1,3,new QStandardItem(borrowTime_q));

            //还书时间
            char* returnTime = const_cast<char*>((all[i].second)[3].s);//const char*转char*
            QString returnTime_q = QString(QLatin1String(returnTime));//char*转QString
            inDebtInformation_model->setItem(line1,4,new QStandardItem(returnTime_q));

            //超期罚款
            QString deduction = QString::number((all[i].second)[4].dou,10,2);
            inDebtInformation_model->setItem(line1,5,new QStandardItem(deduction));

            //总欠费
            BPlusTree<string> User;
            User.SetTableName(string("User"));
            User.ReadHead();
            Return3 result3 = User.Search(record_username_s,User.GetRootName());
            if(result3.Succ)
            {
                QString arrears_q = QString::number(result3.ve[2].dou, 10,2);
                inDebtInformation_model->setItem(line1,6,new QStandardItem(arrears_q));
            }
            line1++;
        }
    }
    //表2
    BPlusTree<int> Money;
    Money.SetTableName(string("Money"));
    Money.ReadHead();
    vector<pair< int,vector<Undecide> > > alls;
    alls = Money.AllLeaf();
    for(int i = 0; i < alls.size(); i++)
    {
        if((alls[i].second)[0].s == record_username)
        {
            //缴费时间
            char* payTime = const_cast<char*>((alls[i].second)[1].s);//const char*转char*
            QString payTime_q = QString(QLatin1String(payTime));//char*转QString
            paymentInformation_model->setItem(line2,1,new QStandardItem(payTime_q));

            //缴费金额
            //char* payMoney = const_cast<char*>((alls[i].second)[2].dou);//const char*转char*
            QString payMoney_q = QString::number((alls[i].second)[2].dou,10,2);//char*转QString
            paymentInformation_model->setItem(line2,2,new QStandardItem(payMoney_q));

            //状态
            if(((alls[i].second)[3].num) == 1)
            {
                paymentInformation_model->setItem(line2,3,new QStandardItem("成功"));
            }
            else
            {
                paymentInformation_model->setItem(line2,3,new QStandardItem("失败"));
            }
            //缴费后总欠费
            QString laterArrears = QString::number((alls[i].second)[4].dou, 10,2);
            paymentInformation_model->setItem(line2,4,new QStandardItem(laterArrears));
            line2++;
        }
    }




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

                            if((all[i].second)[2].num == 0)
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
        if(result1.ve[2].num == 0)
        {
            vector<pair< int,vector<Undecide> > > all;
            all = Borrow.AllLeaf();
            int k = all.size();
            //导入信息到borrow表
            vector<Undecide>borrowv;
            Undecide te1,te2,te3,te4,te5,te6,te7;
            te1.num = k;
            strcpy(te2.s,data_s);//书的编号
            const char *record_username_s = record_username.toStdString().data();
            strcpy(te3.s,record_username_s);//借书人
            QDateTime current_date_time = QDateTime::currentDateTime();
            QString current_date = current_date_time.toString("yyyy/MM/dd");
            const char *current_date_s = current_date.toStdString().data();
            strcpy(te4.s,current_date_s);//借书时间*/

            //最后还书日期
            QDateTime lastTime = current_date_time.addDays(30);
            QString lastTime_q = lastTime.toString("yyyy/MM/dd");
            const char *lastTime_qs = lastTime_q.toStdString().data();
            strcpy(te5.s,lastTime_qs);

            te6.num = 0;
            te7.num = 1;

            borrowv.push_back(te2);
            borrowv.push_back(te3);
            borrowv.push_back(te4);
            borrowv.push_back(te5);
            borrowv.push_back(te6);
            borrowv.push_back(te7);
            Borrow.Insert(k,borrowv);
            Borrow.SaveHead();//一定要记得保存！


            QMessageBox::information(this, "提示", "借书成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

            vector<Undecide>bookav;//将BookA中的是否可借的值改为false,更新最新借阅时间、人
            Undecide te8,te9,te10,te11,te12,te13;
            strcpy(te8.s,data_s);
            strcpy(te9.s,record_username_s);
            strcpy(te10.s,current_date_s);
            te11.num = 1;
            te12.num = result1.ve[3].num;
            strcpy(te13.s,result1.ve[4].s);
            bookav.push_back(te9);
            bookav.push_back(te10);
            bookav.push_back(te11);
            bookav.push_back(te12);
            bookav.push_back(te13);
            BookA.Update(data_s,bookav);
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
    //书籍编号 书名 出版社 作者 最后还书时间 是否超期
    int row = ui->bookInformationRepay->currentIndex().row();//选中行的行号
    //获取书的编号
    QAbstractItemModel *model = ui->bookInformationRepay->model();
    QModelIndex index = model->index(row,0);//选中行第一列的内容
    QVariant bookNumber = model->data(index);
    const char *bookNumber_s = bookNumber.toString().toStdString().data();//先转Qstring再转const char*
    const char *record_username_s = record_username.toStdString().data();

    //更改BookA中是否被借阅的bool值
    BPlusTree<string> BookA;
    BookA.SetTableName(string("BookA"));
    BookA.ReadHead();  //读取文件

    Return3 result1 = BookA.Search(bookNumber_s,BookA.GetRootName());
    if(result1.Succ)
    {
        //更新bool值
        vector<Undecide>Bookav;
        Undecide te7,te8,te9,te10,te11,te12;
        strcpy(te7.s,bookNumber_s);
        strcpy(te8.s,result1.ve[0].s);
        strcpy(te9.s,result1.ve[1].s);
        te10.num = 0;
        te11.num = result1.ve[3].num;
        strcpy(te12.s,result1.ve[4].s);
        Bookav.push_back(te8);
        Bookav.push_back(te9);
        Bookav.push_back(te10);
        Bookav.push_back(te11);
        Bookav.push_back(te12);
        BookA.Update(bookNumber_s,Bookav);
        BookA.SaveHead();

        BPlusTree<int> History;
        History.SetTableName(string("History"));
        History.ReadHead();  //读取文件

        vector<Undecide>historyv;
        Undecide te1,te2,te3,te4,te5,te6;

        vector<pair< int,vector<Undecide> > > all;
        all = History.AllLeaf();
        int k = all.size();
        Return3 result2 = BookA.Search(bookNumber_s,BookA.GetRootName());
        if(result2.Succ)
        {
            if(result2.ve[2].num == 0)
            {
                //更新到History表
                te1.num = k;
                strcpy(te2.s,bookNumber_s);
                //用户名
                const char *record_username_s = record_username.toStdString().data();
                strcpy(te3.s,record_username_s);

                //根据用户名和图书编号在borrow中查找
                BPlusTree<int> Borrow;
                Borrow.SetTableName(string("Borrow"));;
                Borrow.ReadHead();  //读取文件

                vector<pair< int,vector<Undecide> > > all;
                all = Borrow.AllLeaf();
                const char *lastTime_s;
                for(int i = 0; i < all.size(); i++)
                {
                    if(((all[i].second)[0].s == bookNumber) && ((all[i].second)[1].s == record_username) && ((all[i].second)[4].num == 0))
                    {
                        strcpy(te4.s,(all[i].second)[2].s);
                        lastTime_s = (all[i].second)[3].s;
                    }
                    break;
                }
                //还书日期获取当前时间
                QDateTime current_date_time = QDateTime::currentDateTime();
                QString current_date = current_date_time.toString("yyyy/MM/dd");
                const char *current_date_s = current_date.toStdString().data();
                strcpy(te5.s,current_date_s);

                //根据天数计算钱
//                QModelIndex index = model->index(row,4);//选中行第4列的内容（最后还书日期）
//                QVariant lastTime = model->data(index);
//                const char *lastTime_s = lastTime.toString().toStdString().data();//先转Qstring再转const char*
                char* lastTime_sc = const_cast<char*>(lastTime_s);//const char*转char*
                QString lastTime_scq = QString(QLatin1String(lastTime_sc));//char*转QString
                QDateTime lastTime_scqq = QDateTime::fromString(lastTime_scq, "yyyy/MM/dd");//借书时间QString转化为QDateTime
                int days = lastTime_scqq.daysTo(current_date_time);
                if(days <= 0)
                {
                    te6.dou = 0;
                }
                else
                {
                    te6.dou = days * 0.2;
                }
                historyv.push_back(te2);
                historyv.push_back(te3);
                historyv.push_back(te4);
                historyv.push_back(te5);
                historyv.push_back(te6);
                History.Insert(k,historyv);
                History.SaveHead();//一定要记得保存！

                //更新borrow表
                //vector<pair< int,vector<Undecide> > > all;
                all = Borrow.AllLeaf();
                for(int i = 0; i < all.size(); i++){
                    cout << (all[i].second)[0].s << " " << bookNumber_s<<" "<< (all[i].second)[1].s<<" " << record_username_s;
                    if(((all[i].second)[0].s == bookNumber) && ((all[i].second)[1].s == record_username))
                    {
                        vector<Undecide>borrowv;
                        Undecide te13,te14,te15,te16,te17,te18,te19;
                        te13.num = all[i].first;
                        strcpy(te14.s,(all[i].second)[0].s);
                        strcpy(te15.s,(all[i].second)[1].s);
                        strcpy(te16.s,(all[i].second)[2].s);
                        strcpy(te17.s,(all[i].second)[3].s);
                        te18.num = 1;
                        te19.num = 0;
                        borrowv.push_back(te14);
                        borrowv.push_back(te15);
                        borrowv.push_back(te16);
                        borrowv.push_back(te17);
                        borrowv.push_back(te18);
                        borrowv.push_back(te19);
                        Borrow.Update(all[i].first,borrowv);
                        Borrow.SaveHead();

                    }
                }

                QMessageBox::information(this, "提示", "还书成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else
                QMessageBox::information(this, "提示", "还书失败！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }
    }
}

void MainWindow::on_affirmBottonRenew_clicked()
{
        BPlusTree<int> Borrow;
        Borrow.SetTableName(string("Borrow"));
        Borrow.ReadHead();

        int row = ui->bookInformationRenew->currentIndex().row();//选中行的行号
        QAbstractItemModel *model = ui->bookInformationRenew->model();
        QModelIndex index = model->index(row,0);//选中行第一列的内容
        QVariant bookNumber = model->data(index);
        const char *bookNumber_s = bookNumber.toString().toStdString().data();//先转Qstring再转const char*
        const char *record_username_s = record_username.toStdString().data();
        cout << "**" << bookNumber_s << "**"<<"??" << record_username_s<<"??";
        vector<pair< int,vector<Undecide> > > all;
        all = Borrow.AllLeaf();
        for(int i = 0; i < all.size(); i++){
                //cout << (all[i].second)[0].s << bookNumber_s << (all[i].second)[1].s << record_username_s;
            if(((all[i].second)[0].s == bookNumber) && ((all[i].second)[1].s == record_username))
            {
                if((all[i].second)[4].num == 1)
                {
                    vector<Undecide>borrowv;
                    Undecide te1,te2,te3,te4,te5,te6;
                    te1.num = all[i].first;
                    strcpy(te2.s,(all[i].second)[0].s);
                    strcpy(te3.s,(all[i].second)[1].s);
                    QDateTime lastTime_qq = lastTime_qq.addDays(30);
                    QString lastTime_q = lastTime_qq.toString("yyyy/MM/dd");
                    const char *lastTime_s = lastTime_q.toStdString().data();//Qstring转const char*
                    //将borrow中的最后还书日期改为上一个最后还书日期+30
                    strcpy(te4.s,lastTime_s);
                    te5.num = (all[i].second)[3].num;
                    te6.num = (all[i].second)[4].num;
                    borrowv.push_back(te2);
                    borrowv.push_back(te3);
                    borrowv.push_back(te4);
                    borrowv.push_back(te5);
                    borrowv.push_back(te6);
                    Borrow.Update(all[i].first,borrowv);
                    Borrow.SaveHead();
                    QMessageBox::information(this, "提示", "续借成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                }
                else
                {
                    QMessageBox::information(this, "提示", "该书不可续借！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                }
           }

        }
}



void MainWindow::on_affirmButtonMoney_clicked()
{
    QString password_input;
    password_input = ui->passwordMoneyInput->text();
    std::string md5_password;
    QByteArray bb;
    const char *password_s = password_input.toStdString().data();
    bb = QCryptographicHash::hash (password_input.toLatin1(), QCryptographicHash::Md5 );
    md5_password.append(bb.toHex());

    BPlusTree<string> User;
    User.SetTableName(string("User"));;
    User.ReadHead();  //读取文件

    const char *record_username_s = record_username.toStdString().data();
    string record_username_st = record_username.toStdString();
    Return3 result1 = User.Search(record_username_st,User.GetRootName());
    if(result1.Succ)
    {
        if(md5_password == result1.ve[0].s)
        {
            BPlusTree<int> Money;
            Money.SetTableName(string("Money"));;
            Money.ReadHead();

            double totalArrears = result1.ve[2].dou;
            if(result1.ve[2].dou == 0)
                QMessageBox::information(this, "提示", "该用户无欠费！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            else
            {
                //密码正确，更新user表
                vector<Undecide>userv;
                Undecide te1, te2, te3, te4,te5;
                strcpy(te1.s,record_username_s);
                strcpy(te2.s,result1.ve[0].s);
                strcpy(te3.s,result1.ve[1].s);
                te4.dou = 0;
                te5.num = result1.ve[3].num;
                userv.push_back(te2);
                userv.push_back(te3);
                userv.push_back(te4);
                userv.push_back(te5);
                User.Update(record_username_st,userv);
                User.SaveHead();//一定要记得保存！

                vector<pair< int,vector<Undecide> > > all;
                all = Money.AllLeaf();
                int k = all.size();
                if(result1.ve[2].dou == 0)
                {
                    QMessageBox::information(this, "提示", "缴费成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                    //写入Money表

                    vector<Undecide>moneyv;
                    Undecide te6,te7,te8,te9,te10,te11;
                    te6.num = money_key;

                    strcpy(te7.s,record_username_s);

                    QDateTime current_date_time = QDateTime::currentDateTime();
                    QString current_date = current_date_time.toString("yyyy/MM/dd");
                    const char *current_date_s = current_date.toStdString().data();
                    strcpy(te8.s,current_date_s);

                    te9.dou = totalArrears;
                    //状态
                    te10.num = 1;
                    te11.dou = 0;
                    moneyv.push_back(te7);
                    moneyv.push_back(te8);
                    moneyv.push_back(te9);
                    moneyv.push_back(te10);
                    moneyv.push_back(te11);
                    Money.Insert(k,moneyv);
                    Money.SaveHead();//一定要记得保存！
                }
            }
        }

        else
        {
            QMessageBox::critical(this, "critical", "密码错误!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }

    }
}
