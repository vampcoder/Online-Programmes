#include<iostream>
#include<cstdio>
#define N 100000007

using namespace std;

int n;
int cv[102];
long long int dp[10001];
long long int func(int k){
	dp[0] = 1;
	for(int i = 1; i <= k; i++)
		dp[i] = 0;
	for(int i = 0; i < n; i++)
		for(int j = 1; j <= k; j++)
			if(j >= cv[i])
				dp[j] = (dp[j]+dp[j-cv[i]])%N;
	return dp[k];
}
int main()
{
	int t, k;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d%d", &n, &k);
		for(int j = 0; j < n; j++)
			scanf("%d", &cv[j]);
		printf("Case %d: %lld\n",i, func(k));
	}
}
