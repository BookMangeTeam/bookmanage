#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

#endif // B_PLUS_TREE_H

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#define OK 1
#define NO 0
#define ERROR -1
/*
B+树存的Key是子树最小值
 */
/*
把新文件的名字记录下来
输出keynum、IsLeaf等信息
 */
/*
需要重新命名，同一个key名对应多个
 */
using namespace std;
#define MAXNODE 4

union Undecide{//数据库的存储单元
    char s[100];
    int num;
    long long LL;
    bool is;
};

struct Return3{
//函数返回状态的记录
//包括是否成功、文件名和找到的文件信息
    bool Succ;
    string filename;
    vector<Undecide> ve;
    Return3(bool a, string b, vector<Undecide> v){
        Succ = a;
        filename = b;
        ve = v;
    }
};

template<typename T1>
struct  Return4{
    bool Succ;
    string filename;
    vector<Undecide> ve;
    T1 Key;
    Return4<T1>(){}
    Return4<T1>(bool a, T1 key, string b, vector<Undecide> v){
        Succ = a;
        filename = b;
        ve = v;
        Key = key;
    }
};

template<typename T1>
class BPlusTree{
public:
    void BuildTree(string Table);//建立一棵只有一个空的根节点的树
    //B+树搜索过程，递归搜索，初始先搜索root
    Return3 Search(T1 Key, string filename);
    string TransIntToString(int Num);
    bool Insert(T1 Key, vector<Undecide>v);
    bool Insert2(T1 Key, string filename, vector<Undecide>v);
    Return3 SearchForInsert(T1 Key, string filename);
    void SetTable(vector<short> v);
    bool SetSon_sFather(string filename, string newfather);
    bool Delete(T1 Key);
    bool Delete2(string filename, T1 Key);
    string GetRootName();
    bool ChangePreNameForDel(string filename, T1 original, T1 newkey);
    Return4<T1> BorrowNodes(string filename, T1 Key);
    bool Union2(string file1, string file2);
    Return4<T1> UnionNodes(string filename, T1 Key);
    bool SaveHead();
    bool ReadHead();
    void SetSonAll(string filename, string newfather);
    bool Update(T1 Key, vector<Undecide>ve);
    vector<pair< T1,vector<Undecide> > > AllLeaf();
private:
    //储存表的结构，每个位置对应一个数字
    vector<short> TypeList;  //0->string  1->int  2->longlong  3->bool
    string TableName;
    int NodeNum;
    string RootName;
};


template<typename T1>
string BPlusTree<T1>::GetRootName(){
    return RootName;
}


template<typename T1>
void BPlusTree<T1>::SetTable(vector<short>v){
    TypeList = v;
    return;
}

template<typename T1>
string BPlusTree<T1>::TransIntToString(int Num){
    stringstream ss;
    string s;
    ss << Num;
    ss >> s;
    return s;
}

//建树的过程
template<typename T1>
void BPlusTree<T1>::BuildTree(string Table){
    NodeNum = 0;
    //根节点文件命名为root.dat
    TableName = Table;
    RootName = TableName+TransIntToString(NodeNum)+string(".dat");
    NodeNum++;
    ofstream out;
    out.open(RootName.c_str()); //转换成c语言的字符串格式
    out << 0 << " ";//根节点中有0个Key
    out << 1 << " ";//根节点类型为叶子节点
    out << "NULL" << " ";//根节点没有父亲节点
    out.close();
}

//B+树搜索过程，输入要搜索的Key和现在搜索到的文件名称
template<typename T1>
Return3 BPlusTree<T1>::Search(T1 Key, string filename){
    //tempkey用来保存当前文件中的key值
    T1 tempkey[MAXNODE];
    string tempfilename[MAXNODE];
    ifstream in;
    in.open(filename.c_str());//打开当前文件
    int KeyNum = 0;
    in >> KeyNum;//输入key值个数
    bool IsLeaf = 0;
    in >> IsLeaf;//输入是否是叶子节点
    string father;
    in >> father;//输入该文件的父节点文件
    if(IsLeaf == true){//如果该文件节点是叶子节点
        vector<Undecide>v;//用来储存key的附加信息
        for(int i = 0; i < KeyNum; i++){
            in >> tempkey[i];//输入一个key值
            Undecide ttt;
            //输入对应的附加信息
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) in >> ttt.s;
                else if(TypeList[j] == 1) in >> ttt.num;
                else if(TypeList[j] == 2) in >> ttt.LL;
                else in >> ttt.is;
                //如果当前遍历的这个tempkey是Key，则将这个文件信息保存起来
                if(tempkey[i] == Key)
                    v.push_back(ttt);
            }
        }
        //如果有过对tempkey的保存
        if(v.size() != 0){
            //返回找到了这个信息，当前这个文件的名字，这个key对应的附加信息
            Return3 ttt(true,filename,v);
            return ttt;
        }
        else{
            //返回未找到这个信息，当前这个文件的名字，这个key对应的附加信息
            Return3 ttt(false,filename,v);
            return ttt;
        }
    }
    else{//如果这个节点是中间节点
        //遍历输入该文件节点所存储的key和对应的文件名
        for(int i = 0; i < KeyNum; i++){
            in >> tempkey[i];
            in >> tempfilename[i];
        }
        int next_no;

        //寻找下一个需要寻找的文件
        for(int i = 0; i < KeyNum-1; i++){
            next_no = i;
            //如果当前这个tempkey比Key小，而且下一个tempkey比Key大，则表示寻找到了
            if(Key>=tempkey[i] && Key<tempkey[i+1])
                break;
        }
        if(Key < tempkey[0])
            next_no = 0;
        //如果这个key比tempkey[keynum-1]还大，则应该在最后一个key中
        if(Key >= tempkey[KeyNum-1])
            next_no = KeyNum-1;
        //递归搜索下一个应搜索的文件
        return Search(Key,tempfilename[next_no]);
    }
    in.close();
}

