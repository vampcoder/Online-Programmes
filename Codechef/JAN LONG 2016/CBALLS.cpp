#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int t, n, x;
	int a[10010];
	cin >> t;
	while(t--){
		ll ans = 0;
		int cur;		
		cin >> n;
		cin >> x;
		if(x%2 == 1){
			x++;
			ans++;
		}
		cur = x;
		for(int j = 1; j < n; j++){
			cin >> x;
			if(x < cur){
				ans += (cur-x);
			}else if(x%2 == 1){
				ans++;
				x++;
				cur = x;
			}
		}
		cout << ans << endl;
	}
}
