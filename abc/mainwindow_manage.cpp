#include "mainwindow_manage.h"
#include "ui_mainwindow_manage.h"
#include "b_plus_tree.h"
#include <QMessageBox>
#include <global_variable.h>
#include <QTableView>
#include <register.h>
#include <qstring.h>
#include<iostream>
#include <QStandardItemModel> //用于存储定制数据的通用模型

QStandardItemModel *bookInformationDelate;

MainWindow_Manage::MainWindow_Manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Manage)
{
    ui->setupUi(this);
    if(manage_jurisdiction == 2){
        ui->btn_SignupManager->setEnabled(false);
    }
    ui->stackedWidgetManage->setCurrentIndex(0);//首页界面

    //删除信息表
    //设置表头
    QStandardItemModel *bookInformationDelate_model = new QStandardItemModel();
    bookInformationDelate_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("书籍编号")));
    bookInformationDelate_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationDelate_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    bookInformationDelate_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版日期")));
    bookInformationDelate_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("价格")));
    bookInformationDelate_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("状态")));//已借，可借

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationDelate->setModel(bookInformationDelate_model);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    //设置表格的各列的宽度值
    ui->bookInformationDelate->setColumnWidth(0,100);
    ui->bookInformationDelate->setColumnWidth(1,210);
    ui->bookInformationDelate->setColumnWidth(2,210);
    ui->bookInformationDelate->setColumnWidth(3,110);
    ui->bookInformationDelate->setColumnWidth(4,80);
    ui->bookInformationDelate->setColumnWidth(5,80);

    //设置选中时为整行选中
    ui->bookInformationDelate->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑（用户不能编辑，管理员可以）
    ui->bookInformationDelate->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置隔一行变一颜色，即：一灰一白
    ui->bookInformationDelate->setAlternatingRowColors(true);

    //设置只能选择一行，不能多行选中
    ui->bookInformationDelate->setSelectionMode(QAbstractItemView::SingleSelection);

    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->bookInformationDelate->setContextMenuPolicy(Qt::CustomContextMenu);

    //更新信息信息表
    //设置表头
    QStandardItemModel *bookInformationUpdate_model = new QStandardItemModel();
    bookInformationUpdate_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("图书索引值")));
    bookInformationUpdate_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationUpdate_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("出版社")));
    bookInformationUpdate_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版日期")));
    bookInformationUpdate_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("价格")));
    bookInformationUpdate_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("数量")));
    bookInformationUpdate_model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("状态")));//已借，可借

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationUpdate->setModel(bookInformationUpdate_model);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->bookInformationUpdate->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->bookInformationUpdate->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->bookInformationUpdate->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->bookInformationUpdate->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->bookInformationUpdate->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->bookInformationUpdate->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->bookInformationUpdate->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);
    //设置表格的各列的宽度值
    ui->bookInformationUpdate->setColumnWidth(0,100);
    ui->bookInformationUpdate->setColumnWidth(1,200);
    ui->bookInformationUpdate->setColumnWidth(2,190);
    ui->bookInformationUpdate->setColumnWidth(3,110);
    ui->bookInformationUpdate->setColumnWidth(4,80);
    ui->bookInformationUpdate->setColumnWidth(5,80);
    ui->bookInformationUpdate->setColumnWidth(6,80);

    //设置选中时为整行选中
    ui->bookInformationUpdate->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑（用户不能编辑，管理员可以）
    ui->bookInformationUpdate->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置隔一行变一颜色，即：一灰一白
    ui->bookInformationUpdate->setAlternatingRowColors(true);

    //设置只能选择一行，不能多行选中
    ui->bookInformationUpdate->setSelectionMode(QAbstractItemView::SingleSelection);

    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->bookInformationUpdate->setContextMenuPolicy(Qt::CustomContextMenu);


    //借书记录表
    //设置表头
    QStandardItemModel *bookInformationBRManage_model = new QStandardItemModel();
    bookInformationBRManage_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("书籍编号")));
    bookInformationBRManage_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("用户名")));
    bookInformationBRManage_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("书名")));
    bookInformationBRManage_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("借/续书日期")));
    bookInformationBRManage_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("最后还书日期")));
    bookInformationBRManage_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("状态")));//借，续
    bookInformationBRManage_model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("扣费")));

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationBRManage->setModel(bookInformationBRManage_model);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->bookInformationBRManage->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->bookInformationBRManage->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->bookInformationBRManage->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->bookInformationBRManage->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->bookInformationBRManage->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->bookInformationBRManage->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->bookInformationBRManage->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);
    //设置表格的各列的宽度值
    ui->bookInformationBRManage->setColumnWidth(0,90);
    ui->bookInformationBRManage->setColumnWidth(1,170);
    ui->bookInformationBRManage->setColumnWidth(2,180);
    ui->bookInformationBRManage->setColumnWidth(3,100);
    ui->bookInformationBRManage->setColumnWidth(4,100);
    ui->bookInformationBRManage->setColumnWidth(5,80);
    ui->bookInformationBRManage->setColumnWidth(6,80);

    //设置选中时为整行选中
    ui->bookInformationBRManage->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->bookInformationBRManage->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置隔一行变一颜色，即：一灰一白
    ui->bookInformationBRManage->setAlternatingRowColors(true);

    //设置只能选择一行，不能多行选中
    ui->bookInformationBRManage->setSelectionMode(QAbstractItemView::SingleSelection);

    //如果你用在QTableView中使用右键菜单，需启用该属性
    ui->bookInformationBRManage->setContextMenuPolicy(Qt::CustomContextMenu);

}

