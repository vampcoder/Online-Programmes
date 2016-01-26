#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, ll> pi;

ll n;
vector<vector<pi > > v;


int bfs(int a, ll arr1[]){
    int visit[n];
    memset(visit, 0, sizeof(visit));
    memset(arr1, -1, n* sizeof(int));
    queue<pi > q;
    q.push(make_pair(a, 0));
    visit[a] = 1;
    arr1[a] = 0;
    ll high = 0;
    int h = 0;
    while(!q.empty()){
        pi temp = q.front();
        q.pop();
        ll c = temp.second;
        ll s = temp.first;
        for(int i = 0; i < v[s].size(); i++){
            ll x = v[s][i].first;
            ll xc = v[s][i].second;
            if(visit[x] == 0){
                visit[x] = 1;
                arr1[x] = xc + c;
                if(high < arr1[x]){
                    high = arr1[x];
                    h = x;
                }
                q.push(make_pair(x, xc + c));
            }
        }
    }
    return h;
}


void sol(void){
    ll arr1[n];
    ll arr2[n];
    int a = bfs(0, arr1);
    int b= bfs(a, arr2);
    int c = bfs(b, arr1);
    for(int i = 0; i < n; i++){
        printf("%lld\n", max(arr1[i], arr2[i]));
    }



}


int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        cin >> n;
        v.resize(n);
        int x, y, c;
        for(int j = 0; j < n-1; j++){
            scanf("%d%d%d", &x, &y, &c);
            v[x].push_back(make_pair(y, c));
            v[y].push_back(make_pair(x, c));
        }
        printf("Case %d:\n", i);
        sol();
        v.clear();
    }


}
