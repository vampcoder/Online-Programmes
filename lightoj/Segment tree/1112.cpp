#include<bits/stdc++.h>

using namespace std;

int seg[1000010];
int arr[100010];

void construct(int ss, int se, int i){
    if (ss == se){
        seg[i] = arr[ss];
        return;
    }
    int mid = (ss+se)/2;

    construct(ss, mid, 2*i+1);
    construct(mid+1, se, 2*i+2);

    seg[i] = seg[2*i+1] + seg[2*i+2];
}

void update(int ss, int se, int i, int val, int uindex){

    if (uindex > se || uindex < ss){
        return;
    }

    if (ss == se){
        seg[i] += val;
        return;
    }

    seg[i] += val;
    int mid = (ss+se)/2;

    update(ss, mid, 2*i+1, val, uindex);
    update(mid+1, se, 2*i+2, val, uindex);
}

int query(int ss, int se, int i, int qs, int qe){

    if (qs > se || qe < ss){
        return 0;
    }

    if (ss >= qs && se <= qe){
        return seg[i];
    }
    int mid = (ss+se)/2;

    return query(ss, mid, 2*i+1, qs, qe) + query(mid+1, se, 2*i+2, qs,qe);
}
void print(){
    for(int i = 0; i <= 4; i++){
        cout << seg[i] << " ";
    }
    cout << endl;

}


int main()
{
    int t;
    cin >> t;
    int n, q;
    for (int i = 1; i <= t; i++){
        cin >> n >> q;
        memset(seg, 0, sizeof seg);
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }
        construct(0, n-1, 0);
        printf("Case %d:\n", i);
        int p, I, J;
        for(int j = 0; j < q; j++){
            //print();
            scanf("%d", &p);
            if(p == 1){
                scanf("%d", &I);
                update(0, n-1, 0, -1*arr[I], I);
                printf("%d\n", arr[I]);
                arr[I] = 0;
            }
            if(p == 2){
                scanf("%d%d", &I, &J);
                update(0, n-1, 0, J, I);
                arr[I] += J;
            }
            if(p == 3){
                scanf("%d%d", &I, &J);
                printf("%d\n", query(0, n-1, 0, I, J));
            }
        }
    }
}
