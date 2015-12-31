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
int dp[207][207];
int calc(int arr[207][207], int i, int j, int N, int n){
    if(i > n || j > N || arr[i][j] == 0){
        return 0;
    }
    //cout << arr[i][j] << " ";
    if(dp[i][j] == 0){
    int l = arr[i][j]+calc(arr, i+1, j, N, n);
    int r = arr[i][j]+calc(arr, i+1, j+1, N, n);
    if(l > r){
        //cout << i+1 << " " << j << endl;
        dp[i][j] = l;
        return l;
    }else{
        //cout << i+1 << " " << j+1 << endl;
        dp[i][j] = r;
        return r;
    }
    }else{
        return dp[i][j];
    }
}
int main(){
    int t,N, n;
    t = read_int();
    for(int i = 1; i <= t; i++){
        N = read_int();
        n = 2*N-1;
        int l = 0;
        int arr[207][207] = {0};
        for(int j = 0; j < N; j++)
            for(int k = 0; k <= j; k++){
                arr[j][k] =read_int();
                dp[j][k] = 0;
            }
        for(int j = N; j < n; j++){
            for(int k = 0 ; k < N; k++)
                if(k > l){
                    arr[j][k] = read_int();
                    dp[j][k] = 0;
                }
            l++;
        }
        /*for(int j = 0; j < n; j++){
            for(int k = 0; k < N; k++)
                cout << dp[j][k] << " ";
            cout << endl;
        }*/
        printf("Case %d: %d\n", i, calc(arr, 0, 0, N, n));
    }
}
