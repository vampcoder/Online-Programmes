#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int n, s, k;
		cin >> n > k >> s;
		int arr[n+1][s+1];
		for(int i = 1; i <= s; i++){
			arr[i][0] = 0;
		}
		for(int i = 0; i <= n; i++){
			arr[0][i] = 0;
		}
		for(int j = 1; j <= s; j++){
			for(int k = 0; k < n; k++){

			}
		}
	}
	return 0;
}
