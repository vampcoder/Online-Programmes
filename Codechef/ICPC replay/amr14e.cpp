#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
using namespace std;

long long int read_int() {
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
    long long int t = read_int();
    int i = 0;
    long long int a[30];
    long long int p = pow(2,30);
    //cout << p<< endl;
    while(t > 1){
        if(t >= p){
            a[i++] = p;
      //      cout << p << " " << t <<" "<<endl;
            t = t%p;
            p = p/2;
        }else{
            p = p/2;
        }
    }
    for(int j = i-1; j >=0; j--){
        printf("%lld ", a[j]);
    }
}
