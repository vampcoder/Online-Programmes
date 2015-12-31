#include<iostream>
#include<cstdio>
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
    n = read_int();
    int x = 0;
    int y = 0;
    int a[n];
    int b[n-1];
    int k = 0;
    int p = 0;
    for(int i = 0; i < n; i++){
        a[i] = read_int();
        if(i > 0){
            b[k] = a[i] - a[i-1];
            if(x > b[k]){
                x = b[k];
            }
            k++;
        }
    }
    k = 0;
    for(int i = 0; i < n-2; i++){
        if(b[i] + b[i+1] < x){
            k = 1;
        } else {
            if(p > b[i]+b[i+1]){
                p = b[i]+b[i+1];
            }
        }
    }
    if(k == 1){
        printf("%d\n", x);
    }else {
        printf("%d\n", p);
    }

    return 0;
}
