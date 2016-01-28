#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

int n, m, a;

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

    for(int i = 0; i < v.size(); i++){
        node temp = v[i];
        if(temp.c < a){
            if(Find_set(temp.s) != Find_set(temp.e)){
                ans += temp.c;
                Union(temp.s, temp.e);
            }
        }else{
            break;
        }

    }
    int arr[n];
    memset(arr, 0, sizeof arr);
    int x;
    for(int i = 0; i < n; i++){
     //   cout << dis_set[i].parent << " ";
        x = Find_set(i);
        arr[x] = 1;
    }
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1)
            cnt++;
    }
    ll c = a;
   // cout << endl
    printf("%lld %lld\n", ans+cnt*c, cnt);
}


int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        scanf("%d%d%d", &n, &m, &a);
        int c, x, y;
        for(int j = 0; j < m; j++){
            scanf("%d%d%d", &x, &y, &c);
            node temp;
            temp.s = x-1;
            temp.e = y-1;
            temp.c = c;
            v.push_back(temp);
        }


        printf("Case %d: ", i);
        mst();
        v.clear();
    }
}
