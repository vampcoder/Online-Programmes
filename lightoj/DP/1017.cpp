#include<bits/stdc++.h>

using namespace std;

int n, w, k, x, y;
int p[110];
int dp[110][110];

int rec(int start, int krem){
	if(start >= n || !krem)
		return 0;	
	if(dp[start][krem] != -1)
		return dp[start][krem];
		
	int end = p[start]+w;
	int ans = 0, i;

	for(i = start; i < n && p[i] <= end; i++){
		ans++;
	}	
	ans += rec(i, krem-1);
	int ret = rec(start+1, krem);

	ans = max(ans, ret);

	return dp[start][krem] = ans;	
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n >> w >> k;
		for(int j = 0; j < n; j++){
			cin >> x >> y;
			p[j] = y;		
		}
		memset(dp, -1, sizeof(dp));
		sort(p, p+n);
		cout << "Case " << i << ": " << rec(0, k) << endl;
	}
}
