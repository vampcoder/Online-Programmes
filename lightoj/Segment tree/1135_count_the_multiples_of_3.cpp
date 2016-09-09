#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

struct node{
    int zero;
    int one;
    int two;
};

node seg[400010];
int lazy[400010];

void construct(int ss, int se, int idx){
    if(ss == se){
        seg[idx].zero = 1;
        return;
    }
    int mid = (ss+se)/2;
    construct(ss, mid, 2*idx+1);
    construct(mid+1, se, 2*idx+2);
    seg[idx].zero = seg[2*idx+1].zero + seg[2*idx+2].zero;
}

void update(int ss, int se, int idx, int us, int ue){
    if(lazy[idx] != 0){
        if(lazy[idx] % 3 == 1){
            int temp = seg[idx].zero;
            seg[idx].zero = seg[idx].two;
            seg[idx].two = seg[idx].one;
            seg[idx].one = temp;
        }else if(lazy[idx]%3 == 2){
            int temp = seg[idx].zero;
            seg[idx].zero = seg[idx].one;
            seg[idx].one = seg[idx].two;
            seg[idx].two = temp;
        }
        if(ss != se){
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if(us > se || ue < ss)
        return;

    if(us <= ss && ue >= se){
        int temp = seg[idx].zero;
        seg[idx].zero = seg[idx].two;
        seg[idx].two = seg[idx].one;
        seg[idx].one = temp;
        if(ss != se){
            lazy[2*idx+1] += 1;
            lazy[2*idx+2] += 1;
        }
        return;
    }
    int mid =(ss+se)/2;
    update(ss, mid, 2*idx+1, us, ue);
    update(mid+1, se, 2*idx+2, us, ue);

    seg[idx].zero = seg[2*idx+1].zero + seg[2*idx+2].zero;
    seg[idx].one = seg[2*idx+1].one + seg[2*idx+2].one;
    seg[idx].two = seg[2*idx+1].two + seg[2*idx+2].two;
}

ll query(int ss, int se, int idx, int qs, int qe){
    if(lazy[idx] != 0){
        if(lazy[idx] % 3 == 1){
            int temp = seg[idx].zero;
            seg[idx].zero = seg[idx].two;
            seg[idx].two = seg[idx].one;
            seg[idx].one = temp;
        }else if(lazy[idx] %3 == 2){
            int temp = seg[idx].zero;
            seg[idx].zero = seg[idx].one;
            seg[idx].one = seg[idx].two;
            seg[idx].two = temp;
        }
        if(ss != se){
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if(qs > se || qe < ss)
        return 0;

    if(qs <= ss && qe >= se){
        return seg[idx].zero;
    }
    int mid = (ss+se)/2;

    return query(ss, mid, 2*idx+1, qs, qe) + query(mid+1, se, 2*idx+2, qs, qe);
}
void printarr(int n){
    for (int i = 0; i < n; i++){
        cout << query(0, n-1, 0, i, i) << " ";
    }
    cout  <<endl;

}
int main()
{
    int t, n, q, p, x, y;
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(seg, 0, sizeof seg);
        memset(lazy, 0, sizeof lazy);
        scanf("%d%d", &n, &q);
        construct(0, n-1, 0);
        printf("Case %d:\n", i+1);
        //printarr(n);
        for(int j = 0; j < q; j++){
            scanf("%d%d%d", &p, &x, &y);
            if(p == 1){
                printf("%lld\n", query(0, n-1, 0, x, y));
            }else{
                update(0, n-1, 0, x, y);
            }
            //printarr(n);
        }
        //printarr(n);
    }
}
