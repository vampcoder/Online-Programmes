#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
string str1, str2;
long long int fact[50];
int dp[32][32];
int cw[32][32];
int lcs(int a, int b, long long int &x){
	for(int k = 0; k <= a; k++)
		dp[k][0] = 0;
	for(int k = 0; k <= b; k++)
		dp[0][k] = 0;
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			if(str1[i-1] == str2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else{
//				x++;
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	for(int i = 0; i <=a; i++)
		cw[i][0] = 1;
	for(int i = 0; i <= b; i++)
		cw[0][i] = 1;
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			if(str1[i-1] == str2[j-1])
				cw[i][j] += cw[i-1][j-1];
			else{
				if(dp[i][j-1] < dp[i-1][j])
					cw[i][j] += cw[i-1][j];
				else if(dp[i][j-1] > dp[i-1][j])
					cw[i][j] += cw[i][j-1];
				else if(dp[i-1][j] == dp[i][j-1])
					cw[i][j] += (cw[i-1][j]+cw[i][j-1]);
			}
		}

	}
	x = cw[a][b];	
	return dp[a][b];
}
int main()
{
	cin.tie(0);
	int t;
	fact[0]=1;
	fact[1] = 1;
	for(int i = 2; i < 50; i++)
		fact[i] = i*fact[i-1];
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		for(int j = 0; j < 32; j++)
			for(int k = 0; k < 32; k++)
				dp[j][k] = -1;
		cin >> str1 >> str2;		
		long long int x = 0;
		int l = str1.length() + str2.length()-lcs(str1.length(), str2.length(), x);
		printf("Case %d: %d %lld\n", i, l, x); 
	}	
}
