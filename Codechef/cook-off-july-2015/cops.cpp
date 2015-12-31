#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int x, y, m;
		cin >>m >> x >> y;
		int a[101]= {0};
		int num, l, r;
		
		for(int i = 0; i < m; i++){
			cin >> num;
			l = num - x*y;
			r = num + x*y;
			if(l <=1)
				l = 1;
			if(r >= 100)
				r = 100;
			
			for(int j = l; j <= r; j++)
				a[j] = 1;	
		}
		int c = 0;
		int ans = 0;
		for(int i = 1; i <= 100; i++) {	
			if(a[i] == 0)
				ans++;	
		}
		cout << ans << endl;
	}
}
