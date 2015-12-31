#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long 
using namespace std;

void print(int  a[], int n){
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << "\n";
}
void update(ll tree[], int n, int x, int val){
	while(x <= n){
		tree[x] += val;
		x += x&(-x);
	}
}
ll read(ll tree[], int x){
	ll sum = 0;
	while(x > 0){
		sum += tree[x];
		x -= x&(-x);
	}
	return sum;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a[n+1];
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		vector<int> v(a+1,a+n+1);
		sort(v.begin(), v.end());
		for(int i = 1; i <= n; i++){
			int rank = int(lower_bound(v.begin(),v.end(), a[i])-v.begin());
			a[i] = rank+1;
		}
//		print(a, n);
		ll tree[n+1];
		memset(tree, 0, sizeof(tree));
		ll count  = 0;
		for(int i = n; i > 0; i--){
			count += read(tree, a[i]);
//			cout << read(tree, a[i]) << " ";
			update(tree, n, a[i], 1); 
		}
//		print(tree, n);
		printf("%lld\n", count);	
	}
}
