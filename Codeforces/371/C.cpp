#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
class trie{
public:
    ll val;
    trie* l;
    trie* r;

    trie(int val){
        this->val = 0;
        l = NULL;
        r = NULL;
    }

    void insert(ll num){
        trie *t = this;
        while(num >= 10){
            ll rem = num%10;
            num = num/10;
            if(rem%2 == 1){
                if(t->l == NULL){
                    t->l = new trie(0);
                }
                t = t->l;
            }else{
                if(t->r == NULL){
                        t->r = new trie(0);
                }
                t = t->r;
            }
        }
        if(num%2 ==1){
            if(t->l == NULL){
                t->l = new trie(0);
            }
            t = t->l;
        }else{
            if(t->r == NULL){
                t->r = new trie(0);
            }
            t = t->r;
        }
        t->val++;
    }

    void del(ll num){
        trie *t = this;
        while(num >= 10){
            ll rem = num%10;
            num = num/10;
            if(rem %2 == 1){
                t = t->l;
            }else{
                t = t->r;
            }
        }
        if(num %2 == 1){
            t = t->l;
        }else{
            t = t->r;
        }
        //cout << " val " <<  t->val << endl;
        t->val--;
    }

    int query(ll s){
        ll ans = 0;
        trie *t = this;
        while(s >= 10){
            ll rem = s%10;
            s = s/10;
            if(rem == 1){
                if(t->l != NULL){
                    t = t->l;
                    //ans += t->val;
                }else{
                    break;
                }
            }else{
                if(t->r != NULL){
                    t = t->r;
                    //ans += t->val;
                }else{
                    break;
                }
            }
        }
        if(s >= 10)
            return 0;
        if(s == 1){
            if(t->l != NULL){
                t = t->l;
                ans += t->val;
            }else{
                return 0;
            }
        }
        while(t->r != NULL){
            t = t->r;
            ans += t->val;
        }
        return ans;
    }
    void print(){
        trie* t = this;

        cout << "Printing: " << endl;
        while(t != NULL){
            if(t -> l != NULL){
                t = t-> l;
                cout << t->val << " ";
            }else if(t -> r != NULL){
                t = t-> r;
                cout << t->val << " ";
            }else{
                t = NULL;
            }
        }
        cout << endl;
    }
};

int main()
{
    trie* T = new trie(-1);
    ll t, x;
    char ch;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> ch >> x;
        if(ch == '+'){
            T->insert(x);
        }else if(ch == '-'){
            T->del(x);
        }else{
            cout << T->query(x) <<endl;
        }
    }


}
