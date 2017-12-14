#include "mainwindow_manage.h"
#include "ui_mainwindow_manage.h"
#include "b_plus_tree.h"
#include "systemmanage.h"
#include <QMessageBox>
#include <global_variable.h>
#include <QTableView>
#include <register.h>
#include <qstring.h>
#include<iostream>
#include <QStandardItemModel> //用于存储定制数据的通用模型


MainWindow_Manage::MainWindow_Manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Manage)
{
    ui->setupUi(this);
    if(manage_jurisdiction == 2){
        ui->btn_SignupManager->setEnabled(false);
        ui->btn_SignupManager->hide();
        ui->btn_manageSystem->setEnabled(false);
        ui->btn_manageSystem->hide();
    }
    if(manage_jurisdiction == 1){
        ui->btn_SignupManager->setEnabled(true);
        ui->btn_manageSystem->setEnabled(true);
    }
    ui->stackedWidgetManage->setCurrentIndex(0);//首页界面






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
    //删除信息表初始化
    //设置表头
    QStandardItemModel *bookInformationDelete_model = new QStandardItemModel();
    bookInformationDelete_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("书籍编号")));
    bookInformationDelete_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationDelete_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("作者")));
    bookInformationDelete_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版社")));
    bookInformationDelete_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("出版日期")));
    bookInformationDelete_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("价格")));
    bookInformationDelete_model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("借阅状态")));//已借，可借

    //利用setModel()方法将数据模型与QTableView绑定
    ui->bookInformationDelate->setModel(bookInformationDelete_model);

    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->bookInformationDelate->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);
    //设置表格的各列的宽度值
    ui->bookInformationDelate->setColumnWidth(0,140);
    ui->bookInformationDelate->setColumnWidth(1,140);
    ui->bookInformationDelate->setColumnWidth(2,130);
    ui->bookInformationDelate->setColumnWidth(3,140);
    ui->bookInformationDelate->setColumnWidth(4,110);
    ui->bookInformationDelate->setColumnWidth(5,60);
    ui->bookInformationDelate->setColumnWidth(6,80);

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


    //管理员删除图书
    //在搜索框中输入书名

    //首先先显示目前的书目（测试）
    //读取BookA表
    BPlusTree<string> BookA;
    BookA.SetTableName(string("BookA"));
    BookA.ReadHead();
    vector<pair< string,vector<Undecide> > > allA;
    allA = BookA.AllLeaf();

    //读取BookB表
    BPlusTree<string> BookB;
    BookB.SetTableName(string("BookB"));
    BookB.ReadHead();

    int row = 0; //设置定位的插入行
    if(allA.size())
    {
        for(int i=0; i<allA.size(); i++)
        {
            //获取书本是否被删去的状态
            bool bookState = (allA[i].second)[3].is;

            //根据BookA中的ISBN去BookB找信息（这里还需要判断是否被删去的，删去的不显示）
            if(bookState == 0)
            {
                //获取书本编号
                QString bookNumber_q = QString::fromStdString(allA[i].first);
                bookInformationDelete_model->setItem(row, 0, new QStandardItem(bookNumber_q));

                //获取书本借阅时间（只有在借阅时才会有）
                int borrowState = (allA[i].second)[2].num;
                QString state;
                switch (borrowState) {
                    case 0:
                        state = "未借";
                        break;
                    case 1:
                        state = "正在借阅";
                        break;
                    case 2:
                        state = "续借中";
                        break;
                    default:
                        break;
                }
                bookInformationDelete_model->setItem(row, 6, new QStandardItem(state));

                //去BookB表查找
                const char *ISBN_s = (allA[i].second)[4].s; //const char*转为string
                string ISBN(ISBN_s);
                Return3 result1 = BookB.Search(ISBN, BookB.GetRootName());
                if(result1.Succ)
                {
                    //若在BookB中存在
                    //获取书名
                    char* bookName = const_cast<char*>(result1.ve[0].s);  //const char*转char*
                    //QString bookName_q = QString::fromUtf8(bookName.getData());  //中文编码
                    //QString bookNumber_q = QString(QLatin1String(bookNumber));   //char*转QString
                    bookInformationDelete_model->setItem(row, 1, new QStandardItem(bookName));

                    //获取作者名
                    char* bookAuthur = const_cast<char*>(result1.ve[1].s);
                    //QString bookAuthur_q = QString::fromUtf8(bookAuthur.getData());  //中文编码
                    bookInformationDelete_model->setItem(row, 2, new QStandardItem(bookAuthur));

                    //获取出版社
                    char* bookPublish = const_cast<char*>(result1.ve[2].s);
                    bookInformationDelete_model->setItem(row, 3, new QStandardItem(bookPublish));

                    //获取出版时间
                    char* publishTime = const_cast<char*>(result1.ve[3].s);
                    bookInformationDelete_model->setItem(row, 4, new QStandardItem(publishTime));

                    //获取书本价格
                    char* bookPrice = const_cast<char*>(result1.ve[4].s);
                    bookInformationDelete_model->setItem(row, 5, new QStandardItem(bookPrice));
                }

                row++;  //因为遍历的i和row不一样
            }

        }
    }

}

