#include<iostream>
#include<cstdio>
#define N 100000007
using namespace std;
int n;
int cn[52];
int cv[52];
long long int dp[101][1001];
long long int func(int i, int k){
	if(k == 0)
		return 1;
	if(k < 0 || i >= n){
		return 0;
	}
	if(dp[i][k] != -1)
		return dp[i][k];
	long long int x = 0;
	for(int j = 0; j <= cn[i]; j++){
		x += func(i+1, k-j*cv[i]);
		if(x >= N)
			x -= N;
	}
	dp[i][k] = x;
	return x;
}
int main()
{
	int t, k;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d%d", &n, &k);
		for(int j = 0; j < n; j++)
			scanf("%d", &cv[j]);
		for(int j = 0; j < n; j++)
			scanf("%d", &cn[j]);
		for(int j = 0; j <= n; j++)
			for(int m = 0; m <= k; m++)
				dp[j][m] = -1;
		printf("Case %d: %lld\n",i, func(0, k));
	}

}
