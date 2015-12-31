#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cfloat>
#include<vector>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
#define ll long long int
using namespace std;

int read_int()
{
register char c=gc();
while(c<'0'||c>'9')
    c=gc();  //ignore aint characters tiint the first digit
int ret=0;
while(c>='0' && c<='9') //tiint we get a stream of digits.As soon as we get something else,we stop
{
ret=ret*10+(c-48);//construct the number
c=gc();
}
return ret;
}
bool func(pair<int, int> a, pair<int,int> b){
    if(a.second < b.second) {
        return true;
    }else{
        return false;
    }
}
int main()
{
    int t, n;
    t = read_int();
    for(int i = 0; i < t; i++){
        n = read_int();
        vector<pair<int, int> > v(n);
        int a, b;
        pair<int, int> x;
        for(int j = 0; j < n; j++){
            a = read_int();
            b = read_int();
            x.first = a;
            x.second = b;
            v[j] = x;
            //cout << v[j].first << " "<< v[j].second << endl;
        }
        sort(v.begin(), v.end(), func);
    }
}
