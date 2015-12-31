#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
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
long long int dp[31];
long long int calc(int n, int k){
    long long int x = dp[n]/dp[n-k];
    long long int y = x/dp[k];
    y=y*x;
    return y;
}
int main(){
    int t, n, k;
    long long int f = 1;
    dp[0] = 1;
    for(int i = 1; i <= 30; i++){
        dp[i] = (f * i)%100000000000000000;
        f = dp[i];
       // cout << dp[i] << " ";
    }
    t = read_int();
    for(int i = 1; i <= t; i++){
        n = read_int();
        k = read_int();
        if(k > n){
            printf("Case %d: %d\n", i, 0);
        }else{
            printf("Case %d: %lld\n", i, calc(n, k));
        }
    }
}