MainWindow_Manage::~MainWindow_Manage()
{
    delete ui;
}




void MainWindow_Manage::on_addButton_clicked()
{
    ui->stackedWidgetManage->setCurrentIndex(1);
}

void MainWindow_Manage::on_returnButtonAdd_clicked()
{
    ui->stackedWidgetManage->setCurrentIndex(0);
}

void MainWindow_Manage::on_deleteButton_clicked()
{
    ui->stackedWidgetManage->setCurrentIndex(2);
}

void MainWindow_Manage::on_returnButtonDelate_clicked()
{
    ui->stackedWidgetManage->setCurrentIndex(0);
}

void MainWindow_Manage::on_updateButton_clicked()
{
    ui->stackedWidgetManage->setCurrentIndex(3);
}

void MainWindow_Manage::on_returnButtonUpdate_clicked()
{
    ui->stackedWidgetManage->setCurrentIndex(0);
}

void MainWindow_Manage::on_borrowRecordButtonManage_clicked()
{
    ui->stackedWidgetManage->setCurrentIndex(4);
}

void MainWindow_Manage::on_returnBottonBRManage_clicked()
{
    ui->stackedWidgetManage->setCurrentIndex(0);
}

void MainWindow_Manage::on_btn_SignupManager_clicked()
{
    //点击管理员注册按钮
    register_location = 2;
    Register *reg = new Register();//说明reg指针指向了副窗口，其中Register类在register中定义
    this->hide();//隐藏父窗口，this指针指向父窗口
    reg->show();

}