//B+树的插入过程，首先使用Search函数对Key进行搜索
//如果B+树中存在这个Key，则不进行操作
//如果B+树中不存在这个Key，则调用Insert2函数进行插入操作
template<typename T1>
bool BPlusTree<T1>::Insert(T1 Key, vector<Undecide>v){
    Return3 temp = SearchForInsert(Key, RootName);
    if(temp.Succ == true){
        return false;
    }
    Insert2(Key, temp.filename, v);
}

//向filename文件中插入一个Key
template<typename T1>
bool BPlusTree<T1>::Insert2(T1 Key, string filename, vector<Undecide>v){
    // cout << "插入的key为" << Key << endl;
    T1 tempkey[MAXNODE];
    string tempfilename[MAXNODE];
    ifstream in;
    in.open(filename.c_str());
    int KeyNum = 0;
    in >> KeyNum;
    bool IsLeaf = 0;
    in >> IsLeaf;
    string father;
    in >> father;
    int ISROOT = 0;
    if(KeyNum+1 > MAXNODE){//如果超界
        if(filename == RootName){
            ISROOT = 1;
            string newfathername = TableName+TransIntToString(NodeNum)+string(".dat");
            NodeNum++;
            father = newfathername;
            RootName = newfathername;
            ofstream outroot;

            outroot.open(newfathername.c_str());
            outroot << 0 << " ";//根节点中有0个Key
            outroot << 0 << " ";//根节点类型为中间节点
            outroot << "NULL" << " ";//根节点没有父亲节点
            outroot.close();
        }
        /*
        分裂成两个，一个原来就在父节点，另一个需要通过Insert2的方式加入
        注意插入以后需要更新父节点
        */
        //新建两个文件，分别命名为temp+filename和split+filename
        //将filename中的文件分别输入到上述两个文件中
        //输入完以后将filename文件删除，将temp+filename重命名为filename
        //将split+filename重命名为newfilename
        //newfilename通过插入过程中记录第一个出现在第二个文件中的key决定
        string newname = TableName+TransIntToString(NodeNum)+string(".dat");
        NodeNum++;
        string temp_string = string("temp");
        ofstream out((temp_string+filename).c_str());
        ofstream out2(newname.c_str());
        //首先将两个新文件的文件头写入
        out << (MAXNODE/2) << " ";
        out << IsLeaf << " ";
        out << father << " ";
        out2 << KeyNum+1-(MAXNODE/2) << " ";
        out2 << IsLeaf << " ";
        out2 << father << " ";
        int second_flag = 0;//用此变量记录第二个文件中的第一个key
        T1 second_filename;
        if(IsLeaf == true){ //超界且为叶子节点
            int flag = 0;//用来判断有没有插入
            //遍历所有的tempkey
            for(int i = 0; i < KeyNum; i++){
                in >> tempkey[i];
                //如果找到了应该插入的位置
                if(tempkey[i] > Key && flag==0){
                    flag = 1;
                    //如果插入后将应该首个放在第二个文件中的key
                    //则将其记录key记录在second_filename中
                    //并使用second_flag=1标志第二个文件中已经有key
                    if(i+flag >= MAXNODE/2 && second_flag==0){
                        second_flag = 1;
                        second_filename = Key;//第二个文件的key
                    }
                    if(i+flag < MAXNODE/2)
                        out << Key << " ";
                    else
                        out2 << Key << " ";
                    //遍历应该插入的数据的所有项，v是传入的vector
                    for(int j = 0; j < TypeList.size(); j++){
                        if(TypeList[j] == 0){
                            if(i+flag < MAXNODE/2)
                                out << v[j].s << " ";
                            else
                                out2 << v[j].s << " ";
                        }
                        else if(TypeList[j] == 1){
                            if(i+flag < MAXNODE/2)
                                out << v[j].num << " ";
                            else
                                out2 << v[j].num << " ";
                        }
                        else if(TypeList[j] == 2){
                            if(i+flag < MAXNODE/2)
                                out << v[i].LL << " ";
                            else
                                out2 << v[i].LL << " ";
                        }
                        else{
                            if(i+flag < MAXNODE/2)
                                out << v[i].is << " ";
                            else
                                out2 << v[i].is << " ";
                        }
                    }
                }
                Undecide ttt;
                //判断第二个文件的首个key
                if(i+flag >= MAXNODE/2 && second_flag==0){
                    second_flag = 1;
                    second_filename = tempkey[i];
                }
                if(i+flag < MAXNODE/2)
                    out << tempkey[i] << " ";
                else
                    out2 << tempkey[i] << " ";
                for(int j = 0; j < TypeList.size(); j++){
                    if(TypeList[j] == 0){
                        in >> ttt.s;
                        if(i+flag < MAXNODE/2)
                            out << ttt.s<< " ";
                        else
                            out2 << ttt.s << " ";
                    }
                    else if(TypeList[j] == 1){
                        in >> ttt.num;
                        if(i+flag < MAXNODE/2)
                            out << ttt.num<< " ";
                        else
                            out2 << ttt.num << " ";
                    }
                    else if(TypeList[j] == 2){
                        in >> ttt.LL;
                        if(i+flag < MAXNODE/2)
                            out << ttt.LL<< " ";
                        else
                            out2 << ttt.LL << " ";
                    }
                    else{
                        in >> ttt.is;
                        if(i+flag < MAXNODE/2)
                            out << ttt.is<< " ";
                        else
                            out2 << ttt.is << " ";
                    }
                }
            }
            //如果一直没有插入到文件的key中，则说明key大于所有的tempkey
            //所以应该插入到tempkey[keynum-1]后面
            if(flag == 0){
                flag = 1;
                if(KeyNum+flag >= MAXNODE/2 && second_flag==0){
                    second_flag = 1;
                    second_filename = tempkey[KeyNum-1];
                }
                out2 << Key << " ";
                for(int j = 0; j < TypeList.size(); j++){
                        if(TypeList[j] == 0){
                            if(KeyNum+flag < MAXNODE/2)
                                out << v[j].s << " ";
                            else
                                out2 << v[j].s << " ";
                        }
                        else if(TypeList[j] == 1){
                            if(KeyNum+flag < MAXNODE/2)
                                out << v[j].num<< " ";
                            else
                                out2 << v[j].num << " ";
                        }
                        else if(TypeList[j] == 2){
                            if(KeyNum+flag < MAXNODE/2)
                                out << v[j].LL<< " ";
                            else
                                out2 << v[j].LL << " ";
                        }
                        else{
                            if(KeyNum+flag < MAXNODE/2)
                                out << v[j].is<< " ";
                            else
                                out2 << v[j].is << " ";
                        }
                }
            }
        }
        else{ //超界，为中间节点
            int flag = 0;//有没有插入
            for(int i = 0; i < KeyNum; i++){
                in >> tempkey[i];
                if(tempkey[i] > Key && flag ==0){
                    //插入
                    flag = 1;
                    if(i+flag >= MAXNODE/2 && second_flag==0){
                        second_flag = 1;
                        second_filename = Key;
                    }
                    //插入一个filename，这个filename存在vector参数的0位
                    //插入到第一个文件中
                    if(i+flag < MAXNODE/2){
                        out << Key << " ";
                        out << v[0].s << " ";
                    }
                    //插入到第二个文件中
                    else{
                        out2 << Key << " ";
                        out2 << v[0].s << " ";
                        SetSon_sFather(v[0].s,newname);
                    }
                }
                //记录是否是第一个插入到第二个文件中的key
                if(i+flag >= MAXNODE/2 && second_flag==0){
                    second_flag = 1;
                    second_filename = tempkey[i];
                }
                //正常输出到两个文件中
                string ttt;
                in >> ttt;
                if(i+flag < MAXNODE/2){
                    out << tempkey[i] << " ";
                    out << ttt << " ";
                }
                else{
                    out2 << tempkey[i] << " ";
                    out2 << ttt << " ";
                    SetSon_sFather(ttt,newname);
                }
            }
            //如果没有被插入过，则说明key比所有tempkey都大
            //所以应该输入到tempkey[keynum-1]之后
            if(flag == 0){
                if(KeyNum+flag >= MAXNODE/2 && second_flag==0){
                    second_flag = 1;
                    second_filename = tempkey[KeyNum-1];
                }

                if(KeyNum+flag < MAXNODE/2){
                        out << Key << " ";
                        out << v[0].s << " ";
                    }
                else{
                        out2 << Key << " ";
                        out2 << v[0].s << " ";
                        SetSon_sFather(v[0].s,newname);
                }
            }
        }
        out.close();
        out2.close();
        //删除和重命名文件
        vector<Undecide> vvv;
        Undecide ttt;
        strcpy(ttt.s,newname.c_str());
        vvv.push_back(ttt);
        in.close();
        remove(filename.c_str());
        rename((temp_string+filename).c_str(),filename.c_str());
        if(ISROOT==1){
            // cout<<"root 分裂"<< endl;
            IsLeaf = 0;
            vector<Undecide> vvv2;
            Undecide ttt2;
            strcpy(ttt2.s,filename.c_str());
            vvv2.push_back(ttt2);
            // cout << min(Key,tempkey[0]) << " " << father << endl;
            Insert2(min(Key,tempkey[0]),father,vvv2);
        }
        // cout << second_filename << " " << father << endl;
        Insert2(second_filename,father,vvv);
    }
    else{//如果没超界
        string temp_string = string("temp");//用此string实现删除原文件并重命名
        ofstream out((temp_string+filename).c_str());
        //先输出文件头信息
        out << KeyNum+1 << " ";
        out << IsLeaf << " ";
        out << father << " ";
        if(IsLeaf == true){ //没有超界且为叶子节点
            int flag = 0;//有没有插入
            for(int i = 0; i < KeyNum; i++){
                in >> tempkey[i];
                if(tempkey[i] > Key && flag==0){
                    //插入
                    flag = 1;
                    out << Key << " ";
                    for(int j = 0; j < TypeList.size(); j++){
                        if(TypeList[j] == 0){
                            out << v[j].s << " ";
                        }
                        else if(TypeList[j] == 1){
                            out << v[j].num << " ";
                        }
                        else if(TypeList[j] == 2){
                            out << v[j].LL << " ";
                        }
                        else{
                            out << v[j].is << " ";
                        }
                    }
                }
                Undecide ttt;
                out << tempkey[i] << " ";
                for(int j = 0; j < TypeList.size(); j++){
                    if(TypeList[j] == 0){
                        in >> ttt.s;
                        out << ttt.s<< " ";
                    }
                    else if(TypeList[j] == 1){
                        in >> ttt.num;
                        out << ttt.num<< " ";
                    }
                    else if(TypeList[j] == 2){
                        in >> ttt.LL;
                        out << ttt.LL<< " ";
                    }
                    else{
                        in >> ttt.is;
                        out << ttt.is<< " ";
                    }
                }
            }
            if(flag == 0){
                flag = 1;
                out << Key << " ";
                for(int i = 0; i < TypeList.size(); i++){
                        if(TypeList[i] == 0){
                            out << v[i].s << " ";
                        }
                        else if(TypeList[i] == 1){
                            out << v[i].num<< " ";
                        }
                        else if(TypeList[i] == 2){
                            out << v[i].LL<< " ";
                        }
                        else{
                            out << v[i].is<< " ";
                        }
                }
            }
        }
        else{ //没有超界，为中间节点
            int flag = 0;//有没有插入
            for(int i = 0; i < KeyNum; i++){
                in >> tempkey[i];
                if(tempkey[i] > Key && flag==0){
                    //插入
                    flag = 1;
                    out << Key << " ";
                    out << v[0].s << " ";
                }
                string ttt;
                in >> ttt;
                out << tempkey[i] << " ";
                out << ttt << " ";
            }
            if(flag == 0){
                flag = 1;
                out << Key << " ";
                out << v[0].s << " ";
            }
        }
        out.close();
        in.close();
        remove(filename.c_str());
        rename((temp_string+filename).c_str(),filename.c_str());
    }
}

