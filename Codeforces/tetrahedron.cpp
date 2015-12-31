#include<iostream>
#include<cstdio>
//#include<cstdint>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	long long int a[] = {1, 0};
	long long int b;
	int x = 1000000007;
	for(int i = 1; i <= n; i++) {
		b = a[1];	
		a[1] = 3*a[0]+2*a[1];
		a[1] %= x;
		a[0] = b;
	}
	printf("%d\n", a[0]);
}