void MainWindow_Manage::on_affirmBottonAdd_clicked()
{
    //添加图书
    QString bookISBN, bookName, bookAuthur, bookPublish, publishTime, bookPrice, bookNumber;
    int countN = 0;  //用来遍历BookA时候计算数量

    bookISBN = ui->add_ISBN->text();
    bookName = ui->add_bookName->text();
    bookAuthur = ui->add_author->text();
    bookPublish = ui->add_publish->text();
    publishTime = ui->add_publishTime->text();
    bookPrice = ui->add_price->text();
    bookNumber = ui->add_amount->text();
    //相关类型转换
    const char *bookISBN_s = bookISBN.toStdString().data();
    const char *bookName_s = bookName.toStdString().data();
    const char *bookAuthur_s = bookAuthur.toStdString().data();
    const char *bookPublish_s = bookPublish.toStdString().data();
    const char *publishTime_s = publishTime.toStdString().data();
    const char *bookPrice_s = bookPrice.toStdString().data();
    const char *bookNumber_s = bookNumber.toStdString().data();   //批量添加先不设定
    string bookISBN_fin = bookISBN.toStdString();
//    const char *publicTime_s = publicTime.toStdString().data();
//    std::cout<<publicTime_s;
    if(bookISBN != "" && bookName != "" && bookAuthur != "" && bookPublish != "" & publishTime != "" && bookPrice != "" && bookNumber !="")
    {
        //判断输入正确
        //先到BookB表去查找是否存在这本书（利用ISBN作为key去查找） 这还有一种是ISBN被删除的情况，后面再添加
        BPlusTree<string> BookB;
        BookB.SetTableName(string("BookB"));
        BookB.ReadHead();
        Return3 result1 = BookB.Search(bookISBN_fin, BookB.GetRootName());

        if(result1.Succ)
        {
            cout<<result1.Succ;
            //如果找到，再到BookA表去遍历对应的本书，获得应该的数量编号
            BPlusTree<string> BookA;
            BookA.SetTableName(string("BookA"));
            BookA.ReadHead();
            vector<pair< string,vector<Undecide> > > all;
            all = BookA.AllLeaf();
            cout<<all.size();
            for(int i = 0; i < all.size(); i++)
            {
                if( (all[i].second)[5].s == bookISBN_s )
                {
                    countN = countN + 1;
                }
            }
            //设定插入的编码
            //将countN转化为string类型
            stringstream ss;
            string str;
            string add;
            ss<<countN;
            ss>>str;
            int len = str.length();
            switch(len)
            {
                case 1: add = "00";
                        add.append(str);
                        bookISBN_fin.append(add);
                        break;
                case 2: add = "0";
                        add.append(str);
                        bookISBN_fin.append(add);
                        break;
                case 3: bookISBN_fin.append(str);
                        break;
                default:
                        cout<<"no one book has been found";
                        break;
            }

            if(len)
            {
                //在BookA找到的情况，包括标记为删除的部分
                //类型转换(string->const char*)
                const char *ISBNThree = bookISBN_fin.data();
                vector<Undecide>bookav;
                Undecide te1, te2, te3, te4, te5, te6;
                strcpy(te1.s, ISBNThree);
                strcpy(te2.s, "none");   //初始化用户存储为"none"
                strcpy(te3.s, "none");   //初始化时间为"none"
                te4.is = 0;            //是否被续借初始为0
                te5.is = 0;            //是否被标记为删除初始为0
                strcpy(te6.s, bookISBN_s);
                bookav.push_back(te1);
                bookav.push_back(te2);
                bookav.push_back(te3);
                bookav.push_back(te4);
                bookav.push_back(te5);
                bookav.push_back(te6);
                BookA.Insert(bookISBN_fin, bookav);
                BookA.SaveHead();  //保存信息
                QMessageBox::information(this, "提示", "添加成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else
            {
                //如果在BookA没有找到的情况(在BookB中是存在的)
                bookISBN_fin.append("001");  //创建为BookA的第一本
                const char *ISBNThree = bookISBN_fin.data(); //转换类型
                vector<Undecide>bookav;
                Undecide te1, te2, te3, te4, te5, te6;
                strcpy(te1.s, ISBNThree);    //这里实际上是ISBN+三位
                strcpy(te2.s, NULL);   //初始化用户存储为NULL
                strcpy(te3.s, NULL);   //初始化时间为NULL
                te4.is = 0;            //是否被续借初始为0
                te5.is = 0;            //是否被标记为删除初始为0
                strcpy(te6.s, bookISBN_s);
                bookav.push_back(te1);
                bookav.push_back(te2);
                bookav.push_back(te3);
                bookav.push_back(te4);
                bookav.push_back(te5);
                bookav.push_back(te6);
                BookA.Insert(bookISBN_fin, bookav);
                BookA.SaveHead();  //保存信息
                QMessageBox::information(this, "提示", "添加成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }


        }
        else
        {
            //如果在BookB里面没有找到
            //先将书添加到BookB表中
            vector<Undecide> bookbv;
            Undecide t1, t2, t3, t4, t5, t6;
            strcpy(t1.s, bookISBN_s);
            strcpy(t2.s, bookName_s);
            strcpy(t3.s, bookAuthur_s);
            strcpy(t4.s, bookPublish_s);
            strcpy(t5.s, publishTime_s);
            strcpy(t6.s, bookPrice_s);
            bookbv.push_back(t1);
            bookbv.push_back(t2);
            bookbv.push_back(t3);
            bookbv.push_back(t4);
            bookbv.push_back(t5);
            bookbv.push_back(t6);
            BookB.Insert(bookISBN_fin, bookbv);
            BookB.SaveHead();  //保存信息

            //再将书添加到BookA中
            BPlusTree<string> BookA;
            BookA.SetTableName(string("BookA"));
            BookA.ReadHead();
            bookISBN_fin.append("001");  //创建为BookA的第一本
            cout<<"test1##############";

            const char *ISBNThree = bookISBN_fin.data(); //转换类型
            vector<Undecide>bookav;
            Undecide te1, te2, te3, te4, te5, te6;
            strcpy(te1.s, ISBNThree);    //这里实际上是ISBN+三位
            strcpy(te2.s, "none");   //初始化用户存储为"none"
            strcpy(te3.s, "none");   //初始化时间为"none"
            te4.is = 0;            //是否被续借初始为0
            te5.is = 0;            //是否被标记为删除初始为0
            strcpy(te6.s, bookISBN_s);
            bookav.push_back(te1);
            bookav.push_back(te2);
            bookav.push_back(te3);
            bookav.push_back(te4);
            bookav.push_back(te5);
            bookav.push_back(te6);
            BookA.Insert(bookISBN_fin, bookav);
            BookA.SaveHead();  //保存信息
            QMessageBox::information(this, "提示", "添加成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }



    }
    else
    {
        //判断输入有误
        QMessageBox::critical(this, "critical", "请输入完整信息!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}

void MainWindow_Manage::on_affirmBottonDelate_clicked()
{
    //管理员删除图书
    //在搜索框中输入书名
    //QStandardItemModel* model = new QStandardItemModel();

    //读取BookA表
//    BPlusTree<string> BookA;
//    BookA.SetTableName(string("BookA"));
//    BookA.ReadHead();
//    vector<pair< string,vector<Undecide> > > allA;
//    allA = BookA.AllLeaf();
//    //读取BookB表
//    BPlusTree<string> BookB;
//    BookB.SetTableName(string("BookB"));
//    BookB.ReadHead();

//    for(int i=0; i<allA.size(); i++)
//    {
//        char* bookNumber = const_cast<char*>((allA[i].second)[0].s);//const char*转char*
//        QString bookNumber_q = QString(QLatin1String(bookNumber));//char*转QString
//        bookInformationDelate->setItem(i,0,new QStandardItem(QString::fromLocal8Bit(bookNumber_q)));
//        bookInformationDelate->setItem(i,1,new QStandardItem(QString::fromLocal8Bit(bookNumber_q)));
//        bookInformationDelate->setItem(i,2,new QStandardItem(QString::fromLocal8Bit(bookNumber_q)));
//        bookInformationDelate->setItem(i,3,new QStandardItem(QString::fromLocal8Bit(bookNumber_q)));
//        bookInformationDelate->setItem(i,4,new QStandardItem(QString::fromLocal8Bit(bookNumber_q)));
//        bookInformationDelate->setItem(i,5,new QStandardItem(QString::fromLocal8Bit(bookNumber_q)));
//    }






}