template<typename T1>
void BPlusTree<T1>::SetSonAll(string filename, string newfather){
    //cout << filename << " set All son " << newfather << endl;
    ifstream in;
    in.open(filename.c_str());
    int KeyNum;
    in >> KeyNum;
    bool IsLeaf;
    in >> IsLeaf;
    string father;
    in >> father;
    if(IsLeaf == true)
        return;
    T1 tempk;
    string tempf;
    for(int i = 0; i < KeyNum; i++){
        in >> tempk;
        in >> tempf;
        SetSon_sFather(tempf,newfather);
    }
    return;
}

template<typename T1>
bool BPlusTree<T1>::SetSon_sFather(string filename, string newfather){
    //cout << "set single son " << filename << " " << newfather << endl;
    T1 tempkey[MAXNODE];
    string tempfilename[MAXNODE];
    vector<Undecide> v[MAXNODE];
    ifstream in;
    in.open(filename.c_str());//打开当前文件
    int KeyNum = 0;
    in >> KeyNum;//输入key值个数
    bool IsLeaf = 0;
    in >> IsLeaf;//输入是否是叶子节点
    string father;
    in >> father;//输入该文件的父节点文件
    if(IsLeaf == true){//如果该文件节点是叶子节点
        for(int i = 0; i < KeyNum; i++){
            in >> tempkey[i];//输入一个key值
            //输入对应的附加信息
            Undecide ttt;
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) in >> ttt.s;
                else if(TypeList[j] == 1) in >> ttt.num;
                else if(TypeList[j] == 2) in >> ttt.LL;
                else in >> ttt.is;
                v[i].push_back(ttt);
            }
        }
    }
    else{
        // cout << "开始" << endl;
        //如果这个节点是中间节点
        //遍历输入该文件节点所存储的key和对应的文件名
        for(int i = 0; i < KeyNum; i++){
            in >> tempkey[i];
            in >> tempfilename[i];
        }
    }
    in.close();
    ofstream out;
    out.open(filename.c_str());
    out << KeyNum << " ";
    out << IsLeaf << " ";
    out << newfather << " ";
    if(IsLeaf == true){
        for(int i = 0; i < KeyNum; i++){
            out << tempkey[i] << " ";//输入一个key值
            //输入对应的附加信息
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) out << v[i][j].s << " ";
                else if(TypeList[j] == 1) out << v[i][j].num << " " ;
                else if(TypeList[j] == 2) out << v[i][j].LL << " ";
                else out << v[i][j].is << " ";
            }
        }
    }
    else{
        for(int i = 0; i < KeyNum; i++){
            out << tempkey[i] << " ";
            out << tempfilename[i]<<" ";
        }
    }
}

