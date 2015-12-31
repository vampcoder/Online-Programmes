#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int a, b, c;
int dp[4007];
int rec(int n){
	if(n == 0){
		return 0;
	}
	if(n < 0){
		return -1;
	}
	if(dp[n] != -2){
		return dp[n];
	}
	int p, q, r;
	p = rec(n-a);
	if(p != -1){
		p++;
	}
	q = rec(n-b);
	if(q != -1){
		q++;
	}
	r = rec(n-c);
	if(r != -1)
		r++;
	p = max(p, q);
	p = max(p, r);

	dp[n] = p;
	return p;
} 
int main()
{
	int n;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	
	for(int i = 0; i <= n+1; i++)
		 dp[i] = -2;
	printf("%d\n", rec(n));
}
