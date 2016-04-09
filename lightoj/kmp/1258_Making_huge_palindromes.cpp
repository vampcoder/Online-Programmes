#include<bits/stdc++.h>

using namespace std;

vector<int> prefixFunc(string pat){
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
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        string str,pat;
        cin >> str;
        int l = str.length();
        for(int j = l-1; j >= 0; j--){
            pat += str[j];
        }
        pat += '$';

        pat += str;

        vector<int> v = prefixFunc(pat);
        /*for(int j = 0; j < v.size(); j++)
            cout << v[j];
        cout << endl;
        */int a = v[v.size()-1];
        cout << "Case " << i << ": " << 2*l-a << endl;



    }
}