//由上向下查找，判断是否需要为文件改key
template<typename T1>
Return3 BPlusTree<T1>::SearchForInsert(T1 Key, string filename){
    //tempkey用来保存当前文件中的key值
    T1 tempkey[MAXNODE];
    string tempfilename[MAXNODE];
    ifstream in;
    in.open(filename.c_str());//打开当前文件
    int KeyNum = 0;
    in >> KeyNum;//输入key值个数
    bool IsLeaf = 0;
    in >> IsLeaf;//输入是否是叶子节点
    // cout << "Key=" << Key << " IsLeaf = " << IsLeaf << endl;
    string father;
    in >> father;//输入该文件的父节点文件
    if(IsLeaf == true){//如果该文件节点是叶子节点
        vector<Undecide>v;//用来储存key的附加信息
        for(int i = 0; i < KeyNum; i++){
            in >> tempkey[i];//输入一个key值
            Undecide ttt;
            //输入对应的附加信息
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) in >> ttt.s;
                else if(TypeList[j] == 1) in >> ttt.num;
                else if(TypeList[j] == 2) in >> ttt.LL;
                else in >> ttt.is;
                //如果当前遍历的这个tempkey是Key，则将这个文件信息保存起来
                if(tempkey[i] == Key)
                    v.push_back(ttt);
            }
        }
        //如果有过对tempkey的保存
        if(v.size() != 0){
            //返回找到了这个信息，当前这个文件的名字，这个key对应的附加信息
            Return3 ttt(true,filename,v);
            return ttt;
        }
        else{
            //返回未找到这个信息，当前这个文件的名字，这个key对应的附加信息
            Return3 ttt(false,filename,v);
            return ttt;
        }
    }
    else{
        // cout << "开始" << endl;
        //如果这个节点是中间节点
        //遍历输入该文件节点所存储的key和对应的文件名
        for(int i = 0; i < KeyNum; i++){
            in >> tempkey[i];
            in >> tempfilename[i];
        }
        int next_no;
        //寻找下一个需要寻找的文件
        for(int i = 0; i < KeyNum-1; i++){
            next_no = i;
            //如果当前这个tempkey比Key小，而且下一个tempkey比Key大，则表示寻找到了
            if(Key>=tempkey[i] && Key<tempkey[i+1])
                break;
        }
        //如果这个key比tempkey[keynum-1]还大，则应该在最后一个key中
        if(Key >= tempkey[KeyNum-1])
            next_no = KeyNum-1;
        if(Key < tempkey[0]){
            // cout << "更改key" << endl;
            next_no = 0;
            in.close();
            remove(filename.c_str());
            ofstream out;
            out.open(filename.c_str());
            out << KeyNum << " ";
            out << IsLeaf << " ";
            out << father << " ";
            out << Key << " " << tempfilename[0] << " ";
            for(int i = 1; i < KeyNum; i++)
                out << tempkey[i] << " " << tempfilename[i] <<  " ";
            out.close();
        }
        // cout << next_no << endl;
        // cout<< "进入" << tempfilename[next_no] << endl;
        //递归搜索下一个应搜索的文件
        return SearchForInsert(Key,tempfilename[next_no]);
    }
    in.close();
}

