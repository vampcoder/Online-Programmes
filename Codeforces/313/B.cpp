#include<iostream>

using namespace std;

int main()
{
	int a1, a2,  a3, b1, b2, b3;
	cin >> a3 >> b3 >> a1 >> b1 >> a2 >> b2;
	if(((a1+a2)<= a3 && max(b1,b2) <= b3) || ((a1+a2)<= b3 && max(b1,b2) <= a3)||((a1+b2)<= a3 && max(b1,a2) <= b3)||((a1+b2)<= b3 && max(b1,a2) <= a3)||((b1+a2)<= a3 && max(a1,b2) <= b3)||((b1+a2)<= b3 && max(a1,b2) <= a3)||((b1+b2)<= a3 && max(a1,a2) <= b3)||((b1+b2)<= b3 && max(a1,a2) <= a3)){
		cout << "YES";
	}else{
		cout << "NO";
	
	}
}
