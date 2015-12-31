#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    map<string, int> m;
    m["balck"] = 1;
    m["blue"] = 2;
    m["red"] = 3;
    m["green"] = 4;
    m["yellow"] = 5;
    m["orange"] = 6;
    string str;
    while(t--){
        int a[7];
        for(int i = 1; i < 7; i++){
            cin >> str;
            a[i] = m[str];
        }
        bool temp = false;
        if(a[1] == a[6]){
            if(a[1] == a[3] || a[1] == a[4])
                temp = true;
        }
        if(a[1] == a[5]){
            if(a[1] == a[4] || a[1] == a[3])
                temp = true;
        }
        if(a[2] == a[6]){
            if(a[2] == a[3] || a[2] == a[4])
                temp = true;
        }
        if(a[2] == a[5]){
            if(a[2] == a[4] || a[2] == a[3])
                temp = true;
        }
        if(temp)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
