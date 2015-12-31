#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	map<string, int> m;
	m["balck"] = 0;
	m["blue"] = 1;
	m["red"] = 2;
	m["green"] = 3;
	m["yellow"] = 4;
	m["orange"] = 5;
	while(t--){
		vector<int> v(6);
		string s;
		for(int i = 0; i < 6; i++){
			cin >> s;
			v[m[s]]++;
		}
		bool flag = false;
		for(int i = 0; i < 6; i++){
			if(v[i] >= 3)
				flag = true;
		}
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
