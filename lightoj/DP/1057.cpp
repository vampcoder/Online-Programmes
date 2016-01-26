#include<bits/stdc++.h>

using namespace std;

vector<int> x;
vector<int> y;

int sx, sy, t, n, m;
int dp[15][33000];
int rec(int last, int mask){
	if(x.size() == 0)
		return 0;
	if(last != -1 && dp[last][mask] != -1)
		return dp[last][mask];	
	int cnt = 0;
	
	for(int i = 0; i < x.size(); i++){
		if(mask & (1 << i))
			cnt++;
	}
	
	if(cnt == x.size())
		return max(abs(x[last]-sx),abs(sy-y[last]));
	int ans = INT_MAX;
	
	int temp;
	
	for(int i = 0; i < x.size(); i++){
		if(!(mask & (1 << i))){
			temp = mask | (1 << i);
			if(last != -1)
				ans  = min(ans, max(abs(x[i]-x[last]), abs(y[i]-y[last]))+ rec(i,temp));
			else
				ans = min(ans, max(abs(x[i] - sx) , abs(y[i]-sy))+ rec(i, temp));
		}
	}
	if(last != -1)
		dp[last][mask] = ans;
	return ans;
}

int main()
{
	char a[30];
	cin >> t;
	for(int i = 1; i <= t; i++){
		x.clear();
		y.clear();
		memset(dp, -1, sizeof(dp));
		cin >> m >> n;
		for(int j = 0; j < m; j++){
			scanf("%s", a);
			for(int k = 0; k < n; k++){
				if(a[k] == 'x'){
					sx = j;
					sy = k;
//					cout << "source : " <<  sx << " " << sy << endl;
				}
				if(a[k] == 'g'){
//					cout << j << " " << k << endl;
					x.push_back(j);
					y.push_back(k);
				}
			}
		}
		cout << "Case " << i << ": " <<  rec(-1, 0) << endl;		
	}
}
