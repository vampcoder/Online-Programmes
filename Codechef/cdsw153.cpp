#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	long long int t, n, l, r;
	int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	scanf("%lld", &t);
	
	while(t--){
		scanf("%lld%lld%lld", &n, &l, &r);
		long long int mask, x = 0;
		for(int i = 0 ; i < 15; i++){
			if(primes[i] <= n)
				x++;
		}
		long long int m = pow(2, x);
		long long int f = 0;
		for(mask = 1; mask < m; mask++){
			long long int mul = 1, ans = 0;
			long long int count  = 0;
			for(int j = 0;j < x; j++){
				if((1<<j)& mask){
					mul *= primes[j];
					count++;
				}
			}
		//	if(mask <= 7)
		//		cout << mul<< " " << count << endl;
				ans = (r/mul) - (l-1)/mul;
			//cout << mul << endl;
			if(count % 2)
				f += ans;
			else
				f -= ans;
		}
		printf("%lld\n", f);	
	}
}
