#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, d;
		cin >> n >> d;
		int a[n];
		long long ans = 0;
		int mark[100000] = {0};
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		if(n == 1){
			cout << "0\n";
		}else{
			int j, i = n-1;
			while(i >= 1){	
				bool flag = true;
				if((a[i]-a[i-1]) < d){
					ans += a[i];
					ans += a[i-1];
					i = i-2;
				}else{
					i--;
				}
			}
		}
		cout << ans <<endl;
	}
}
