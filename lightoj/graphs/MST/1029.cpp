#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

int n;

struct node{
    int s;
    int e;
    ll c;
};

struct dset{
    int parent;
    int r;
};
dset dis_set[110];


bool cmpc(node a, node b){
    return a.c < b.c;

}
vector<vector<pi > > v;

void Make_set(int i){
    dis_set[i].r = 0;
    dis_set[i].parent = i;
}
int Find_set(int x){
    if(x != dis_set[x].parent){
        dis_set[x].parent = Find_set(dis_set[x].parent);
    }
    return dis_set[x].parent;

}
void Link(int x, int y){
    dset x1 = dis_set[x];
    dset y1 = dis_set[y];
    if(x1.r > y1.r)
        dis_set[y].parent = x;
    else{
        dis_set[x].parent = y;
        if(x1.r == y1.r)
            dis_set[y].r++;
    }
}
void Union(int x, int y){
    Link(Find_set(x), Find_set(y));
}

ll mst(void){


    ll ans = 0;
    vector<node> v1;
    vector<node> v2;
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < v[i].size(); j++){
            node ss;
            ss.s = i;
            ss.e = v[i][j].first;
            ss.c = v[i][j].second;
            v1.push_back(ss);
            ss.c *= -1;
            v2.push_back(ss);
        }
    }
    sort(v1.begin(), v1.end(), cmpc);
    sort(v2.begin(), v2.end(), cmpc);
    //cout << v1.size() << " " << v2.size() << endl;

    for(int i = 0; i <= n; i++){
        Make_set(i);
    }

    for(int i = 0; i < v1.size(); i++){
        node temp = v1[i];
        if(Find_set(temp.s) != Find_set(temp.e)){
            ans += temp.c;
            Union(temp.s, temp.e);
        }
    }

    for(int i = 0; i <= n; i++){
        Make_set(i);
    }
    for(int i = 0; i < v2.size(); i++){
        node temp = v2[i];
        if(Find_set(temp.s) != Find_set(temp.e)){
            ans += (-1*temp.c);
            Union(temp.s, temp.e);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        v.resize(n+1);
        int x, y, c;
        while(1){
            cin >> x >> y >> c;
            if((x == 0)&&(y == 0)&&(c == 0)){
                break;
            }
            v[x].push_back(make_pair(y, c));
        }
        ll ans = mst();
        if(ans%2 == 0){
            cout << "Case " << i << ": " << ans/2 << endl;
        }else{
            cout << "Case " << i << ": " << ans << "/2" <<endl;
        }
        v.clear();
    }
}
