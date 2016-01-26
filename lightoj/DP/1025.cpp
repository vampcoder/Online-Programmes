#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[65][65];
char s[65];

ll rec(int i, int j){
	if(i > j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	if(s[i] == s[j]){
		dp[i][j] = (1+rec(i+1,j)+ rec(i, j-1));
	}else{
		dp[i][j] = (rec(i+1, j) + rec(i, j-1) - rec(i+1, j-1));
	}
	return dp[i][j];
}


int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		memset(dp, -1, sizeof(dp));
		scanf("%s", s);
		printf("Case %d: %lld\n", i,  rec(0, strlen(s)-1));	
	}	
}
