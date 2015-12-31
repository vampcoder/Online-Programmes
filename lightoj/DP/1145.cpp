#include <iostream>
using namespace std;

#define M 100000007

long long  arr[1005][15007] = {0};
int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int n, s, k;
		cin >> n >> k >> s;

		for(int j = 1; j <= n; j++){
			arr[j][0] = 0;
		}
		for(int j = 0; j <= s; j++){
			arr[0][j] = 1;
		}
		for(int j = 1; j <= n; j++){
			for(int l = 1; l <= s; l++){

                arr[j][l] = (arr[j-1][l-1]+arr[j][l-1]);
                if(l >= k+1){
                    arr[j][l] = (arr[j][l]-arr[j-1][l-k-1]);
                }
                arr[j][l]= (arr[j][l]+M)%M;
			}
		}
		/*for(int j = 0; j <= n; j++){
            for(int l = 0; l <= s; l++){
                cout << arr[j][l] << " ";
            }
            cout << endl;
		}*/
		long long ans;
		if(arr[n][s] == 0){
            ans = 0;
		}else{
            ans = (arr[n][s]-arr[n][s-1]+M)%M;
		}
		cout << "Case "<<i <<": " << ans << endl;
	}
	return 0;
}
