#include<bits/stdc++.h>

using namespace std;

long long n;

class ret{
public:
	long long count;
	long long branch;

};

class sol{
public:
    long long n;
    bitset<32> bin;
    int st;
    int k;
    ret dp[2][34];
    sol(long long n){
        this->n = n;
        bin = bitset<32>(n);
        int i;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 33; j++){
                dp[i][j].count = -1;
                dp[i][j].branch  = -1;
            }
        }
        for(i = 31; i >= 0; i--){
            if(bin[i] == true){
                break;
            }
        }
        k = i;
    /*    cout << k << endl;
        for(int i = 0; i < 32; i++)
            cout << bin[i] << " ";
        cout << endl;
*/
    }

    ret rec(int last, int i, bool x){
        if(i < 0){
            ret ans;
            ans.count = 0;
            ans.branch = 1;
            return ans;
        }
        if(x == false){
            if(dp[last][i].count != -1)
                return dp[last][i];
        }
        ret ans;
        ans.count = 0;
        ans.branch = 0;
        if(x == true){
            if(bin[i] == 1){
                ret temp1 = rec(1, i-1, true);
                ret temp2 = rec(0, i-1, false);
                if(last == 1){
                    ans.count += (temp1.count+ temp1.branch + temp2.count);
                    ans.branch += (temp1.branch + temp2.branch);
                }else{
                    ans.count += (temp1.count + temp2.count);
                    ans.branch += temp1.branch + temp2.branch;
                }
            }else{
                ans = rec(0, i-1, true);
            }
        }else{
            ret temp1 = rec(1, i-1, false);
            ret temp2 = rec(0, i-1, false);
            if(last == 1){
                ans.count += (temp1.count + temp1.branch + temp2.count);
                ans.branch += (temp1.branch + temp2.branch);
            }else{
                ans.count += (temp1.count + temp2.count);
                ans.branch += (temp1.branch + temp2.branch);
            }
        }
        if(x == false){
            dp[last][i] = ans;
        }
        return ans;
    }
};

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        sol *x = new sol(n);
        //cout << x->bin << " " << x->k << endl;
        ret x1 = x->rec(1, x->k-1, true);
        ret x2 = x->rec(0, x->k-1, false);
        cout << "Case " << i+1 << ": " << x1.count+x2.count << endl;
    }
}
