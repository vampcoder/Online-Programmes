#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

int n, t;
ll a[1010];
long long dp[1010][2];

ll ret(int i, int j){
	if(i >= n)
		return 0;
	if(i != -1 && dp[i][j] != -1)
		return dp[i][j];	

	ll ans = 0;
	for(int k = i+2; k < n; k++){
		if(j == 1 && k == n-1) 
			continue;
		ans = max(ans, a[k] + ret(k, j));
	}
	if(i != -1)
		dp[i][j] = ans;
	return ans;
}

int main()
{
	cin >> t;
	for(int i = 1; i <= t; i++){
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << "Case " << i << ": " << max(ret(-1, 0) , a[0] + ret(0, 1)) << endl;
			
	}
}
