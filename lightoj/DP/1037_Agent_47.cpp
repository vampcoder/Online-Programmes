#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int n;
int arr[15];
int damage[15][15];
ll dp[1 << 15];

ll func(int bitmask){

    int count = 0;
    for(int i = 0; i < n; i++){
        int num = 1 << i;
        //cout << (num&bitmask) << endl;
        if((num&bitmask) != 0)
            count++;
    }
    if(count == n){
        return 0;
    }
    if(dp[bitmask] != -1)
        return dp[bitmask];

    ll ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int num = 1 << i;
        if((num & bitmask) == 0){
            int newmask = (bitmask|num);
            int dam = arr[i];
            int power = 0;
            for(int j = 0; j < n; j++){
                if((bitmask &(1 << j)) != 0){
                    power = max(power, damage[j][i]);
                }
            }
            int cnt = arr[i];
            if(power != 0){
                cnt = dam/power;
                if(dam % power != 0)
                    cnt++;
            }
            ans = min(ans, cnt + func(newmask));
        }
    }
    return dp[bitmask]=ans;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[j]);
        char str[16];
        for(int j = 0; j < n; j++){
            scanf("%s", &str);
            for(int k = 0; k < n; k++){
                damage[j][k] = str[k]-'0';
            }
        }
        memset(dp, -1, sizeof dp);
        ll ans = INT_MAX;
        for(int j = 0; j < n; j++){
            ans = min(ans, arr[j] + func((1 << j)));
        }
        printf("Case %d: %lld\n", i+1, ans);
    }
}