//删除一个节点，首先输入这个节点的key
template<typename T1>
bool BPlusTree<T1>::Delete(T1 Key){
    //首先从root开始找
    Return3 result = Search(Key, RootName);
    //如果没找到就返回0
    if(result.Succ == 0){
        return 0;
    }
    //如果找到了就从最底层文件中循环删除
    Delete2(result.filename, Key);
}

//输入文件名和要删除的key
template<typename T1>
bool BPlusTree<T1>::Delete2(string filename, T1 Key){
    //cout << filename << " *****************" << Key << endl;
    // if(filename == string("NULL"))return 0;
    ifstream in;
    in.open(filename.c_str());//打开当前文件
    int KeyNum = 0;
    in >> KeyNum;//输入key值个数
    bool IsLeaf = 0;
    in >> IsLeaf;//输入是否是叶子节点
    string father;
    in >> father;
    T1 tempkey[MAXNODE];
    // cout << "start" << endl;
    //不管是否满足，直接删除
    if(IsLeaf == true){//如果删除后符合要求，且为叶节点
        vector<Undecide>v[MAXNODE];//用来储存key的附加信息
        for(int i = 0; i < KeyNum; i++){
            in >> tempkey[i];//输入一个key值
            Undecide ttt;
            //输入对应的附加信息
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) in >> ttt.s;
                else if(TypeList[j] == 1) in >> ttt.num;
                else if(TypeList[j] == 2) in >> ttt.LL;
                else in >> ttt.is;
                v[i].push_back(ttt);
            }

        }
        in.close();
        //如果删除的是father节点的key，那么需要循环更改
        if(tempkey[0] == Key){
            //将上一层的tempkey0更改为tempkey1
            ChangePreNameForDel(father,tempkey[0],tempkey[1]);
        }
        //不管如何直接从文件中删除这个key
        ofstream out;
        out.open(filename.c_str());
        out << KeyNum-1 << " ";
        out << IsLeaf << " ";
        out << father << " ";
        for(int i = 0; i < KeyNum; i++){
            if(Key == tempkey[i])continue;
            out << tempkey[i] << " ";
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) out << v[i][j].s << " ";
                else if(TypeList[j] == 1) out << v[i][j].num << " ";
                else if(TypeList[j] == 2) out << v[i][j].LL << " ";
                else out << v[i][j].is << " ";
            }
        }
        out.close();
    }
    else{//如果删除后符合要求，且是中间节点
        string tempfilename[MAXNODE];
        for(int i = 0; i < KeyNum; i++){
            in >> tempkey[i];
            in >> tempfilename[i];
        }
        in.close();
        if(tempkey[0] == Key){
            ChangePreNameForDel(father,tempkey[0],tempkey[1]);
        }
        ofstream out;
        out.open(filename.c_str());
        out << KeyNum-1 << " ";
        out << IsLeaf << " ";
        out << father << " ";
        for(int i = 0; i < KeyNum; i++){
            if(Key == tempkey[i])continue;
            out << tempkey[i] << " ";
            out << tempfilename[i] << " ";
        }
        out.close();
        //如果这个节点是根节点，且只有一个子节点，则根节点重置
        if(KeyNum-1 == 1 && father == string("NULL")){
            SetSonAll(filename,string("NULL"));
            if(Key != tempkey[0])
                RootName = tempfilename[0];
            else
                RootName = tempfilename[1];
            remove(filename.c_str());
        }
    }
    // cout << "start2" << endl;
    //从这考虑删除后不满足的情况
//	cout << "single Delete succuessful" << endl;

    if(KeyNum-1 < MAXNODE/2 && father!=string("NULL")){//删除后不满足
//		cout << "unsatisfy" << endl;
        Return4<T1> result;
        //首先考虑借点，如果这个点正好是刚刚从父节点中被删除，则应该传递tempkey1
        //否则直接传递tempkey0
        // cout << result.Succ << endl;
        if(tempkey[0] == Key)
            result = BorrowNodes(father,tempkey[1]);
        else
            result = BorrowNodes(father,tempkey[0]);
//		cout << "Borrow success? "<< result.Succ << endl;
        //如果借点成功，那么此时的文件中插入借到的点
        if(result.Succ == true){
            Insert2(result.Key,filename,result.ve);
            if(tempkey[0]==Key && result.Key<tempkey[1])
                ChangePreNameForDel(father,tempkey[1],result.Key);
            if(tempkey[0]!=Key && result.Key<tempkey[0])
                ChangePreNameForDel(father,tempkey[0],result.Key);
        }
        else{//如果没有借到点那么就和父节点进行合并
            if(tempkey[0] == Key)
                UnionNodes(father,tempkey[1]);
            else
                UnionNodes(father,tempkey[0]);
        }
//		cout << "454545" << endl;
    }
}

