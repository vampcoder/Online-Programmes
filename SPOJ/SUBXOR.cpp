#include<bits/stdc++.h>

using namespace std;

int arr[1000010];

class trie{
public:
    int val;
    int cnt;
    trie* l;
    trie* r;

    trie(int val){
        this->val = val;
        cnt = 0;
        l = NULL;
        r = NULL;
    }

    void insert(int num){
        bitset<32> bin(num);
        trie *t = this;

        for(int i = 31; i >= 0; i--){
            if(bin[i] == 0){
                if(t->l ==NULL){
                    t->l = new trie(0);
                }
                t = t->l;
                t->cnt++;

            }else{
                if(t->r == NULL){
                    t->r = new trie(1);
                }
                t = t->r;
                t->cnt++;
            }
        }
    }

    long long count(int num, int k){
        bitset<32> kin(k);
        bitset<32> bin(num);
        int ans = 0;
        trie *t = this;
        for(int i = 31; i >= 0; i--){
            int q = bin[i];
            int p = kin[i];

            if(q == 1 && p ==1){
                if(t->r != NULL){
                    ans += t->r->cnt;
                }
                if(t->l == NULL)
                    break;
                else
                    t = t->l;
            }
            if(q == 1 && p ==0){
                if(t->r == NULL)
                    break;
                else
                    t = t->r;
            }
            if(q == 0 && p ==1){
                if(t->l != NULL){
                    ans += t->l->cnt;
                }
                if(t->r == NULL)
                    break;
                else
                    t = t->r;
            }
            if(q == 0 && p ==0){
                if(t->l == NULL)
                    break;
                else
                    t = t->l;
            }
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

    int t;
    cin >> t;
    while(t--){
        trie* T = new trie(-1);
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> arr[i];

        }
        //T->print();
        T->insert(0);
        long long p = 0, ans = 0;
        for(int i = 0; i < n; i++){
            p = p^arr[i];
            ans += T->count(p, k);
            T->insert(p);
        }
        cout << ans << endl;
    }
}
