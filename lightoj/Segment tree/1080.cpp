#include<bits/stdc++.h>

using namespace std;

int seg[1000010], lazy[1000010];
char arr[100010];

void construct(int seg_start, int seg_end, int i){
    if (seg_start == seg_end){
        seg[i] = arr[seg_start] - '0';
        return;
    }
    int mid = (seg_start + seg_end)/2;
	construct(seg_start, mid, 2*i+1);
	construct(mid+1, seg_end, 2*i + 2);
	return;
}

int query(int seg_start, int seg_end, int i, int qidx){
    if (lazy[i] != 0){
        if (seg_start != seg_end){
            lazy[2*i+1] ^= 1;
            lazy[2*i+2] ^= 1;
        }else{
            seg[i] ^= 1;
        }
        lazy[i] = 0;
    }
    if (qidx < seg_start || qidx  > seg_end){
        return 0;
    }
    if (seg_start == seg_end){
        if (qidx == seg_start){
            return seg[i];
        }
    }
    int  mid = (seg_start+seg_end)/2;
    return query(seg_start, mid, 2*i+1, qidx) + query(mid+1, seg_end, 2*i+2, qidx);
}

void update(int seg_start, int seg_end, int i, int sindex, int eindex){
    if (lazy[i] != 0){
        if (seg_start == seg_end){
            seg[i] = seg[i]^1;
        }
        if (seg_start != seg_end){
            lazy[2*i+1] ^= 1;
            lazy[2*i+2] ^= 1;
        }
        lazy[i] = 0;
    }
    if(eindex < seg_start || sindex > seg_end)
		return;
	if(seg_start >= sindex && seg_end <= eindex){
        lazy[i] = lazy[i]^1;
        return;
	}
	int mid = (seg_start +seg_end)/2;
	update(seg_start, mid, 2*i+1, sindex, eindex);
	update(mid+1, seg_end, 2*i+2, sindex, eindex);
}

void print(void){

    for (int i = 0; i <=24; i++){
        cout  << seg[i] ;
    }
    cout << endl;

    for (int i = 0; i <=24; i++){
        cout  << lazy[i] ;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++){
        scanf("%s", arr);
        int n = strlen(arr);
        memset(seg, 0, sizeof seg);
        memset(lazy, 0 , sizeof lazy);
        int q, I, J;
        construct(0, n-1, 0);
        scanf("%d", &q);
        printf("Case %d:\n", i);
        while(q--){
            char ch;
            scanf(" %c", &ch);
            if (ch == 'I'){
                scanf("%d%d", &I, &J);
                update(0, n-1, 0, I-1, J-1);
                //print();
            }else{
                scanf("%d", &I);
                printf("%d\n", query(0, n-1, 0, I-1));
                //print();
            }
        }
    }
}
