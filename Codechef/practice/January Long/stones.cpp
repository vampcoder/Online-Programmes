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

long long int read_int()
{
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
int main()
{
    long long int t, n, k, l, m;
    t = read_int();
    for(long long int i = 0; i < t; i++){
        n = read_int();
        k = read_int();
        m = 0;
        l = 0;
        long long int a[n+7];
        long long int b[n+7];
        for(long long int j = 0; j < n; j++){
            a[j] = read_int();
        }
        for(long long int j = 0; j < n; j++) {
            b[j] = read_int();
            l = k/a[j];
            l *= b[j];
            if(m < l){
                m = l;
            }
        }
        printf("%lld\n", m);
    }
}
