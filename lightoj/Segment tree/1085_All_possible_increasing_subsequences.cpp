#include<bits/stdc++.h>

typedef long long ll;
#define MOD 1000000007
using namespace std;

ll seg[400010];

void update(int ss, int se, int idx, int val, int qs){
    if(qs > se || qs < ss){
        return;
    }
    if (qs <= ss && qs >= se){
        seg[idx] = (seg[idx] + val)%MOD;
        return;
    }
    int mid = (ss+se)/2;
    seg[idx] += val;
    update(ss, mid, 2*idx+1, val, qs);
    update(mid+1, se, 2*idx+2, val, qs);
}

ll res(int ss, int se, int idx, int qs, int qe){
    if(qs > se || qe < ss)
        return 0;
    if(qs <= ss && qe >= se)
        return seg[idx];
    int mid = (ss+se)/2;
    return (res(ss, mid, 2*idx +1, qs, qe) + res(mid+1, se, 2*idx+2, qs, qe))%MOD;
}

bool func(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second > b.second;
    else{
        return a.first < b.first;
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(seg, 0, sizeof seg);
        int n;
        cin >> n;
        int arr[n];
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }
        vector<pair<int, int> > v;
        for(int j = 0; j < n; j++){
            v.push_back(make_pair(arr[j], j));
        }
        sort(v.begin(), v.end(), func);
        for(int j = 0; j < n; j++){
            pair<int, int> p = v[j];
           // cout << p.first << " " << p.second << endl;
            ll ans = res(0, n-1, 0, 0, p.second-1);
            ans++;
            update(0, n-1, 0, ans, p.second);
        }
        printf("Case %d: %lld\n", i+1, res(0, n-1, 0, 0, n-1)%MOD);
    }
}
