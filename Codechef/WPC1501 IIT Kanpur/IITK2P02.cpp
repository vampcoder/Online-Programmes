#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cfloat>
#include<vector>
#include<cmath>
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
long long int power(int a, int b){
    if(b = 1){
        return a;
    }
    long long int x = power(a, b/2);
    x= (x*x)%1000000007;
    return x;
}
int main(){
int t = read_int();
while(t--){
    int n = read_int();
    int m = read_int();
    long long int x = m;
    if(n == 1){
        printf("%d\n", m);
    }else if(n ==2){
        x = x*(x-1);
        printf("%d\n", x%1000000007);
    }else{
        n = n-2;
        printf("%d\n", (x*(x-1)*power(m-2, n-2))%1000000007);
    }

    }
}
