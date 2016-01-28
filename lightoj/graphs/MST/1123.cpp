#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

int n, w;

struct node{
    int s;
    int e;
    ll c;
};

struct dset{
    int parent;
    int r;
};
dset dis_set[10010];


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

void mst(void){


    ll ans = 0;
    sort(v.begin(), v.end(), cmpc);
    //cout << v1.size() << " " << v2.size() << endl;

    for(int i = 0; i <= n; i++){
        Make_set(i);
    }
    bool  x[v.size()];
    memset(x, 0, sizeof x);
    for(int i = 0; i < v.size(); i++){
        node temp = v[i];
        if(Find_set(temp.s) != Find_set(temp.e)){
            ans += temp.c;
            x[i] = true;
            Union(temp.s, temp.e);
        }

    }
    vector<node> v1;
    for(int i = 0; i < v.size(); i++){
        if(x[i]){
            v1.push_back(v[i]);
        }
    }
    v.clear();
    v.swap(v1);

    int arr[n];
    memset(arr, 0, sizeof arr);
    bool flag = true;
    int p = Find_set(0);
    for(int i = 1; i < n; i++){
        if(p != Find_set(i))
            flag = false;
    }
    if(flag)
        printf("%lld\n", ans);
    else
        printf("-1\n");
}


int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){

        scanf("%d%d", &n, &w);
        printf("Case %d:\n", i);
        int c, x, y;
        for(int j = 0; j < w; j++){
            scanf("%d%d%d", &x, &y, &c);
            node temp;
            temp.s = x-1;
            temp.e = y-1;
            temp.c = c;
            v.push_back(temp);
            mst();
        }
        v.clear();
    }
}
