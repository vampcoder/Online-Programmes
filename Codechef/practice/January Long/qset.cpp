#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cfloat>
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
int main(){
    int n, m, type, c, d;
    n = read_int();
    m = read_int();
    int ch;
    char a[n+7];
    int b[n+7];
    int x[n+7];
    int e[n + 7][n + 7];
    for(int i = 0; i < n; i++){
        a[i] = gc() - 48;
        b[i] = a[i] % 3;
    }
    int r = 0;
    for(int i = 0; i < m; i++){
        type = read_int();
        c = read_int()-1;
        d = read_int()-1;
        if(type == 1){
            ch = b[c];
            b[c] = b[d];
            b[d] = ch;
            r = 0;
        }
        int p = 0;
        if(type == 2){
            if(r == 0){
                for(int j = n-1; j >= 0; j--){
                    p = 0;
                    for(int k = j; k < n; k++) {
                        p += b[k];
                        if(k == j){
                        if(b[j] == 0){
                            e[j][j] = 1;
                        }else{
                            e[j][j] = 0;
                        }
                        }else{
                            if(p%3 == 0){
                                e[j][k] = 1 + e[j+1][k] + e[j][k-1];
                            } else{
                                e[j][k] = e[j+1][k] + e[j][k-1];
                            }
                        }
                    }
                }
                r = 1;
            }
            printf("%d\n", e[c][d]);
        }
    }
}
