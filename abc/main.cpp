#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include "b_plus_tree.h"

int register_location = 0;
int manage_jurisdiction = 0;
int mark = 0;
int savesign = 1;
int user_key = 0;
int admin_key = 0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(mark == 1)
    {
        //User表
        BPlusTree<string> User; //新建一个对象
        User.BuildTree("User"); //表的名字为User
        vector<short>userv;//表的属性列
        //0->string  1->int  2->longlong  3->bool
        userv.push_back(0);	//用户名是string类型
        userv.push_back(0); //密码是string类型
        userv.push_back(0); //院系是string类型
        userv.push_back(1); //欠费目前类型还没有设置double 用int代替
        User.SetTable(userv); //使用testv设置表的属性列
        savesign = User.SaveHead();
        cout<<savesign<<endl;

        //Admin表
        BPlusTree<string> Admin;
        Admin.BuildTree("Admin");
        vector<short>adminv;
        //0->string  1->int  2->longlong  3->bool
        adminv.push_back(0); //用户名作为索引值string类型
        adminv.push_back(0); //密码string类型
        Admin.SetTable(adminv);
        savesign = Admin.SaveHead();
        cout<<savesign<<endl;

        //Borrow表
        BPlusTree<int> Borrow;
        Borrow.BuildTree("Borrow");
        vector<short>borrowv;
        borrowv.push_back(1); //图书借阅表key值为int类型
        borrowv.push_back(0); //图书编号ISBNstring为类型
        borrowv.push_back(0); //用户索引（用户表用户名）string类型
        borrowv.push_back(0); //借阅时间string类型
        Borrow.SetTable(borrowv);
        savesign = Borrow.SaveHead();
        cout<<savesign<<endl;

        //History表
        BPlusTree<int> History;
        History.BuildTree("History");
        vector<short>historyv;
        historyv.push_back(1); //历史借阅表key值为int类型
        historyv.push_back(1); //图书索引值int类型
        historyv.push_back(0); //用户索引值string类型
        historyv.push_back(0); //借阅时间string类型
        historyv.push_back(0); //归还时间string类型
        History.SetTable(historyv);
        savesign = History.SaveHead();
        cout<<savesign<<endl;

        //BookA表
        BPlusTree<string> BookA;
        BookA.BuildTree("BookA");
        vector<short>bookav;
        bookav.push_back(0); //书籍编号作为key值string类型（ISBN+后三位）
        bookav.push_back(0); //用户名string类型
        bookav.push_back(0); //最新借阅时间string类型
        bookav.push_back(3); //是否被续借使用bool类型
        bookav.push_back(3); //标志位表示是否被标记为删去bool类型
        bookav.push_back(0); //ISBN码string类型（作为BookB的映射联系）
        BookA.SetTable(bookav);
        savesign = BookA.SaveHead();
        cout<<savesign<<endl;

        //BookB表
        BPlusTree<string> BookB;
        BookB.BuildTree("BookB");
        vector<short>bookbv;
        bookbv.push_back(0); //以ISBN作为key值string类型
        bookbv.push_back(0); //书名string类型
        bookbv.push_back(0); //作者string类型
        bookbv.push_back(0); //出版社string类型
        bookbv.push_back(0); //出版时间string类型
        bookbv.push_back(0); //价格暂时string（后面会用double代替）
        BookB.SetTable(bookbv);
        savesign = BookB.SaveHead();
        cout<<savesign<<endl;

    }

    Login loginWin;
    loginWin.show();

    return a.exec();
}


