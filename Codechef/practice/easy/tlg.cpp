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

int read_int()
{
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
int main()
{
    int n;
    int x, y, a = 0, b = 0;
    int l = 0;
    int p = 1;
    n = read_int();
    for(int i = 0 ; i < n; i++){
        x = read_int();
        y = read_int();
        x += a;
        y += b;
        if(x>y && (x-y) > l){
            l = x-y;
            p = 1;
        }else if(x < y && (y-x) > l){
            l = y-x;
            p = 2;
        }
        a = x;
        b = y;
    }
    printf("%d %d", p, l);
}
