#include<bits/stdc++.h>
#define N 1000000007
#define ll long long

using namespace std;

ll n;
ll a[100010];

ll power(ll a, ll b){
	if (b == 0)
		return 1;
	ll x = power(a, b/2);
	
	if(b&1)
		return (a*x*x)%N;
	else
		return (x*x)%N;
}

ll fact_by_two(ll a){
	ll ans = 1;
	for(ll i = a ; i > 2; i--){
		ans *= i;
		ans %= N;
	}
	return ans;

}

int main(){
	ll t;
	cin >> t;
	while(t--){
		cin >> n;
		n++;
		ll sum = 0, diff = 0;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		ll p = 1;
		ll po[n];
		for(int i = 0; i < n; i++){
			po[i] = p;
			p *= 2;
			if(p >= N)
				p %= N;
		}
//		cout << sum << " " << diff << endl;
		sum = a[0];
		ll ans = 0;
		for(ll i = 1; i < n; i++){
			ll temp = 1;
			temp *= ((sum*a[i])%N);
			temp *= po[n-i];
			if(temp >= N)
				temp %= N;
			ans += temp;
			
			if(ans >= N)
				ans %= N;
			sum += (po[i-1]*a[i]);
			if (sum >= N)
				sum %= N;
		}
		cout << ans << endl;		
	}
}
