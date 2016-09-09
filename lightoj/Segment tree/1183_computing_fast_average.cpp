#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

ll seg[400100];
ll arr[100100];
ll lazy[400100];

void update(int ss, int se, int idx, int us, int ue, int val){
    if(lazy[idx] != -1){
        seg[idx] = (se-ss+1)*lazy[idx];
        if(ss != se){
            lazy[2*idx+1] = lazy[idx];
            lazy[2*idx+2] = lazy[idx];
        }
        lazy[idx] = -1;
    }

    if(us > se || ue < ss)
        return;
    if(us <= ss && ue >= se){
        seg[idx] = (se-ss+1)*val;
        if(ss != se){
            lazy[2*idx+1] = val;
            lazy[2*idx+2] = val;
        }
        return;
    }
    int mid = (ss+se)/2;
    update(ss, mid, 2*idx+1, us, ue, val);
    update(mid+1, se, 2*idx+2, us, ue, val);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

ll query(int ss, int se, int idx, int qs, int qe){
    if(lazy[idx] != -1){
        seg[idx] = (se-ss+1)*lazy[idx];
        if(ss != se){
            lazy[2*idx+1] = lazy[idx];
            lazy[2*idx+2] = lazy[idx];
        }
        lazy[idx] = -1;
    }
    if(qs > se || qe < ss)
        return 0;

    if(qs <= ss && qe >= se){
        return seg[idx];
    }
    int mid = (ss+se)/2;
    return query(ss, mid, 2*idx+1, qs, qe) + query(mid+1, se, 2*idx+2, qs, qe);
}

void printarr(){
    for(int i = 0; i < 23; i++){
        cout << query(0, 22, 0, i, i) << " ";
    }
    cout << endl;

}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(arr, 0, sizeof arr);
        memset(seg, 0, sizeof seg);
        memset(lazy, -1, sizeof lazy);
        int n, q;
        scanf("%d%d", &n, &q);
        int p, x, y, val;
        printf("Case %d:\n", i+1);
        for(int j = 0; j < q; j++){
            scanf("%d%d%d", &p, &x, &y);
            if(p == 1){
                scanf("%d", &val);
                update(0, n-1, 0, x, y, val);
            }else{
                ll ans = query(0, n-1, 0, x, y);
                //cout << ans << endl;
                ll ans1 = y-x+1;
                if(ans == 0){
                    printf("%lld\n", ans);
                    continue;
                }
                ll com = __gcd(ans, ans1);
                ans /= com;
                ans1 /= com;
                printf("%lld", ans);
                if(ans1 != 1){
                    printf("/%lld", ans1);
                }
                printf("\n");
            }
            //printarr();
        }
    }
}