//在filename找key的左右兄弟节点进行合并
template<typename T1>
Return4<T1> BPlusTree<T1>::UnionNodes(string filename, T1 Key){

//	cout << "Union nodes from " << filename << "  Near " << Key << endl;
    ifstream in;
    in.open(filename.c_str());
    int KeyNum;
    in >> KeyNum;
    int IsLeaf;
    in >> IsLeaf;
    string father;
    in >> father;
    T1 tempkey[MAXNODE];
    string tempfilename[MAXNODE];
    //这个文件一定是中间节点
    for(int i = 0; i < KeyNum; i++){
        in >> tempkey[i];
        in >> tempfilename[i];
    }
    in.close();
    T1 PreKey, NextKey;
    string Pre = string("NULL");
    string Next = string("NULL");
    string original;
    //分别找到这个文件的左右兄弟节点
    for(int i = 0; i < KeyNum; i++){
        if(tempkey[i] == Key){
            original = tempfilename[i];
            if(i-1 >= 0) {
                Pre = tempfilename[i-1];
                PreKey = tempkey[i-1];
            }
            if(i+1 < KeyNum) {
                Next = tempfilename[i+1];
                NextKey = tempkey[i+1];
            }
        }
    }

//	cout << "union nodes Pre= " << Pre << "Next = " << Next << endl;
    //这个地方需要注意，如果这个文件是根文件，而且只有这一个节点，则需要将根节点删除，
    //并且将他的唯一子节点设为根节点
    if(filename==RootName && Pre==string("NULL") && Next==string("NULL")){
        //将子节点的father设为NULL
        SetSonAll(filename,string("NULL"));
        //删除这个文件
        remove(filename.c_str());
        RootName = tempfilename[0];
        Return4<int> a;
        return a;
    }

    //正常合并节点
    string newfile;
    if(Pre != string("NULL")){
        newfile = Pre;
        Union2(Pre,original);
        Delete2(filename,Key);
    }
    else{
        Union2(original,Next);
        Delete2(filename,NextKey);
    }

    Return4<T1> result;
    return result;
}

template<typename T1>
bool BPlusTree<T1>::Union2(string file1, string file2){
    cout << "Union two file :" << file1 << " and " << file2 << endl;
    ifstream in1;
    ifstream in2;
    in1.open(file1.c_str());
    in2.open(file2.c_str());
    int KeyNum1;
    int KeyNum2;
    int IsLeaf;
    string father;
    in1 >> KeyNum1;
    in2 >> KeyNum2;
    in1 >> IsLeaf;
    in2 >> IsLeaf;
    in1 >> father;
    in2 >> father;
    T1 tempkey[MAXNODE];
    string	temp_string = string("temp");
    if(IsLeaf == true){
        ofstream out;
        out.open((temp_string+file1).c_str());
        out << KeyNum1+KeyNum2 << " ";
        out << IsLeaf << " ";
        out << father << " ";
        for(int i = 0; i < KeyNum1; i++){
            in1 >> tempkey[i];//输入一个key值
            out << tempkey[i] << " ";
            Undecide ttt;
            //输入对应的附加信息
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) {
                    in1 >> ttt.s;
                    out << ttt.s << " ";
                }
                else if(TypeList[j] == 1){
                    in1 >> ttt.num;
                    out << ttt.num << " ";
                }
                else if(TypeList[j] == 2) {
                    in1 >> ttt.LL;
                    out << ttt.LL << " ";
                }
                else{
                    in1 >> ttt.is;
                    out << ttt.is << " ";
                }
            }
        }
        for(int i = 0; i < KeyNum2; i++){
            in2 >> tempkey[i];//输入一个key值
            out << tempkey[i] << " ";
            Undecide ttt;
            //输入对应的附加信息
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) {
                    in2 >> ttt.s;
                    out << ttt.s << " ";
                }
                else if(TypeList[j] == 1){
                    in2 >> ttt.num;
                    out << ttt.num << " ";
                }
                else if(TypeList[j] == 2) {
                    in2 >> ttt.LL;
                    out << ttt.LL << " ";
                }
                else{
                    in2 >> ttt.is;
                    out << ttt.is << " ";
                }
            }
        }
        remove(file1.c_str());
        remove(file2.c_str());
        rename((temp_string+file1).c_str(),file1.c_str());
        in1.close();
        in2.close();
        out.close();
//		cout << "end..............." << endl;
    }
    else{
        ofstream out;
        out.open((temp_string+file1).c_str());
        out << KeyNum1+KeyNum2 << " ";
        out << IsLeaf << " ";
        out << father << " ";
        string tempfilename[MAXNODE];
        for(int i = 0; i < KeyNum1; i++){
            in1 >> tempkey[i];
            in1 >> tempfilename[i];
            out << tempkey[i] << " ";
            out << tempfilename[i] << " ";
        }
        for(int i = 0; i < KeyNum2; i++){
            in2 >> tempkey[i];
            in2 >> tempfilename[i];
            out << tempkey[i] << " ";
            out << tempfilename[i] << " ";
        }
        cout << "Setson " << file2 << " to " << file1 << endl;
        SetSonAll(file2,file1);
        remove(file1.c_str());
        remove(file2.c_str());
        rename((temp_string+file1).c_str(),file1.c_str());
        in1.close();
        in2.close();
        out.close();
    }
    // exit(0);
//	cout << "454545454" << endl;
}

