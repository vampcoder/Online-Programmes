#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int x;
long long dp[151][26];
long long func(int sum, int n){
	if(n <= 0 ||sum >= x){
		if(sum < x){
			return 1;	
		}else{	
			return 0;
		}
	}
//	if (sum >= x)
//		return 0;
	if(dp[sum][n] != -1)
		return dp[sum][n];
	long long  ret = 0;
	for(int i = 1; i <= 6; i++){
		ret += func(sum+i, n-1);				
	}
	dp[sum][n] = ret; 
	return ret;

}
int main()
{
	int  t, n;
	long long int p,q;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n >> x;
		for(int j = 0; j <= 150; j++)
			for(int k = 0; k <= 25; k++)
				dp[j][k] = -1;		
		p = func(0,n);
		q = 1;
		for (int j = 1; j <= n; j++) {
			q *= 6;
		}
		p = q - p;
	 	long long gcd = __gcd(p, q);
		p /= gcd;
		q /= gcd;
		if(q == 1)
			cout <<"Case " << i << ": " <<  p << endl;
		else
			cout <<"Case " << i << ": " <<  p << "/" << q << endl;
	}
}
