#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

struct node{
    int l;
    int r;
    ll val;
    int cnt;
};

ll arr[160010];
struct node seg[700010];
ll n,count1;

void construct(int ss, int se, int i){
    if(ss == se){
        seg[i].val = arr[ss];
        seg[i].l = 0;
        seg[i].r = 0;
        if(arr[ss] != 0)
            seg[i].cnt = 1;
        else
            seg[i].cnt = 0;
        return;
    }
    int mid = (ss+se)/2;
    construct(ss, mid, 2*i+1);
    construct(mid+1, se, 2*i+2);
    seg[i].l = seg[2*i+1].cnt;
    seg[i].r = seg[2*i+2].cnt;
    seg[i].cnt = seg[i].l + seg[i].r;
}

ll delentry(int ss, int se, int i, int k){
    if (ss < 0 || se > 160000)
        return 0;
    if(ss == se){
        seg[i].cnt = 0;
        return seg[i].val;
    }
    int mid = (ss+ se)/2;
    seg[i].cnt--;

    if(k <= seg[i].l){
        seg[i].l--;
        return delentry(ss, mid, 2*i+1, k);
    }else{
        seg[i].r--;
        return delentry(mid+1, se, 2*i+2, k-seg[i].l);
    }
}

void addEntry(int ss, int se, int i, int q, int val){
    if (q < ss || q > se){
        return;
    }
    if(ss == se){
        seg[i].val = val;

        seg[i].cnt = 1;
        seg[i].l = 0;
        seg[i].r = 0;
        return;
    }

    int mid = (ss +se)/2;
    addEntry(ss, mid, 2*i+1, q, val);
    addEntry(mid+1, se, 2*i+2, q, val);
    seg[i].l = seg[2*i+1].cnt;
    seg[i].r = seg[2*i+2].cnt;
    seg[i].cnt = seg[i].l + seg[i].r;
}


int main()
{
    ll t, q, p;
    cin >> t;
    for(int i = 0; i < t; i++){
        printf("Case %d:\n", i+1);
        memset(seg, 0, sizeof seg);
        memset(arr, 0, sizeof arr);
        scanf("%lld%lld", &n, &q);
        count1 = n;
        char ch;
        for(int j = 0; j < n; j++){
            scanf("%lld", &arr[j]);
        }
        if(n != 0)
            construct(0, 160000, 0);
        for(int j = 0; j < q; j++){
            getchar();
            scanf("%c %d", &ch, &p);
            if(ch == 'a'){
                n++;
                addEntry(0, 160000, 0, n-1, p);
                count1++;
            }else{
               // cout << "count " << count1 << endl;
                if(count1 < p || p <= 0){
                    printf("none\n");
                }else{
                    int ans = delentry(0, 160000, 0, p);
                    printf("%d\n", ans);
                    count1--;
                }
            }
        }
    }
}