//从filename文件中的key节点的兄弟节点中借一个节点给filename
template<typename T1>
Return4<T1> BPlusTree<T1>::BorrowNodes(string filename, T1 Key){
//	cout << "Borrow from " << filename << " near " << Key << endl;
    ifstream in;
    in.open(filename.c_str());
    int KeyNum;
    in >> KeyNum;
    int IsLeaf;
    in >> IsLeaf;
    string father;
    in >> father;
    T1 tempkey[MAXNODE];
    string tempfilename[MAXNODE];
    for(int i = 0; i < KeyNum; i++){
        in >> tempkey[i];
        in >> tempfilename[i];
    }
    in.close();
    string Pre = string("NULL");
    string Next = string("NULL");
    for(int i = 0; i < KeyNum; i++){
        if(tempkey[i] == Key){
            if(i-1 >= 0) Pre = tempfilename[i-1];
            if(i+1 < KeyNum) Next = tempfilename[i+1];
        }
    }
//	cout << "Left:" << Pre << " Right" << Next << endl;
    if(Pre != string("NULL")){//从左兄弟节点借最右边的点
        in.open(Pre.c_str());
        in >> KeyNum;
        in >> IsLeaf;
        in >> father;
        if(KeyNum-1>=MAXNODE/2 && IsLeaf == true){
            for(int i = 0; i < KeyNum-1; i++){
                in >> tempkey[i];//输入一个key值
                Undecide ttt;
                //输入对应的附加信息
                for(int j = 0; j < TypeList.size(); j++){
                    if(TypeList[j] == 0) in >> ttt.s;
                    else if(TypeList[j] == 1) in >> ttt.num;
                    else if(TypeList[j] == 2) in >> ttt.LL;
                    else in >> ttt.is;
                }
            }
            T1 borrowKey;
            in >> borrowKey;
            vector<Undecide>v;
            Undecide tt2;
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) in >> tt2.s;
                else if(TypeList[j] == 1) in >> tt2.num;
                else if(TypeList[j] == 2) in >> tt2.LL;
                else in >> tt2.is;
                v.push_back(tt2);
            }
            in.close();
            Delete2(Pre,borrowKey);
            return Return4<T1>(true,borrowKey,Pre,v);
        }
        if(KeyNum-1>=MAXNODE/2 && IsLeaf == false){
            T1 tempkey[MAXNODE];
            string tempfilename[MAXNODE];
            for(int i = 0; i < KeyNum-1; i++){
                in >> tempkey[i];
                in >> tempfilename[i];
            }
            T1 borrowKey;
            string borrowfile;
            in >> borrowKey;
            in >> borrowfile;
            in.close();
            vector<Undecide>v;
            Undecide tt2;
            strcpy(tt2.s,Pre.c_str());
            v.push_back(tt2);
            Delete2(Pre,borrowKey);
            return Return4<T1>(true,borrowKey,borrowfile,v);
        }
    }
    if(Next != string("NULL")){
        in.open(Next.c_str());
        in >> KeyNum;
        in >> IsLeaf;
        in >> father;
        // cout << KeyNum << " " << IsLeaf << endl;
        if(KeyNum-1>=MAXNODE/2 && IsLeaf==true){
            T1 borrowKey;
            in >> borrowKey;
            vector<Undecide>v;
            Undecide tt2;
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) in >> tt2.s;
                else if(TypeList[j] == 1) in >> tt2.num;
                else if(TypeList[j] == 2) in >> tt2.LL;
                else in >> tt2.is;
                v.push_back(tt2);
            }
            in.close();
            // cout << Next << "***" << endl;
            Delete2(Next,borrowKey);
            return Return4<T1>(true,borrowKey,Next,v);
        }
        if(KeyNum-1>=MAXNODE/2 && IsLeaf==false){
            T1 borrowKey;
            string borrowfile;
            in >> borrowKey;
            in >> borrowfile;
            in.close();
            Undecide t;
            strcpy(t.s,borrowfile.c_str());
            vector<Undecide>v;
            v.push_back(t);
            Delete2(Next,borrowKey);
            return Return4<T1>(true,borrowKey,Next,v);
        }
    }
    T1 NONO1;
    vector<Undecide>v;
    return Return4<T1>(false,NONO1,filename,v);
}



template<typename T1>
bool BPlusTree<T1>::ChangePreNameForDel(string filename, T1 original, T1 newkey){
    ifstream in;
    in.open(filename.c_str());
    int KeyNum = 0;
    in >> KeyNum;//输入key值个数
    bool IsLeaf = 0;
    in >> IsLeaf;//输入是否是叶子节点
    string father;
    in >> father;//输入该文件的父节点文件
    T1 tempkey[MAXNODE];
    string tempfilename[MAXNODE];
    for(int i = 0; i < KeyNum; i++){
        in >> tempkey[i];
        in >> tempfilename[i];
    }
    in.close();
    ofstream out;
    out.open(filename.c_str());
    out << KeyNum << " ";
    out << IsLeaf << " ";
    out << father << " ";
    // if(father == string("NULL") || IsLeaf==true)
    // 	return 0;
    if(tempkey[0] == original && father != string("NULL")){
        ChangePreNameForDel(father,original,newkey);
    }
    for(int i = 0; i < KeyNum; i++){
        if(tempkey[i] != original){
            out << tempkey[i] << " " << tempfilename[i] <<  " ";
        }
        else out << newkey << " " << tempfilename[i] << " ";
    }
    return 0;
}

template<typename T1>
bool BPlusTree<T1>::SaveHead(){
    string Previous = string("Head");
    string Add = string(".dat");
    FILE * fp;
    fp = fopen((Previous+TableName+Add).c_str(),"wb");
    int k;
    k = TypeList.size();
    fwrite(&k,sizeof(k),1,fp);
    for(int i = 0; i < TypeList.size(); i++){
        fwrite(&TypeList[i],sizeof(TypeList[i]),1,fp);
    }
    fwrite(&NodeNum,sizeof(NodeNum),1,fp);
    k = RootName.capacity()+1;
    fwrite(&k,sizeof(k),1,fp);
    fwrite(RootName.c_str(),sizeof(char)*k,1,fp);
    k = TableName.capacity()+1;
    fwrite(&k,sizeof(k),1,fp);
    fwrite(TableName.c_str(),sizeof(char)*k,1,fp);
    fclose(fp);
}

template<typename T1>
bool BPlusTree<T1>::ReadHead(){
    string Previous = string("Head");
    string Add = string(".dat");
    FILE * fp;
    fp = fopen((Previous+TableName+Add).c_str(),"rb");
    int num;
    fread(&num,sizeof(num),1,fp);
    for(int i = 0; i < num; i++){
        short temp;
        fread(&temp,sizeof(temp),1,fp);
        TypeList.push_back(temp);
    }
    fread(&NodeNum,sizeof(NodeNum),1,fp);
    int k;
    char RName[150];
    fread(&k,sizeof(k),1,fp);
    fread(RName,sizeof(char)*k,1,fp);
    char TName[150];
    fread(&k,sizeof(k),1,fp);
    fread(TName,sizeof(char)*k,1,fp);
    RootName.assign(RName);
    TableName.assign(TName);
    fclose(fp);
    // cout << RootName << endl;
    // cout << TableName << endl;
    // cout << TypeList[0] << endl;
}

