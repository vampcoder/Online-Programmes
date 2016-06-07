#include<bits/stdc++.h>

using namespace std;

int lazy[1000010];
long long seg[1000010];
int arr[100010];


long long query(int ss, int se, int i, int qs, int qe){
    if(lazy[i]!= 0){
        seg[i] += (lazy[i]*(se-ss+1));
        if(ss !=se){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if (ss > qe || se < qs){
        return 0;
    }
    if(ss >= qs && se <= qe){
        return seg[i];
    }
    int mid = (ss + se)/2;

    return query(ss, mid, 2*i+1, qs, qe) + query(mid+1, se, 2*i+2, qs, qe);
}


void update(int ss, int se, int i, int qs, int qe, int val){
    if(lazy[i] != 0){
        seg[i] += (lazy[i]*(se-ss+1));
        if(ss !=se){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if (ss > qe || se < qs){
        return;
    }
    if(ss >= qs && se <= qe){
        seg[i] += (se-ss+1)*val;
        if(ss != se){
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return;
    }
    int mid = (ss+se)/2;

    update(ss, mid, 2*i+1, qs, qe, val);
    update(mid+1, se, 2*i+2, qs, qe, val);
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

int main()
{
    int t, n, q;
    cin >> t;
    for(int i = 1; i <= t; i++){
        memset(seg, 0, sizeof seg);
        memset(lazy, 0, sizeof lazy);
        memset(arr, 0, sizeof arr);
        cin >> n >> q;
        int p, x, y, v;
        printf("Case %d:\n", i);
        for(int j = 0; j < q; j++){
            scanf("%d%d%d", &p, &x, &y);
            if(p == 0){
                scanf("%d", &v);
                update(0, n-1, 0, x, y, v);
            }else{
                printf("%lld\n", query(0, n-1, 0, x, y));
            }
        }
    }
}
