#include<bits/stdc++.h>

using namespace std;

int n;
double a[100];
double dp[100];

double rec(int pos){
	if(pos == n-1)
		return a[pos];
	if(dp[pos] != -1)
		return dp[pos];
	double ans = 0;
	int p;
	double cnt = 0;
	for(int i = 1; i <= 6; i++){
		p = pos + i;
		if(p < n){
			cnt+= 1;	
			ans += rec(p);					
		}else{
			break;
		}
	}
	ans /= cnt;
	ans += a[pos];
	dp[pos] = ans;
	return ans;		
}


int main()
{
	int t;

	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> a[j];
			dp[j] = -1;
		}
//		cout.precision(6);
		cout << "Case " << i << ": " << setprecision(15) <<  rec(0) << endl;	
	}


}
