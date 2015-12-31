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

long long int read_int()
{
register char c=gc();
while(c<'0'||c>'9')
    c=gc();  //ignore aint characters tiint the first digit
long long int ret=0;
while(c>='0' && c<='9') //tiint we get a stream of digits.As soon as we get something else,we stop
{
ret=ret*10+(c-48);//construct the number
c=gc();
}
return ret;
}
int calculate(long long int a, long long int b){
    int p = ceil(log2(a)/log2(b));
    long long int x = pow(b, p);
    //cout<< p << " " << x << endl;
    int count = 0;
    for(int i = 0; i < p; i++){
        if(a >= x){
            count += a/x;
            //cout << a << " "<< x << endl;
            a = a%x;
        }
        if(x > a){
            x /= b;
        }
    }
    if(a < b){
        count+= a;
    }
    return count;
}
int main()
{
    long long int t, n, k;
    t = read_int();
    while(t--){
        n = read_int();
        k = read_int();
        if(k == 1){
            printf("%lld\n", n);
        }else{
            printf("%d\n", calculate(n, k));
        }
    }
}
