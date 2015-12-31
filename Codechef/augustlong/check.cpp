#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int t, i;
	long long n;
	long double y, x;
	bool b = true;
	for (i = 1; i < 100; i++) {
		if(!b) break;
		n = i;
		y = (n*(n+1))/2 + 1;
		x = (sqrtl(1+8.0*(y-1))-1)/2;
		if((long long)ceill(x) == (long long)floorl(x)){
	//		cout << "a ";
	//	i	cout << (long long)floorl(x)+1 << endl;
			if((long long)n != (long long)floorl(x))
				b= false;
//		}else{
		//	cout << "b  ";	
		//	cout << (long long)floorl(x)+2 << endl;
//			if((long long)n != (long long)floorl(x)+2)
//				b= false;
		}
	}
	cout << i << " " << y << " " << x << endl;
}
