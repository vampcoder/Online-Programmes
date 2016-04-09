#include<bits/stdc++.h>

using namespace std;

string pat, text;

vector<int> prefixFunc(){
    int n = pat.length();
    vector<int> v(n);
    v[0] = 0;
    for(int i = 1, j = 0; i < n; i++){
        if(pat[i] == pat[j]){
            v[i] = j+1;
            j++;
        }else{
            while(j > 0 && pat[i] != pat[j]){
                j = v[j-1];
            }
            if(j == 0){
                if(pat[i] != pat[j])
                    v[i] = 0;
                else{
                    v[i] = v[j]+1;
                    j++;
                }
            }else{
                v[i] = v[j]+1;
                j++;
            }
        }
    }
    /*for(int i = 0; i < n; i++){
        cout << v[i];
    }
    cout << endl;
*/
    return v;
}

vector<int> patternSearching(vector<int> &p){

    int i = 0, j = 0;
    int l = text.length();
    int l1 = pat.length();
    vector<int> v;
    while(i < l){
        if(text[i] == pat[j]){
            i++;
            j++;
            if(j == l1){
                v.push_back(i-l1);
                j = p[j-1];
            }
        }else if(j != 0){
            j = p[j-1];
        }else{
            i++;
    }
        }
    /*for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    */return v;
}


int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> text >> pat;
        vector<int> v = prefixFunc();
        vector<int> ans = patternSearching(v);
        int a = ans.size();
        printf("Case %d: %d\n", i, a);
    }


}
