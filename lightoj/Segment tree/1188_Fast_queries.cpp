#include<bits/stdc++.h>

using namespace std;

int arr[100010];
struct node{
    int i;
    int l;
    int r;
    int ans;
};
node queries[50010];
int seg[500010];
int n, q;

void update(int ss, int se, int idx, int us, int val){
    if(us < ss || us > se){
        return;
    }
    if(ss == se){
        if(us == ss){
            seg[idx] += val;
            return;
        }
    }

    int mid = (ss+ se)/2;
    update(ss, mid, 2*idx+1, us, val);
    update(mid+1, se, 2*idx+2, us, val);
    seg[idx] = seg[2*idx+1]+ seg[2*idx+2];
}

int read(int ss, int se, int idx, int qs, int qe){
    if(qs > se || qe < ss)
        return 0;
    if(qs <= ss && qe >= se){
        return seg[idx];
    }
    int mid = (ss+se)/2;
    return read(ss, mid, 2*idx+1, qs, qe) + read(mid+1, se, 2*idx+2, qs, qe);
}

bool cmpc(node a, node b){
    if(a.r == b.r)
        return a.l < b.l;
    else
        return a.r < b.r;
}

bool cmpc1(node a, node b){
    return a.i < b.i;
}

void solve(){
    sort(queries, queries+q, cmpc);
    map<int, int> m;
    int pos[n];
    for(int i = 0; i < n; i++){
        if(m.find(arr[i]) == m.end()){
            pos[i] = -1;
        }else{
            pos[i] = m[arr[i]];
        }
        m[arr[i]] = i;
        //cout << pos[i] << " ";
    }
   // cout << endl;
    int qi = 0;
    for(int i = 0; i < n; i++){
        if(pos[i] != -1){
            update(0, n-1, 0, pos[i], -1);
        }
        update(0, n-1, 0, i, 1);
        while(i > (queries[qi].r-1))
            qi++;
        while(i == queries[qi].r-1){
            queries[qi].ans = read(0, n-1, 0, queries[qi].l-1, queries[qi].r-1);
            qi++;
            //cout << queries[qi].ans << " ";
        }
    }
    //cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(seg, 0, sizeof seg);
        cin >> n >> q;
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }
        for(int j = 0; j < q; j++){
            scanf("%d%d", &queries[j].l, &queries[j].r);
            queries[j].i = j;
        }
        solve();
        sort(queries, queries+q, cmpc1);
        printf("Case %d:\n", i+1);
        for(int j = 0; j < q; j++){
            printf("%d\n", queries[j].ans);
        }

    }
}
