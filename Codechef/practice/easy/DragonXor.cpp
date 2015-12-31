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
int count1(int x){
    int i = 0;
    while(x > 0){
        i = i+(x%2);
        x /= 2;
    }
    return i;
}
int num(int x){
    int i = 1;
    x--;
    while(x--){
        i = (2*i+1);
    }
    return i;
}
int main() {
    int t = read_int();
    double x =16.0;
    printf("%d\n", x);
    while(t--){
        int a = read_int();
        int b = read_int();
        int c = read_int();
        int cntc1 = count1(b), cntc2 = count1(c);
        cout << cntc1 << " " << a-cntc2 << endl;
        if(a <= max(cntc1+a-cntc2, cntc2+a-cntc1)){
            printf("%d\n", num(a));
        }else{
            int num1 = num(max(cntc1+a-cntc2, cntc2+a-cntc1));
            cout << num1 << endl;
            cout << pow(2, a-max((cntc1+a-cntc2), (cntc2+a-cntc1))) << endl;
            printf("%d\n", num1*(int)pow(2, a-max((cntc1+a-cntc2), (cntc2+a-cntc1))));
        }
    }
}
