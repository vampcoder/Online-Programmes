#include<bits/stdc++.h>

using namespace std;

long long arr[1000010];

int seg[1000010];

void construct(int ss, int se, int i){
    if(ss == se){
        seg[i] = ss;
        return;
    }
    int mid = (ss+se)/2;
    construct(ss, mid, 2*i+1);
    construct(mid+1, se, 2*i+2);
    int m = min(arr[seg[2*i+1]], arr[seg[2*i+2]]);
    if (m == arr[seg[2*i+1]]) seg[i]= seg[2*i+1];
    else seg[i] = seg[2*i+2];
}

int query(int ss, int se, int i, int qs, int qe){
    if(qs > se || qe < ss)
        return -1;
    if(qs <= ss && qe >= se){
        return seg[i];
    }
    int mid = (ss+se)/2;
    int q1 = query(ss, mid, 2*i+1, qs, qe);
    int q2 = query(mid+1, se, 2*i+2, qs, qe);
    if (q1 == -1){
        return q2;
    }
    if(q2 == -1){
        return q1;
    }
    int m = min(arr[q1], arr[q2]);
    if(m == arr[q1]) return q1;
    else return q2;
}

long long findArea(int ss, int se, int n){
    if (ss > se){
        return 0;
    }
    int m = query(0, n-1, 0, ss, se);
    //cout << m << endl;
    long long area = max(findArea(ss, m-1, n), findArea(m+1, se, n));
    if (area < arr[m]*(se-ss+1)){
        area = arr[m]*(se-ss+1);
    }
    return area;
}

int main()
{
    int t, n;
    cin >> t;
    for(int i = 1; i <= t; i++){
        memset(seg, 0, sizeof seg);
        cin >> n;
        for(int j = 0; j < n; j++){
            scanf("%lld", &arr[j]);
        }
        construct(0, n-1, 0);
        //cout << "Done" << endl;
        printf("Case %d: %lld\n", i, findArea(0, n-1, n));
    }

}

