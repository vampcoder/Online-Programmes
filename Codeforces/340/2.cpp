#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int mi = n, ma = -1;
	for(int i = 0; i  < n; i++){
		if(a[i] == 1){
			ma = max(ma, i);
			mi = min(mi, i);
		}
	}
	if(ma == -1){
		cout << "0";
		return 0;
	}
	long long ans = 1;
	int k = 0;
	for(int i = mi+1; i <= ma; i++){
		if(a[i] == 1){
			if(k != 0)
				ans = ans *(k+1);
			k = 0;
		}else{
			k++;
		}
	}
	cout << ans;

}
