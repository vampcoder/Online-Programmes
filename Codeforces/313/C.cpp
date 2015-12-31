#include<iostream>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	cin >> x >> y;
	cin >> x >> y;
	int ans = 0;
	int t = y;
	for(int i = 0; i < x; i++, t++)
		ans+= (2*t+1);
	t = x;
	for(int i = 0; i < y; i++, t++){
		ans+= (2*t+1);
	}
	cout << ans;

}