void MainWindow_Manage::on_returnButtonDelate_clicked()
{
    ui->stackedWidgetManage->setCurrentIndex(0);
}

void MainWindow_Manage::on_updateButton_clicked()
{
    //更改=新书本信息
    ui->stackedWidgetManage->setCurrentIndex(3);
    //更新信息信息表
    //设置表头
    QStandardItemModel *bookInformationUpdate_model = new QStandardItemModel();
    bookInformationUpdate_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("书籍编号")));
    bookInformationUpdate_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("书名")));
    bookInformationUpdate_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("作者")));
    bookInformationUpdate_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版社")));
    bookInformationUpdate_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("出版日期")));
    bookInformationUpdate_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("价格")));
    bookInformationUpdate_model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("借阅状态")));//已借，可借

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
    ui->bookInformationUpdate->setColumnWidth(0,140);
    ui->bookInformationUpdate->setColumnWidth(1,140);
    ui->bookInformationUpdate->setColumnWidth(2,130);
    ui->bookInformationUpdate->setColumnWidth(3,140);
    ui->bookInformationUpdate->setColumnWidth(4,110);
    ui->bookInformationUpdate->setColumnWidth(5,60);
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


    //首先先显示目前的书目（测试）
    //读取BookA表
    BPlusTree<string> BookA;
    BookA.SetTableName(string("BookA"));
    BookA.ReadHead();
    vector<pair< string,vector<Undecide> > > allA;
    allA = BookA.AllLeaf();

    //读取BookB表
    BPlusTree<string> BookB;
    BookB.SetTableName(string("BookB"));
    BookB.ReadHead();

    int row = 0; //设置定位的插入行
    if(allA.size())
    {
        for(int i=0; i<allA.size(); i++)
        {
            //获取书本是否被删去的状态
            bool bookState = (allA[i].second)[3].is;

            //根据BookA中的ISBN去BookB找信息（这里还需要判断是否被删去的，删去的不显示）
            if(bookState == 0)
            {
                //获取书本编号
                QString bookNumber_q = QString::fromStdString(allA[i].first);
                bookInformationUpdate_model->setItem(row, new QStandardItem(bookNumber_q));

                //获取书本借阅状态
                int borrowState = (allA[i].second)[2].num;
                QString state;
                switch (borrowState) {
                    case 0:
                        state = "未借";
                        break;
                    case 1:
                        state = "正在借阅";
                        break;
                    case 2:
                        state = "续借中";
                        break;
                    default:
                        break;
                }
                bookInformationUpdate_model->setItem(row, 6, new QStandardItem(state));

                //去BookB中查找相应信息
                const char *ISBN_s = (allA[i].second)[4].s; //const char*转为string
                string ISBN(ISBN_s);
                Return3 result1 = BookB.Search(ISBN, BookB.GetRootName());
                if(result1.Succ)
                {
                    //若在BookB中存在
                    //获取书名
                    char* bookName = const_cast<char*>(result1.ve[0].s);  //const char*转char*
                    //QString bookName_q = QString::fromUtf8(bookName.getData());  //中文编码
                    //QString bookNumber_q = QString(QLatin1String(bookNumber));   //char*转QString
                    bookInformationUpdate_model->setItem(row, 1, new QStandardItem(bookName));

                    //获取作者名
                    char* bookAuthur = const_cast<char*>(result1.ve[1].s);
                    //QString bookAuthur_q = QString::fromUtf8(bookAuthur.getData());  //中文编码
                    bookInformationUpdate_model->setItem(row, 2, new QStandardItem(bookAuthur));

                    //获取出版社
                    char* bookPublish = const_cast<char*>(result1.ve[2].s);
                    bookInformationUpdate_model->setItem(row, 3, new QStandardItem(bookPublish));

                    //获取出版时间
                    char* publishTime = const_cast<char*>(result1.ve[3].s);
                    bookInformationUpdate_model->setItem(row, 4, new QStandardItem(publishTime));

                    //获取书本价格
                    char* bookPrice = const_cast<char*>(result1.ve[4].s);
                    bookInformationUpdate_model->setItem(row, 5, new QStandardItem(bookPrice));
                }

                row++;  //增加row，放进表格行数
            }

        }
    }

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
                if( (all[i].second)[4].s == bookISBN_s )
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
                //const char *ISBNThree = bookISBN_fin.data();
                vector<Undecide>bookav;
                Undecide te1, te2, te3, te4, te5, te6;
                //strcpy(te1.s, ISBNThree);
                strcpy(te2.s, "none");   //初始化用户存储为"none"
                strcpy(te3.s, "none");   //初始化时间为"none"
                te4.num = 0;            //续借状态初始为0，即未被借
                te5.num = 0;            //是否被标记为删除初始为0
                strcpy(te6.s, bookISBN_s);
                //bookav.push_back(te1);
                bookav.push_back(te2);
                bookav.push_back(te3);
                bookav.push_back(te4);
                bookav.push_back(te5);
                bookav.push_back(te6);
                BookA.Insert(bookISBN_fin, bookav);
                BookA.SaveHead();  //保存信息
                QMessageBox::information(this, "提示", "添加成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

                ui->add_ISBN->setText("");
                ui->add_bookName->setText("");
                ui->add_author->setText("");
                ui->add_publish->setText("");
                ui->add_price->setText("");
                ui->add_amount->setText("");
            }
            else
            {
                //如果在BookA没有找到的情况(在BookB中是存在的)
                bookISBN_fin.append("000");  //创建为BookA的第一本
                //const char *ISBNThree = bookISBN_fin.data(); //转换类型
                vector<Undecide>bookav;
                Undecide te1, te2, te3, te4, te5, te6;
                //strcpy(te1.s, ISBNThree);    //这里实际上是ISBN+三位
                strcpy(te2.s, "none");   //初始化用户存储为NULL
                strcpy(te3.s, "none");   //初始化时间为NULL
                te4.num = 0;            //续借状态初始为0，即未被借
                te5.num = 0;            //是否被标记为删除初始为0
                strcpy(te6.s, bookISBN_s);
                //bookav.push_back(te1);
                bookav.push_back(te2);
                bookav.push_back(te3);
                bookav.push_back(te4);
                bookav.push_back(te5);
                bookav.push_back(te6);
                BookA.Insert(bookISBN_fin, bookav);
                BookA.SaveHead();  //保存信息
                QMessageBox::information(this, "提示", "添加成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

                ui->add_ISBN->setText("");
                ui->add_bookName->setText("");
                ui->add_author->setText("");
                ui->add_publish->setText("");
                ui->add_price->setText("");
                ui->add_amount->setText("");
            }


        }
        else
        {
            //如果在BookB里面没有找到
            //先将书添加到BookB表中
            vector<Undecide> bookbv;
            Undecide tt1, tt2, tt3, tt4, tt5, tt6;
            //strcpy(tt1.s, bookISBN_s);
            strcpy(tt2.s, bookName_s);
            strcpy(tt3.s, bookAuthur_s);
            strcpy(tt4.s, bookPublish_s); //???????????
            strcpy(tt5.s, publishTime_s);
            strcpy(tt6.s, bookPrice_s);
            //bookbv.push_back(t1);
            bookbv.push_back(tt2);
            bookbv.push_back(tt3);
            bookbv.push_back(tt4);
            bookbv.push_back(tt5);
            bookbv.push_back(tt6);
            BookB.Insert(bookISBN_fin, bookbv);
            BookB.SaveHead();  //保存信息

            //再将书添加到BookA中
            BPlusTree<string> BookA;
            BookA.SetTableName(string("BookA"));
            BookA.ReadHead();
            bookISBN_fin.append("001");  //创建为BookA的第一本
            cout<<"test1##############";

            //const char *ISBNThree = bookISBN_fin.data(); //转换类型
            vector<Undecide>bookav;
            Undecide te1, te2, te3, te4, te5, te6;
            //strcpy(te1.s, ISBNThree);    //这里实际上是ISBN+三位
            strcpy(te2.s, "none");   //初始化用户存储为"none"
            strcpy(te3.s, "none");   //初始化时间为"none"
            te4.num = 0;            //借阅状态初始为未借为0
            te5.num = 0;            //是否被标记为删除初始为0
            strcpy(te6.s, bookISBN_s);
            //bookav.push_back(te1);
            bookav.push_back(te2);
            bookav.push_back(te3);
            bookav.push_back(te4);
            bookav.push_back(te5);
            bookav.push_back(te6);
            BookA.Insert(bookISBN_fin, bookav);
            BookA.SaveHead();  //保存信息
            QMessageBox::information(this, "提示", "添加成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

            ui->add_ISBN->setText("");
            ui->add_bookName->setText("");
            ui->add_author->setText("");
            ui->add_publish->setText("");
            ui->add_price->setText("");
            ui->add_amount->setText("");
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
    //选中删除书本
    //获取现在表格中现选中的行row和model
    int row = ui->bookInformationDelate->currentIndex().row();
    QAbstractItemModel *model = ui->bookInformationDelate->model();

    QModelIndex index1 = model->index(row,0); //获得第一列内容
    QVariant data1 = model->data(index1);  //获得data的值
    QString bookNumber = data1.toString();  //书编号

    QModelIndex index2 = model->index(row,1); //获得第二列内容
    QVariant data2 = model->data(index2);  //获得data的值
    QString bookName = data1.toString();   //书名

    QModelIndex index3 = model->index(row,2); //获得第三列内容
    QVariant data3 = model->data(index3);  //获得data的值
    QString bookAuthur = data1.toString(); //作者

    QModelIndex index4 = model->index(row,3); //获得第四列内容
    QVariant data4 = model->data(index4);  //获得data的值
    QString bookPublish = data1.toString(); //出版社

    QModelIndex index5 = model->index(row,4); //获得第五列内容
    QVariant data5 = model->data(index5);  //获得data的值
    QString publishTime = data1.toString(); //出版时间

    QModelIndex index6 = model->index(row,5); //获得第六列内容
    QVariant data6 = model->data(index6);  //获得data的值
    QString bookPrice = data1.toString();  //书价格

    QModelIndex index7 = model->index(row,6); //获得第七列内容
    QVariant data7 = model->data(index7);  //获得data的值
    QString bookState = data1.toString();  //借阅状态

    //打开BookA
    BPlusTree<string> BookA;
    BookA.SetTableName(string("BookA"));
    BookA.ReadHead();

    //遍搜索BookA（根据图书编码）
    string bookNumber_fin = bookNumber.toStdString();
    Return3 result1 = BookA.Search(bookNumber_fin, BookA.GetRootName());
    if(result1.Succ)
    {
        //若成功找到
        //先要判断一下借阅状态
        if(result1.ve[2].num != 0)
        {
            //若是借阅状态的
            QMessageBox::information(this, "提示", "这本书当前是借阅状态，确定删除吗", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        }
        else
        {
            //非借阅状态
            result1.ve[3].is = 1; //将标志位改为删除状态：1
            BookA.Update(bookNumber_fin,result1.ve);  //更新数据信息
            //确认删除后将表格中的数据也删除
            model->removeRow(row,QModelIndex());
        }
    }






}


void MainWindow_Manage::on_btn_manageSystem_clicked()
{
    //点击进入关于系统操作的界面
    this->hide();
    SystemManage* sysWin = new SystemManage();
    sysWin->show();
}

void MainWindow_Manage::on_affirmBottonUpdate_clicked()
{
    //点击确定更新书本信息
    //选中更新书本
    //获取现在表格中现选中的行row和model
    int row = ui->bookInformationUpdate->currentIndex().row();
    QAbstractItemModel *model = ui->bookInformationUpdate->model();

    QModelIndex index1 = model->index(row,0); //获得第一列内容
    QVariant data1 = model->data(index1);  //获得data的值
    QString bookNumber_q = data1.toString();  //书编号

    QModelIndex index2 = model->index(row,1); //获得第二列内容
    QVariant data2 = model->data(index2);  //获得data的值
    QString bookName_q = data2.toString();   //书名

    QModelIndex index3 = model->index(row,2); //获得第三列内容
    QVariant data3 = model->data(index3);  //获得data的值
    QString bookAuthur_q = data3.toString(); //作者

    QModelIndex index4 = model->index(row,3); //获得第四列内容
    QVariant data4 = model->data(index4);  //获得data的值
    QString bookPublish_q = data4.toString(); //出版社

    QModelIndex index5 = model->index(row,4); //获得第五列内容
    QVariant data5 = model->data(index5);  //获得data的值
    QString publishTime_q = data5.toString(); //出版时间

    QModelIndex index6 = model->index(row,5); //获得第六列内容
    QVariant data6 = model->data(index6);  //获得data的值
    QString bookPrice_q = data6.toString();  //书价格

    QModelIndex index7 = model->index(row,6); //获得第七列内容
    QVariant data7 = model->data(index7);  //获得data的值
    QString bookState_q = data7.toString();  //借阅状态

    //打开BookA
    BPlusTree<string> BookA;
    BookA.SetTableName(string("BookA"));
    BookA.ReadHead();

    //打开BookB
    BPlusTree<string> BookB;
    BookB.SetTableName(string("BookB"));
    BookB.ReadHead();

    //搜索BookA（根据图书编码）
    string bookNumber_fin = bookNumber.toStdString();
    Return3 result1 = BookA.Search(bookNumber_fin, BookA.GetRootName());
    if(result1.Succ)
    {
        //若成功找到
        //获取所要修改的项和修改的值
        QString updateItem_q = ui->updateOption_CB->currentText();
        QString updataInput_q = ui->updateTo_Input->text();

        //定义选择栏里面的title
        QString ISBN_title = "ISBN";
        QString bookName_title = "书名";
        QString bookAuthur_title = "作者";
        QString bookPublish_title = "出版社";
        QString publishTime_title = "出版时间";
        QString bookPrice_title = "价格";
        QString bookState_title = "状态";

        //判断对信息进行更改
        switch (updateItem_q) {
        case ISBN_title:
                    bookNumber_q = updataInput_q;
                    break;
        case bookName_title:
                    bookName_q = updataInput_q;
                    break;
        case bookAuthur_title:
                    bookAuthur_q = updateInput_q;
                    break;
        case bookPublish_title:
                    bookPublish_q = updateInput_q;
                    break;
        case publishTime_title:
                    publishTime_q = updataInput_q;
                    break;
        case bookPrice_title:
                    bookPrice_q = updataInput_q;
                    break;
        case bookState_title:
                    bookState_q = updateInput_q;
                    break;
        default:
                    break;
        }

        //类型转换
        //result1.ve

    }
}
