#include<bits/stdc++.h>

using namespace std;
long long dp[1001][15001];
int k;
#define N 100000007

long long rec(int n, int s){
	if(s < 0){	
		return 0;
	}
	if(s == 0){
		if(n == 0){
				dp[n][s] = 1;
				return 1;
		}else{
				dp[n][s] = 0;
				return 0;
		}
	}
	if(n == 0)
			if(s != 0)
					return 0;


	if(dp[n][s] != -1)
			return dp[n][s];

	long long  ret = 0;
	
	for(int i = 0; i < k; i++){
		ret = (ret + (rec(n-1, s-i-1)))%N;
	}
	
	dp[n][s] = ret%N;
	
	return ret%N;
}

int main()
{
	int t, n, s;
	cin >> t;
	for(int i = 1; i <= t; i++){
		for(int j = 0; j < 1001; j++)
				for(int l = 0; l < 15001; l++)
						dp[j][l] = -1;
		cin >> n >> k >> s;
		cout << rec(n, s)%N;

	}
}
