#include<bits/stdc++.h>

using namespace std;
long long n;

class sol{
public:
    long long n;
    bitset<32> bin;
    int st;
    int k;
    sol(long long n){
        this->n = n;
        bin = bitset<32>(n);
        int i;

        for(i = 0; i < 32; i++){
            if(bin[i] == true){
                break;
            }
        }
        k = i;
    }

    long long rec(int last, int i, bool x){
        if(i >= 32){
            return 1;
        }
        int ans = 0;
        if(bin[i] == 1){
            if(last == 1){
                ans += rec(1, i+1, x)+ rec(0,i+1, true);
            }else{
                ans += (rec(1, i+1, x)+rec(0, i+1, true));
            }
        }else{
            if(x){
                ans += (rec(1, i+1, x)+rec(0, i+1, x));
            }else{
                ans += rec(0, i+1, x);
            }
        }
        //cout << ans << endl;
        return ans;
    }
};


int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        sol *x = new sol(n);
        cout << x->bin << endl;
       //cout << x->rec(0, x->k, false) << endl;
    }
}
