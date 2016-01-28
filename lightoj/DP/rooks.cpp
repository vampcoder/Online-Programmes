#include<iostream>
#include<cstdio>

using namespace std;
int n, l;
int a[31];
long long int rec(int k){
	if( k == 0) 
		return 1;
	long long int x = 0;
	for(int i = 0; i < n; i++){
		if(a[i] != 1){
			a[i] = 1;
		x += rec(k-1);
			a[i] = 0;
		}
	}
	return x;
}
int main()
{
	scanf("%d%d", &n, &l);
	for(int i = 0; i < 31; i++)
		a[i] = 0;
	if(l > n)
		printf("%d", 0);
	else
		printf("%lld\n",n*rec(l));
}
