#include<bits/stdc++.h>

using namespace std;

char a[55], b[55], c[55];
int dp[55][55][55];

int func(int i, int j, int k){
    if(i < 0 || j < 0 || k < 0)
        return 0;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    int ans = 0;
    if(a[i] == b[j] && b[j] == c[k]){
        ans = 1+ func(i-1, j-1, k-1);
    }else{
        ans = max(func(i-1, j, k), max(func(i, j-1, k), func(i, j, k-1)));
    }
    return dp[i][j][k]=ans;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(dp, -1, sizeof dp);
        scanf("%s%s%s", &a, &b, &c);
        int l = strlen(a);
        int m = strlen(b);
        int n = strlen(c);
        printf("Case %d: %d\n", i+1, func(l-1, m-1, n-1));
        //cout << "Case " << i+1 << ": " << func(l-1, m-1, n-1) << endl;
    }
}
