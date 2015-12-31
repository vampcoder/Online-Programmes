#include<cstring>
#include<iostream>
#include<map>
#include<set>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std;


int main(){
    string a,b;
    int t;
    scanf("%d", &t);
    vector<string> vect1;
    vector<string> vect2;
    int i = 0;
    while(t--){
        cin >> a >> b;
        vector<string>::iterator it = find(all(vect2), a);
        if(it != vect2.end()){
            *it = b;
        }else{
            i++;
            vect1.push_back(a);
            vect2.push_back(b);
        }
    }
    cout << i << endl;
    while(i--){
       cout << vect1[i]<< " "<<vect2[i]<< endl;
    }
}
