#include<iostream>
#include<algorithm>
#include<map>
#include<climits>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long int a[n];
		long long int b[n];
		for(int i = 0; i < n; i++){
			int m;
			cin >> m;
			long long int x, y;
			long long int p = LLONG_MIN;
			while(m--){
				cin >> x >> y;
				if(x > p){
					p = x;
				}
			}
			a[i] = p;
			b[i] = p;
		}
		map<long long int, int> m;
		sort(a, a+n);
		for(int i = 0; i < n; i++)
			m[a[i]] = i;
		for(int i = 0; i < n; i++)
			cout << m[b[i]] << " ";
		cout << endl;			
	}
}
