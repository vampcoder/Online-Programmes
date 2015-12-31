#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n == 1){
		string s;
		cin >> s;
		cout << "1\n";
		return 0;		

	}
	string s[104];
	for(int i = 0; i < n; i++)
		cin >> s[i];
	int m = 0;
	sort(s, s+n);
//	for(int i = 0; i < n; i++)
//		cout << s[i] << endl;	
	string temp = s[0];
	int tm = 1;
	for(int i = 1; i < n; i++){
		if(temp ==s[i])
			tm++;
		else{
			if(tm > m){
				m = tm;		
			}
			tm = 1;
			temp = s[i];
		}
	}
	if(tm > m)
		m = tm;
	cout << m;	
}
