#include<bits/stdc++.h>

using namespace std;
string s1, s2;
int dp[110][110];
string ans[110][110];

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(dp, -1, sizeof dp);
        cin >> s1 >> s2;
        int l, m;
        l = s1.length();
        m = s2.length();

        for(int j = 0; j <= l; j++){
            for(int k = 0; k <= m; k++){
                if(j == 0 || k == 0){
                    dp[j][k] = 0;
                    ans[j][k] = "";
                }else if(s1[j-1] == s2[k-1]){
                    dp[j][k] = dp[j-1][k-1] + 1;
                    ans[j][k] = ans[j-1][k-1] + s1[j-1];
                }else if(dp[j-1][k] < dp[j][k-1]){
                    dp[j][k] = dp[j][k-1];
                    ans[j][k] = ans[j][k-1];
                }else if(dp[j-1][k] > dp[j][k-1]){
                    dp[j][k] = dp[j-1][k];
                    ans[j][k] = ans[j-1][k];
                }else{
                    dp[j][k] = dp[j-1][k];
                    ans[j][k] = min(ans[j-1][k], ans[j][k-1]);
                }
            }
        }
        cout << "Case " << i+1 << ": ";
        if(dp[l][m] == 0){
            cout << ":(" << endl;
            continue;
        }
        cout << ans[l][m] << endl;

    }
}
