#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, n;
	cin >> t;
	for(int j = 1; j <= t; j++){
		cin >> n;
		int n1 = 0, n0 = 0, x;
		for(int i = 0; i < n; i++){
			cin >> x;
			if(x < 0)
				n0++;
			n1 += abs(x);

		}
		
		int g = __gcd(n1, n-n0);
		cout << "Case " << j << ": ";
		if(n0 == n)	
			cout << "inf" << endl;
		else
			cout << n1/g << "/" << (n- n0)/g << endl; 
	}

}
