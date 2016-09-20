#include<bits/stdc++.h>

using namespace std;
int R, B;
long double dp[510][510][2];
//turn = 0 (your turn) = 1(Jim's turn)
long double func(int r, int bl, bool turn){
   if(r == 0 && bl == 1)
            return 1.0;

    if(bl == 0){
        return 0;
    }
    long double &ans = dp[r][bl][turn];
    if(ans > -0.5){
        return ans;
    }
    ans = 0.0;
    long double a = r*1.0;
    long double b = bl*1.0;
    if(turn){
            ans += func(r, bl-1, false);
    }else{
        if(r > 0)
            ans += a/(a+b) *func(r-1, bl, true);
        ans += b/(a+b)*func(r, bl-1, true);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> R >> B;
        cout << "Case " << i+1 << ": " << std::setprecision(10) << func(R, B, 0) << endl;
    }
}
