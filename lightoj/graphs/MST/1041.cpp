#include<bits/stdc++.h>

using namespace std;

map<string, int> m;
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
vector<node> v;

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
    sort(v.begin(), v.end(), cmpc);
    //cout << v1.size() << " " << v2.size() << endl;

    for(int i = 0; i <= n; i++){
        Make_set(i);
    }

    for(int i = 0; i < v.size(); i++){
        node temp = v[i];
        if(Find_set(temp.s) != Find_set(temp.e)){
            ans += temp.c;
            Union(temp.s, temp.e);
        }
    }
    bool flag = true;
    int x = Find_set(0);
    for(int i = 1; i <= n; i++){
     //   cout << dis_set[i].parent << " ";
        if(x != Find_set(i))
            flag = false;
    }
   // cout << endl;
    if(flag)
        return ans;
    else
        return -1;
}


int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        string s1, s2;
        int cost;
        int I = 0;
        for(int j = 0; j < n; j++){
            int x, y, c;
            map<string, int>::iterator it;
            cin >> s1 >> s2 >> c;
            it = m.find(s1);
            if(it == m.end()){
                x = I++;
                m[s1] = x;
            }else{
                x = it->second;
            }
            it = m.find(s2);
            if(it == m.end()){
                y = I++;
                m[s2] = y;
            }else{
                y = it->second;
            }
            node temp;
            temp.s = x;
            temp.e = y;
            temp.c = c;
            v.push_back(temp);
        }
       // for(int j = 0; j < v.size(); j++){
         //   cout << v[j].s << " " << v[j].e << " " << v[j].c << endl;
        //}
        //cout << endl;
        n = I-1;
        ll x = mst();
        if(x >= 0){
            cout << "Case " << i << ": " << x << endl;
        }else{
            cout << "Case " << i << ": Impossible" << endl;
        }
        v.clear();
        m.clear();
    }
}
