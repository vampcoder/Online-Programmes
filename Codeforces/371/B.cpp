#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    int a[100010];
    cin >> n;
    set<int> s;
    int idx = 0;
    while(n--){
        cin >> x;
        s.insert(x);
        a[idx++] = x;
    }
    if(s.size() < 3){
        cout << "YES";
        return 0;
    }

    if(s.size() == 3){
        set<int>::iterator it = s.begin();
        int arr[3];
        int i = 0;
        while(it != s.end()){
            arr[i++] = *it;
            //cout << *it << " ";
            it++;
        }
        //cout << endl;
        if(arr[2]-arr[1] == arr[1]-arr[0]){
            cout << "YES";
        }else{
            cout << "NO";
        }
    }else{
        cout << "NO";
    }

}
