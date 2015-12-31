#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
using namespace std;

int read_int() {
    register char c=gc();
    while(c<'0'||c>'9')
        c=gc();  //ignore all characters till the first digit
    int ret=0;
    while(c>='0' && c<='9') //till we get a stream of digits.As soon as we get something else,we stop
    {
    ret=ret*10+(c-48);//construct the number
    c=gc();
    }
    return ret;
}
int main() {
    int t, a, b;
    t = read_int();
    while(t--) {
        a = read_int();
        b = read_int();
        int c[b];
        int cook[a];
        int chef[a];
        int k = 0, p = 0, r = 0, s = 0;
        for(int i = 0; i < b; i++){
            c[i] = read_int();
        }
        sort(c, c+b);
        for(int i = 1; i <= a; i++){
            if(c[p] == i){
                p++;
                continue;
            }else{
                if(r == 0){
                    chef[s++] = i;
                    r = 1;
                }else{
                    cook[k++] = i;
                    r = 0;
                }
            }
        }
        for(int i = 0; i < s-1; i++){
            printf("%d ", chef[i]);
        }
        if(s > 0){
            printf("%d\n", chef[s-1]);
        }
        for(int i = 0; i < k-1; i++){
            printf("%d ", cook[i]);
        }
        if(k >0){
            printf("%d\n", cook[k-1]);
        }
    }
}
