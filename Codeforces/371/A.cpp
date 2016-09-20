#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll l1, l2, r1, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    l1 = max(l1, l2);
    r1 = min(r1, r2);
    if(l1 > r1){
        cout << "0";
        return 0;
    }else{
        ll ans = r1-l1+1;
        if(k <= r1 && k >= l1){
            ans--;
        }
        cout << ans;
    }
    return 0;
}
