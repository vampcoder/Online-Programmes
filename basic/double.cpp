#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> dq;
    int t;
    cin >> t;
    string  a;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i  << ":\n";
        int n, m, l, r;
        cin >>n >> m;
        int c = n;
        l = 0;
        r = 0;
        for(int j = 0; j < m; j++){
        cin >> a;
        if(a[1] == 'u'){
            int x;
            cin >> x;
            if(a[4] == 'L' && n){
                dq.push_front(x);
                cout << "Pushed in left: "<< x << endl;
                n--;
                l++;
            }else if(a[4] == 'R' && n){
                dq.push_back(x);
                cout << "Pushed in right: "<< x << endl;
                n--;
                r++;
            }else{
                cout << "The queue is full" << endl;
            }
        }else if(a[1] == 'o'){
            if(a[3] == 'L' && c > n && l >= 0){
                cout << "Popped from left: " << dq.front() << endl;
                dq.pop_front();
                n++;
                l--;
            }else if(a[3] == 'R' && c > n && r >= 0){
                cout << "Popped from right: " << dq.back() << endl;
                dq.pop_back();
                n++;
                r--;
            }else{
                cout << "The queue is empty"<< endl;
            }
        }
        }
    }
}
