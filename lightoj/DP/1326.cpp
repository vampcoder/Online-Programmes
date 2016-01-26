#include<bits/stdc++.h>

using namespace std;

#define mod 10056

int n,t;
int fact[1010];
int dp[1010][1010];
int ans[1010];

int func(int x){
	for(int i = 0; i <= x; i++){
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for(int i = 2; i <= x; i++){
		for(int k = 1; k < i; k++){
			dp[i][k] = (dp[i-1][k]+dp[i-1][k-1])%mod;	
		}
	}
}

void func1(void){
	ans[0] = ans[1] = 1;
	for(int i = 1; i <= 1000; i++){
		ans[i] = 0;
		for(int j = 1; j <= i; j++){
			ans[i] = (ans[i] + dp[i][j]*ans[i-j])%mod;
		}				
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	memset(ans, 0, sizeof(ans));
	func(1002);
/*	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 7; j++)
			cout << dp[i][j] <<" ";
		cout << endl;
	}	
*/
	cin >> t;
	fact[0] = 1;
	
	fact[1] = 1;
	for(int i = 2; i < 1010; i++){
		fact[i] = i*fact[i-1];
		if(fact[i] > mod)
			fact[i] = fact[i]%mod;
	}	
	func1();
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		cout << "Case " << i << ": " << ans[n] << endl;
	}			
}
