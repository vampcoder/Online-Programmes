#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	long long n, m, a;
	cin >> n >> m >> a;

	cout << (long long)ceil(1.0*n/a)*(long long)ceil(1.0*m/a) << endl;
}
