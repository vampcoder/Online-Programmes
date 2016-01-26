#include<bits/stdc++.h>

using namespace std;
char a[55];
int len;

int dp[55][6][4];

// 0 : BAD
// 1 : GOOD
// 2 : Mixed
bool test_vowel(char a){
	return (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');
}

int ret(int idx, int c, int v){
	if(idx >= len)
		if(c >= 5 || v >= 3)
			return 0;
		else
			return 1;
	if(dp[idx][c][v] != -1)
		return dp[idx][c][v];		
	int ans;
	if(a[idx] == '?'){
		int ans1, ans2;
		if(v == 2){
			ans1 = 0;
		}else{
			ans1 = ret(idx+1, 0, v+1);
		}
		if(c == 4){
			ans2 = 0;
		}else{
			ans2 = ret(idx+1, c+1, 0);
		}
		if(ans1 != ans2)
			ans = 2;
		else
			ans = ans1;
	}else if(test_vowel(a[idx])){
		if(v == 2){
			ans = 0;
		}else{
			ans = ret(idx+1, 0, v+1);
		}
	}else{
		if(c == 4){
			ans = 0;
		}else{
			ans = ret(idx+1, c+1, 0);
		}
	}	
	return dp[idx][c][v] = ans;	
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		memset(dp, -1, sizeof(dp));
		scanf("%s", a);
		len = strlen(a);
		int x = ret(0, 0, 0);
		cout << "Case " << i << ": ";
		if(x == 0)
			cout << "BAD";
		if(x == 1)
			cout <<"GOOD";
		if(x == 2)
			cout << "MIXED";
		cout << endl;
	}
}