template<typename T1>
bool BPlusTree<T1>::Update(T1 Key, vector<Undecide>ve){
    string filename;
    Return3 result = Search(Key, RootName);
    if(result.Succ == 0)
        return 0;
    filename = result.filename;
    ifstream in;
    in.open(filename.c_str());
    int KeyNum;
    in >> KeyNum;
    bool IsLeaf;
    in >> IsLeaf;
    string father;
    in >> father;
    T1 tempkey[MAXNODE];
    vector<Undecide>v[MAXNODE];
    for(int i = 0; i < KeyNum; i++){
        in >> tempkey[i];
        Undecide tt;
        for(int j = 0; j < TypeList.size(); j++){
            if(TypeList[j] == 0) in >> tt.s;
            else if(TypeList[j] == 1) in >> tt.num;
            else if(TypeList[j] == 2) in >> tt.LL;
            else in >> tt.is;
            v[i].push_back(tt);
        }
    }
    in.close();
    ofstream out;
    out.open(filename.c_str());
    out << KeyNum << " ";
    out << IsLeaf << " ";
    out << father << " ";
    for(int i = 0; i < KeyNum; i++){
        if(tempkey[i] == Key){
            out << Key << " ";
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) out << ve[j].s << " ";
                else if(TypeList[j] == 1) out << ve[j].num << " ";
                else if(TypeList[j] == 2) out << ve[j].LL << " ";
                else out << ve[j].is << " ";
            }
            continue;
        }
        out <<  tempkey[i] << " ";
        for(int j = 0; j < TypeList.size(); j++){
            if(TypeList[j] == 0) out << v[i][j].s << " ";
            else if(TypeList[j] == 1) out << v[i][j].num << " ";
            else if(TypeList[j] == 2) out << v[i][j].LL << " ";
            else out << v[i][j].is << " ";
        }
    }
    out.close();
}

template<typename T1>
vector<pair< T1,vector<Undecide> > > BPlusTree<T1>:: AllLeaf(){
    vector<pair<  T1,vector<Undecide>  > > all;
    string datstring = string(".dat");
    ifstream in;
    for(int i = 0; i < NodeNum; i++){
        string newname = TableName+TransIntToString(i)+datstring;
        in.open(newname.c_str());
        if(!in)continue;
        int KeyNum;
        bool IsLeaf;
        string father;
        in >> KeyNum;
        in >> IsLeaf;
        in >> father;
        if(IsLeaf == false){
            in.close();
            continue;
        }
        for(int i = 0; i < KeyNum; i++){
            T1 kk;
            in >> kk;
            vector<Undecide>v;
            Undecide tt;
            for(int j = 0; j < TypeList.size(); j++){
                if(TypeList[j] == 0) in >> tt.s;
                else if(TypeList[j] == 1) in >> tt.num;
                else if(TypeList[j] == 2) in >> tt.LL;
                else in >> tt.is;
                v.push_back(tt);
            }
            all.push_back(make_pair(kk,v));
        }
        in.close();
    }
    return all;
}

int main(){
    BPlusTree<int> test;//新建一个对象
    test.BuildTree("test");//表的名字为test
    vector<short>testv;//表的属性列
    //0->string  1->int  2->longlong  3->bool
    testv.push_back(0);	//第一个属性是string类型
    testv.push_back(1); //第二个属性是int类型
    test.SetTable(testv);//使用testv设置表的属性列
    for(int i = 19; i >0; i-=2){
        vector<Undecide>vv;
        Undecide te;
        strcpy(te.s,"testing_string");
        Undecide te2;
        te2.num = 1;
        vv.push_back(te);
        vv.push_back(te2);
        test.Insert(i,vv);	//插入一个key  对应的参数是vv
    }
    for(int i = 0; i <= 20; i+=2){
        vector<Undecide>vv;
        Undecide te;
        strcpy(te.s,"testing_string");
        Undecide te2;
        te2.num = 2;
        vv.push_back(te);
        vv.push_back(te2);
        test.Insert(i,vv);
    }
    Return3 a = test.Search(5,test.GetRootName()); //查找key=5的项
    //cout << a.Succ << " " << a.filename << " " << a.ve[0].s << endl;//输出查找的结果
    Return3 b = test.Search(27,test.GetRootName());
    //cout << b.Succ << " " << b.filename << endl;
    vector<Undecide>vv;
    Undecide te;
    strcpy(te.s,"******");
    Undecide te2;
    te2.num = 3;
    vv.push_back(te);
    vv.push_back(te2);
    test.Update(7,vv);//更新key=7的元组，更新的属性存在vv中
    test.Update(8,vv);
    test.Update(18,vv);
    test.Delete(3);
    //遍历所有的元组，得到一个vector，里面的元素是一个个pair，pair的first中存key,second中存这个元组的属性vector
    vector<pair< int,vector<Undecide> > > all;
    all = test.AllLeaf();
    for(int i = 0; i < all.size(); i++){
        cout << all[i].first << (all[i].second)[0].s << (all[i].second)[1].num<<endl;
    }
    test.SaveHead();//保存树的信息
     /*读取test这个树的方法
        BPlusTree<int> a;
        a.BuildTree("test");
        a.ReadHead();*/
}

// int main1(){
// 	BPlusTree<int> test;
// 	test.BuildTree("test");
// 	test.ReadHead();
// 	Return3 a = test.Search(5,test.GetRootName());
// 	cout << a.Succ << " " << a.filename << endl;
// 	Return3 b = test.Search(27,test.GetRootName());
// 	cout << b.Succ << " " << b.filename << endl;
// 	test.Delete(3);
// }
