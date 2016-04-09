#include<bits/stdc++.h>

using namespace std;

long long arr[1000010];

class trie{
public:
    int val;
    trie* l;
    trie* r;

    trie(int val){
        this->val = val;
        l = NULL;
        r = NULL;
    }

    void insert(long long num){
        bitset<64> bin(num);
        trie *t = this;

        for(int i = 63; i >= 0; i--){
            if(bin[i] == 0){
                if(t->l ==NULL){
                    t->l = new trie(0);
                }
                t = t->l;
            }else{
                if(t->r == NULL){
                    t->r = new trie(1);
                }
                t = t->r;
            }
        }
    }

    long long count(int num){
        bitset<64> bin(num);
        int ans[64];
        trie *t = this;
        for(int i = 63; i >= 0; i--){
            if(bin[i] == 0){
                if(t->r != NULL){
                    //cout << "r ";
                    t = t->r;
                    ans[i] = 1;
                }else{
                    //cout << "l ";
                    t = t->l;
                    ans[i] = 0;
                }
            }else{
                if(t-> l != NULL){
                    //cout << "l ";
                    t = t-> l;
                    ans[i] = 0;
                }else{
                    //cout << "r ";
                    t = t->r;
                    ans[i]=1;
                }
            }
        }


        long long ret = 0, mul =1;
        for(int i = 0; i < 32; i++){
            //cout << ans[i] << " ";
            ret += mul*ans[i];
            mul *= 2;
        }
        //cout << endl;


        return ret;
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
    long long n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //T->print();
    T->insert(0);
    long long p = 0, ans = 0;
    for(int i = 0; i < n; i++){
        p = p^arr[i];
        T->insert(p);
        ans = max(ans, p^T->count(p));
    }
    cout << ans << endl;
}
