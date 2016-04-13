#include<bits/stdc++.h>

using namespace std;

long double arr[100010];

void func(){
    long double ans = 0.0;
    arr[0] = 0.0;
    long double k = 1;
    for(int i = 1; i < 100010; i++){
        for(int j = 0; j < 1000; j++){
            ans += (1.0L/k);
            k++;
        }
        arr[i] = ans;
    }
}

long double solve(int x){
    int r = x/1000;
    long double ans = arr[r];
    for(int i = r*1000+1; i <= x; i++){
        if(i != 0){
            ans += (1.0L/ i);
        }
    }
    return ans;
}
int main()
{



    int t, x;
    func();
    //cout << "Yes";
    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> x;
        printf("Case %d: %0.10Lf\n", i, solve(x));
    }
}
