#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bitset<32> b(n);
    vector<int> a;
    //cout << b;
    int ans = 1;
    for(int i = 0; i < 32; i++){
        if(b[i])
            a.push_back(ans);
        ans *= 2;
    }
    for(int i = a.size()-1; i >= 0; i--)
        cout << a[i] << " ";
}
