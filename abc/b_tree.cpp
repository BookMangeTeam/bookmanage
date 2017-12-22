#include <b_plus_tree.h>

void ReadData(string filename){

    srand( (unsigned)time( NULL ) );

    BPlusTree<string> BookA;
    BookA.SetTableName("BookA");
    BookA.ReadHead();


    BPlusTree<string> BookB;
    BookB.SetTableName("BookB");
    BookB.ReadHead();


    ifstream in(filename);
    char temp1[1024];
    int ll = 0;
    for(int i = 0; i < 9000; i++){
    // while(!in.eof()){
        if(ll <= 6000 &&ll%1000 == 0){
            cout << ll << endl;
        }
        // cout << ll << endl;
        ll++;
        // cout << " ************* " << endl;
        in.getline(temp1,sizeof(temp1));
        if(strlen(temp1) == 0){
            cout << ll << endl;
            // cout << temp1 << endl;
            break;
        }
         // cout << temp1 << endl;
        // cout << temp1 << endl;
        string author;
        in >> author;
        string factory;
        in >> factory;
        string date;
        in >> date;
        string price;
        in >> price;
        string ISBN;
        in >> ISBN;
        char temp2[20];
        in.getline(temp2,sizeof(temp2));
         // cout << author << " " << factory << " " << date << " " << price << " " << ISBN << endl;
        if(strlen(temp1) > 480)continue;
        vector<Undecide> vv;
        Undecide tt0;
        strcpy(tt0.s,temp1);
        Undecide tt1;
        strcpy(tt1.s,author.c_str());
        Undecide tt2;
        strcpy(tt2.s,factory.c_str());
        Undecide tt3;
        strcpy(tt3.s,date.c_str());
        Undecide tt4;
        strcpy(tt4.s,price.c_str());
        vv.push_back(tt0);
        vv.push_back(tt1);
        vv.push_back(tt2);
        vv.push_back(tt3);
        vv.push_back(tt4);
        BookB.Insert(ISBN,vv);

        vector<Undecide> vv2;
        Undecide ttt0;
        strcpy(ttt0.s,"NULL");
        Undecide ttt1;
        strcpy(ttt1.s,"NULL");
        Undecide ttt2;
        ttt2.num = 0;
        Undecide ttt3;
        ttt3.num = 0;
        Undecide ttt4;
        strcpy(ttt4.s,ISBN.c_str());
        vv2.push_back(ttt0);
        vv2.push_back(ttt1);
        vv2.push_back(ttt2);
        vv2.push_back(ttt3);
        vv2.push_back(ttt4);
        // int BookNum = rand()%15;
        int BookNum = 3;
        for(int j = 0; j < BookNum; j++){
            string Key;
            if(j < 10)
                Key = ISBN + string("00") + BookA.TransIntToString(j);
            else
                Key = ISBN + string("0") + BookA.TransIntToString(j);
            BookA.Insert(Key,vv2);
            // cout << Key << " " << vv2[0].s << " " <<  vv2[1].s << " " <<  vv2[2].num << " " <<  vv2[3].num << " " << vv2[4].s << endl;
        }
    }
    cout << "!!!";
    BookA.SaveHead();
    BookB.SaveHead();
    return;
}
