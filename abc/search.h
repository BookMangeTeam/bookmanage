#ifndef SEARCH_H
#define SEARCH_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <iostream>
using namespace std;
int Sco_Ch(string a, string b){
    // return 0;
    int total = 0;
    int len = b.size();
    if(len == 0)return len;
    int num = len /3;
    int num_3 = num/3;
    int num_2 = num/2;
    if(num_2 != 0){
        if(a.find(b.substr(0,num_2*3)) != a.npos){
            total += num_2;
        }
        if(a.find(b.substr((num-num_2)*3)) != a.npos){
            total += num_2;
        }
    }
    if(num_3 != 0){
        if(a.find(b.substr(0,num_3*3)) != a.npos){
            total += num_3;
        }
        if(a.find(b.substr(num_3*3,num_3*3)) != a.npos){
            total += num_3;
        }
        if(a.find(b.substr((num-num_3)*3)) != a.npos){
            total += num_3;
        }
    }
    if(a.find(b) != a.npos){
        total += num;
    }
    return total;
}

int Sco_Eng(string a, string b){
    int total = 0;
    int len = b.size();
    if(len == 0)return total;
    int len_3 = len/3;
    int len_2 = len/2;
    if(len_2 != 0){
        if(a.find(b.substr(0,len_2)) != a.npos){
            total += len_2;
        }
        if(a.find(b.substr(len-len_2)) != a.npos){
            total += len_2;
        }
    }
    if(len_3 != 0){
        if(a.find(b.substr(0,len_3)) != a.npos){
            total += len_3;
        }
        if(a.find(b.substr(len_3,len_3)) != a.npos){
            total += len_3;
        }
        if(a.find(b.substr(len-len_3)) != a.npos){
            total += len_3;
        }
    }
    if(a.find(b) != a.npos){
        total += len;
    }
    return total;
}

int Score(string a, string b){
    int len = b.size();
    string b_ch;
    string b_eng;
    for(int i = 0; i < len; i++){
        if(b[i] >= 0 && b[i] <= 127){
            b_eng += b[i];
        }
        else{
            b_ch += b.substr(i,3);
            i += 2;
        }
    }
    return Sco_Eng(a,b_eng)+Sco_Ch(a,b_ch);
}
#endif // SEARCH_H
