#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main()
{
    ll t, x1, y1, x2, y2;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        ll x, y, ans;
        x = abs(x1-x2);
        y = abs(y1-y2);

        if(x == 0){
            ans = y + 1;
        }else if(y == 0){
            ans = x + 1;
        }else{
            ans = __gcd(x, y) + 1;
        }
        cout << "Case " << i+1 << ": " << ans << endl;
    }
}
