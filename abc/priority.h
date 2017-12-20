#ifndef PRIORITY_H
#define PRIORITY_H


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#define INF 0x3fffffff
#define PI acos(-1)
#define MAXX 25000
#define MAXNODE 1500
using namespace std;
class BoScore{
public:
    BoScore(){}
    BoScore(string sr, int d):s(sr),score(d){}
    string s;
    int score;
    friend bool operator <(const BoScore a, const BoScore b){
        return (a.score < b.score);
    }
};

#endif // PRIORITY_H
