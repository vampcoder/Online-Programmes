#include<iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100007] = {0};
        int x;
        for(int i = 0; i < n-2; i++){
            cin >> x;
            a[x-1]++;
        }
        for(int i = 0; i < n-2; i++){
            cin >> x;
            a[x-1]++;
        }
        int maax = INT_MIN;
        int miin = INT_MAX;
        for(int i = 0; i < n-2; i++){
            if(a[i] < miin)
                miin = a[i];
            if(a[i] > maax)
                maax = a[i];
        }
        if(a[n-2] - miin
    }
}
