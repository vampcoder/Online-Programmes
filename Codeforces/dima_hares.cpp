#include<iostream>

using namespace std;
int a[3007], b[3007], c[3007];
int n, gjoy = 0;
int rec(int level, int last, int last_to_last){
	if(level == n){
		if(last_to_last == 0){
			return a[level-1];
		}else{
			return b[level-1];
		}
	}
	if(last_to_last == 0){
		return max(rec(level+1, 0, last)+a[level-1],rec(level+1, 1, last)+b[level-1]);
	}else{
		return max(rec(level+1, 0, last)+b[level-1],rec(level+1, 1, last)+c[level-1]);
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++)
		cin >> c[i];
	cout << max(rec(1, 0, 0),rec(1, 1, 0)) << endl;
}
