#include<iostream>

using namespace std;

int main()
{
    long long t, n, k, x;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int a[n];
        int c = 0, l = k;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(l < a[i]){
                l += k;
            }
        }

    }
}
