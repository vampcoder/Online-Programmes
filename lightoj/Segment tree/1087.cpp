#include<bits/stdc++.h>

using namespace std;
struct node{
    int l;
    int r;
    int val;
};

int arr[100010];
struct node seg[1000010];
int n;

void construct(int ss, int se, int i){
    if(ss == se){
        seg[i].val = arr[ss];
        seg[i].l = 0;
        seg[i].r = 0;
        return;
    }
    int mid = (ss+se)/2;
    construct(ss, mid, 2*i+1);
    construct(mid, se, 2*i+2);
    seg[i].l = seg[2*i+1].l+seg[2*i+1].r + 1;
    seg[i].r = seg[2*i+2].l+ seg[2*i+2].r + 1;
}

int delentry(int ss, int se, int i, int k){
    if(k == 1){
        return seg[i];
    }

    int mid = (ss+ se)/2;

    if(k <= seg[i].l){
        seg[i].l--;
        return delentry(ss, mid, 2*i+1, k);
    }else{
        seg[i].r--;
        return delentry(mid, se, 2*i+2, k-l);
    }
}

void addEntry(int ss, int se, int i, int q, int val){
    if (q < ss || q > se){
        return;
    }
    if(ss == se){
        seg[i].val = val;
        return;
    }

    int mid = (ss +se)/2;
    addEntry(ss, mid, 2*i+1, q, val);
    addEntry(mid, se, 2*i+1, q, val);
    seg[i].l = seg[2*i+1].l+seg[2*i+1].r + 1;
    seg[i].r = seg[2*i+2].l+ seg[2*i+2].r + 1;


}


int main()
{
    int t, q;
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(seg, 0, sizeof seg);
        cin >> n >> q;

    }

}
