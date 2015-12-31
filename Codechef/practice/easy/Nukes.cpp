#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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

long long int read_int1() {
    register char c=gc();
    while(c<'0'||c>'9')
        c=gc();  //ignore all characters till the first digit
    long long int ret=0;
    while(c>='0' && c<='9') //till we get a stream of digits.As soon as we get something else,we stop
    {
    ret=ret*10+(c-48);//construct the number
    c=gc();
    }
    return ret;
}
int main() {
   long long int a = read_int1();
   long long int n = read_int1(), k = read_int1(), p;
   int modu;
   p = k;
   if(n < 1){
   while(p-- > 1){
        if(n == 0){
            printf("0 ");
        }else if(n == 1){
           modu = 1;
            a -= n;
            if(a > 0){
                printf("%d ", modu);
            }else{
                printf("0 ");
            }
        }
   }
   }
   if(n == 0){
        printf("0\n");
   }if(n == 1){
       modu = 1;
        a -= n;
        if(a > 0){
            printf("%d\n", modu);
        }else{
            printf("0\n");
        }
    }
    n++;
    p = k;
    while(p-- > 1 || a > 0){
        if(n > 2){
            modu = a%n;
            if(a > 0){
                printf("%d ", modu);
            }else{
                printf("0 ");
            }
            a /= n;
        }
    }
    if(n > 2){
        modu = a%n;
        if(a > 0){
            printf("%d\n", modu);
        }else{
            printf("0\n");
        }
        a /= n;
    }
}
