
#include<bits/stdc++.h>

using namespace std;

struct node{
    int l;
    int r;
    int i;
    int ans;
};
int t, n, q;
int freq[1000010];
int arr[30010];
node nde[200010];
int ans = 0;

bool cmpc(node a, node b){
    if(a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
}

bool cmpc1(node a, node b){
    return a.i < b.i;
}
bool cmpc2(node a, node b){
    return a.r < b.r;
}

void add(int pos){
    freq[pos]++;
    if(freq[pos] == 1)
        ans++;
}

void rem(int pos){
    freq[pos]--;
    if(freq[pos] == 0){
        ans--;
    }
}
void print1(){
    for(int i = 0; i < q; i++){
        cout << nde[i].l << " " << nde[i].r << endl;
    }

}

void print(int x){
    for(int i = 1; i < x; i++){
        cout << freq[i] << " ";
    }
    cout << endl;

}
int main()
{
    memset(freq, 0, sizeof freq);
    scanf("%d", &n);
    for(int j = 0; j < n; j++){
        scanf("%d", &arr[j]);
    }
    scanf("%d", &q);
    for(int j = 0; j < q; j++){
        scanf("%d%d", &nde[j].l, &nde[j].r);
        nde[j].i = j;
    }
    int sq = sqrt(n)+1;
    int div = n/sq;
    //cout << sq << " " << div << endl;
    sort(nde, nde + q, cmpc);
//        print1();
//        cout << endl;
    int lk = 0;
    int rk = 0;
    for(int j = 1; j <= div+1; j++){
        int j2 = sq*j;
        while(rk < q &&  nde[rk].l <= j2){
            rk++;
        }
        sort(nde+lk, nde + rk, cmpc2);
        lk = rk;
    }
//        print1();
//        cout << endl;
    int k = 0;
    ans = 0;
    int ll = -1;
    int lr = -1;
    for(int j = 1; j <= div+1; j++){
        while(k < q && (nde[k].l-1) <= j*sq){
            if(ll != -1 && lr != -1){
                while(ll < nde[k].l-1){
                    rem(arr[ll]);
                    ll++;
                }
                //cout << ll << " " << lr << endl;
                while(lr > nde[k].r-1){
                    rem(arr[lr]);
                    lr--;
                }
                //cout << ll << " " << lr << endl;
                while(ll > nde[k].l-1){
                    ll--;
                    add(arr[ll]);
                }
                //cout << ll << " " << lr << endl;
                while(lr < nde[k].r-1){
                    lr++;
                    add(arr[lr]);
                }
                //cout << ll << " " << lr << endl;
            }else{
                for(int J = nde[k].l-1; J <= nde[k].r-1; J++){
                    add(arr[J]);
                }
                ll = nde[k].l-1;
                lr = nde[k].r-1;
                //cout << ll << " " << lr << endl;
            }
            nde[k].ans = ans;

            k++;
            //print(6);
        }
    }
    sort(nde, nde+q, cmpc1);
    for(int j = 0; j < q; j++){
        printf("%d\n", nde[j].ans);
    }
}
