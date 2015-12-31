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
    int t;
    t = read_int();
    while(t--){
        int n = read_int();
        long long int c = read_int1();
        int a;
        while(n--){
            a = read_int();
            c -= a;
        }
        if(c < 0){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
}
