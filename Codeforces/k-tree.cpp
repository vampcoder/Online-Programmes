#include<iostream>
#include<cstdio>

using namespace std;
int d, k;
long long int dp[107][2];
long long int rec(int n, bool inc){
	if(n == 0 && inc)
		return 1;
	if(n <= 0)
		return 0;
	if(inc && dp[n][0] != -1)
		return dp[n][0];
	if(!inc && dp[n][1] != -1)
		return dp[n][1];
	long long int total = 0;
	for(int i = 1; i <= k; i++) {
		if(i >= d){
			total += rec(n-i, true);
		}else{
			total += rec(n-i, inc);
		}
	}
	total = total % 1000000007;
	if(inc)
		dp[n][0] = total;
	else
		dp[n][1] = total;
	return total;
}
int main()
{
	int n;
	scanf("%d%d%d", &n, &k, &d);
	for(int i = 0; i <= n; i++){
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	cout <<rec(n, false)<<endl;
}
