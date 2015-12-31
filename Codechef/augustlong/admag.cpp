#include<iostream>
#include<cmath>

using namespace std;
long long arr[100];
int main()
{
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i < 100; i++){
        arr[i] = arr[i-1] +arr[i-2];
    }
	int t;
	long long n;
	cin >> t;
	while(t--){
		cin >> n;
		int i;
        for(i = 87; i >= 0 ; i--){
            if(n < arr[i])
                continue;
            else
                break;
        }
        cout << i-1 << endl;
	}
}
