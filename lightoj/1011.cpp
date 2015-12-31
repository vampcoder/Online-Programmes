#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int n;
int a[20][20];
int dp[65536][17];
int func(int mask, int rem){
	if(rem < 0){
		return 0;
	}
	if(dp[mask][rem] != -1)
		return dp[mask][rem];
	int x = 0;
	for(int i = 0; i < n; i++){
		if((1 << i) & mask)continue;
		else{
			x = max(x, a[rem][i] + func(mask |(1 << i), rem -1));
		}
	}
	dp[mask][rem] = x;
	return x;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				scanf("%d", &a[j][k]);
			}	
		}
		for(int j = 0; j < 65536; j++)
			for(int k = 0; k < 17; k++)
				dp[j][k] = -1;
		printf("Case %d: %d\n", i, func(0, n-1));
	}
}
