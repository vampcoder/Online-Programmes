#include<bits/stdc++.h>

using namespace std;

int a[32];
long long n;

long long num(int x){
	int mul = 1;
	long long ret = 0;
	for(int i = 31; i >= x; i--){
		ret += (mul*a[i]);
		cout << a[i] << " ";
		mul *= 2;
	}
	
	cout <<endl << ret << endl; 
	return ret;
}
long long func(long long idx, int last){
	if(num(idx) > n){
		return 0;
	}
	
	long long ret = 0;	
	if(last == 1){
		a[idx-1] = 1;
		ret += (func(idx-1, 1)+1);
		a[idx-1] = 0;
		ret += (func(idx-1, 0));
	}
	if(last == 0){
		a[idx-1] = 1;
		ret += (func(idx-1, 1));
		a[idx-1] = 0;
		ret += (func(idx-1, 0));
	}
		
	return ret;
}
int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		if(n == 0){
			cout <<"0\n";
			continue;
		}
		long long ret = 0;
		a[31] = 0;
		ret += func(31, 0);
		a[31] = 1;
		ret += func(31, 1);
		cout << ret << endl;		

	}
}
