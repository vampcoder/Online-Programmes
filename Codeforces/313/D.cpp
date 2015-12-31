#include<bits/stdc++.h>

using namespace std;

bool func(string a, string b){
	if(a.length() >= 1){
		if(a == b)
			return true;
		else{
			string a1, a2, b1, b2;
			a1 = a.substr(0,a.length()/2);
			a2 = a.substr(a.length()/2);
			b1 = b.substr(0,b.length()/2);
			b2 = b.substr(b.length()/2);
//			cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
			return (func(a1, b1) && func(a2, b2)) || (func(a1, b2) && func(a2, b1));
		}
	}else{
		return false;
	}
}

int main()
{
	string a, b;
	cin >> a >> b;
	if(func(a, b))
		cout << "YES";
	else
		cout << "NO";
}
