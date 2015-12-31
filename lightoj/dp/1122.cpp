#include<iostream>
#include<cstdlib>

using namespace std;

int m;
int a[11];
int dp[11][11];
int func(int n, int last){
	if(n <= 0){
		dp[n][last] = 1;
		return 1;
	}
	if(dp[n][last] != -1)
		return dp[n][last];
	int ret = 0;
	for(int i = 0; i < m; i++){
		if(abs(a[i] - last) <= 2)
			ret +=  func(n-1, a[i]);
	}
	dp[n][last] = ret;
	return ret;
}
int main()
{
	int t, n;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> m >> n;
		for(int j = 0; j < m; j++)
			cin >> a[j];
		for(int j = 0; j <= 10; j++)
			for(int k = 0; k <= 10; k++)
				dp[j][k] = -1;
		int ret = 0;
		for(int j = 0; j < m; j++)
			ret += func(n-1, a[j]);	
		cout << "Case " << i << ": " << ret << endl;
	}	
}
