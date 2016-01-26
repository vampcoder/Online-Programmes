#include<bits/stdc++.h>

using namespace std;

int t, n;
int a[100];
int summation[101];
int dp[101][101];

int rec(int i, int j){
	if(i > j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int sum = 0;
	int ans = INT_MIN;
	for(int k = i; k <= j; k++){
		sum = summation[k]- summation[i-1];
		int temp = rec(k+1, j);
		temp = summation[j]-summation[k]- temp;
		if (ans < sum+temp)
			ans = sum+temp;
	}
	sum = 0;
	for(int k = j; k >= i; k--){
		sum =  summation[j] - summation[k-1];
		int temp = rec(i, k-1);
		temp = summation[k-1] - temp;
		if(i > 0)
			temp -= summation[i-1];
		if(ans < sum+temp)
			ans = sum+temp;
	}
	return dp[i][j] = ans;
}

int main()
{
	cin >> t;
	for(int i = 1; i <= t; i++){		
		memset(dp, -1, sizeof(dp));
		scanf("%d",  &n);
		for(int j = 0; j < n; j++){
			scanf("%d", &a[j]);
		}
		summation[0] = a[0];
		for(int j = 1; j < n; j++)
			summation[j] = summation[j-1] + a[j];
		printf("Case %d: %d\n", i, 2*rec(0, n-1)-summation[n-1]);
	}
}
