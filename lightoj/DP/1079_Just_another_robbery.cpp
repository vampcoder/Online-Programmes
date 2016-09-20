#include<bits/stdc++.h>

using namespace std;

long double dp[10010][110];
int M[110];
long double P[110];
int n;
long double p;
bool visited[110];
long double func(int m, int i){
    if(m == 0){
        return 0.0;
    }
    if(m < 0){
        return 0.0;
    }
    if(i >= n){
        return 1.0;
    }
    if(dp[m][i] > -1){
        return dp[m][i];
    }
    long double ans;
    ans = min(func(m, i+1), P[i] + (1-P[i])*func(m-M[i], i+1));

    return dp[m][i] = ans;
}

int solve(){
    int c = 0;
    for(int i = 0; i < n; i++){
        c += M[i];
    }
    //cout << func(c) << " " << p << endl;
    if(func(c, 0) < p){
        return c;
    }
    int l = 0;
    int r = c;

    int ans = 0;
    while(l <= r){
        //memset(dp, -1, sizeof dp);
        int mid = l + (r-l)/2;
        long double x = func(mid, 0);
        //cout << l << " " << r << " "  << mid << " " << x << endl;
        if(x < p){
            ans = max(ans, mid);
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(dp, -1, sizeof dp);
        scanf("%Lf%d", &p, &n);
        for(int j = 0; j < n; j++){
            scanf("%d%Lf", &M[j], &P[j]);
        }
        printf("Case %d: %d\n", i+1, solve());
    }

}
