#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int t;
	long long n;
	cin >> t;
	int i = 2, j;
	long double x;
	int count  = 1;
	bool b = true;
	while(t--){
		while(i < 100){
			if(!b) break;
			j = 1;
			while(j < count){
				if(!b) break;
				n = i;
				x = (sqrtl(1+8.0*(n-1))-1)/2;
				cout << x << endl;
				if((long long)ceill(x) == (long long)floorl(x)){
					if(count != ((long long)(floorl(x)+1)))
						b = false;
				}else{
					if(count != ((long long)(floorl(x)+2)))
						b = false;
				}
				j++;
				i++;
			}
			count++;
		}
	}
	cout << count << " " << x << " " << n << endl;
}
