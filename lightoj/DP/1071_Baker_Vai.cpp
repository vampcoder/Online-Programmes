//Idea from https://lbv-pc.blogspot.in/2012/07/baker-vai.html

#include<bits/stdc++.h>
using namespace std;



int dp[105][105][105][3];
int m, n;
int arr[105][105];

int func(int row, int c1, int c2, int turn){
    if(row == m-1 && c1 == n-2 && c2 == n-1){
        return 0;
    }
    int &ans = dp[row][c1][c2][turn];
    if(ans != -1)
        return ans;

    if(turn == 0){
        if(c1 + 1 < c2){
            ans = max(ans, arr[row][c1+1]+ func(row, c1+1, c2, 0));
        }
        ans = max(ans, func(row, c1, c2, 1));
    }
    if(turn == 1){
        if(c2+1 < n){
            ans = max(ans, arr[row][c2+1]+ func(row, c1, c2+1, 1));
        }
        if(c1 < c2)
            ans = max(ans, func(row, c1, c2, 2));
    }
    if(turn == 2){
        if(c1< c2 && row+1 < m){
            ans = max(ans, arr[row+1][c1] + arr[row+1][c2] + func(row+1, c1, c2, 0));
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>  t;
    for(int i = 0; i < t; i++){
        memset(dp, -1, sizeof dp);
        cin >> m >> n;
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                cin >>arr[j][k];
            }
        }
        cout << "Case "<< i+1 << ": " << arr[0][0]+ func(0, 0, 0, 1) << endl;
    }
}
