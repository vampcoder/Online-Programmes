#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;

int rec(int arr[], int n, int m){
	int mi = arr[n-1]-arr[0];
	for(int i = 0; i <= m-n; i++){
		mi = min(mi, arr[n+i]-arr[i+1]);
	}
	return mi;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a[m];
	for(int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	sort(a,a+m);
	printf("%d\n", rec(a, n, m-1));
}
