#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[3][20];
ll a[3][20];
int n;

ll ret(int last, int idx){
	
	if(idx >= n)
		return 0;
	if(last != -1)
		if(dp[last][idx] != -1)
			return dp[last][idx];
	ll ans = LLONG_MAX;
	for(int i = 0; i < 3; i++){
		if(i != last){
			ans = min(ans, a[i][idx]+ ret(i, idx+1));
		}
	}	
	if(last != -1)
		dp[last][idx] = ans;
	return ans;
}
int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for(int j = 0; j < n; j++)
			cin >> a[0][j] >> a[1][j] >> a[2][j];

		cout << "Case " << i << ": " << ret(-1, 0) << endl;
	}

}
