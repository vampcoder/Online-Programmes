#include<bits/stdc++.h>

using namespace std;

string pat;

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



int main()
{
    cin >> pat;
    vector<int> v = prefixFunc();
    int l = v.size();
    int c = v[l-1];
    if (c == 0){
        cout << "Just a legend" << endl;
        return 0;
    }
    for(int i = 1; i < v.size()-1; i++){
        if(v[i] == c){
            for(int j = 0; j < c; j++){
                cout << pat[j];
            }
            cout << endl;
            return 0;
        }
    }
    c = v[c-1];
    if(c != 0){
        for(int j = 0; j < c; j++){
            cout << pat[j];
        }
        cout << endl;
        return 0;
    }

    cout << "Just a legend" << endl;
    return 0;
}
