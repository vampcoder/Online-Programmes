#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
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

struct arr{
    int x;
    int div;
};

bool cmpc(struct arr x, struct arr y){
    if(x.div < y.div)
        return true;
    else if(x.div == y.div){
        if(x.x > y.x)
            return true;
        else
            false;
    }else
        return false;
}
int main(){
    int t,n,x,y,z;
    t = read_int();
    for(int i = 1; i <= t; i++){
        int dp[1000][2]={0};
        n = read_int();
        x = read_int();
        y = read_int();
        z = read_int();
        int lm = 0;
        int m = x+y;
        dp[n/2][0] = m;
        dp[n/2][1] = m;
        for(int i = n/2; i >0; i--){
            dp[i-1][0] = m + x +y;
            dp[i-1][1] = m + z-(x/2);
            m = max(dp[i][0], dp[i][1]);
            if(m > lm){
                lm = m;
            }
        }
        m = x+y;
        for(int i = (n/2)+1; i < n; i++){
            dp[i][0] = m + x +y;
            dp[i][1] = m + z-(x/2);
            m = max(dp[i][0], dp[i][1]);
            if( m > lm){
                lm = m;
            }
        }
        for(int i = 0; i < n; i++){
            cout << dp[i][0] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << dp[i][1] << " ";
        }
        cout << lm << endl;
    }
}
