#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x;
    int f = a[0];
    int l = n - a[0];
    int i;
    for(i = 0; i < n; i++){
        if(i%2==0)
            x = (a[i]-f);
        else
            x = (a[i] + f);
        if(x < 0)
            x += n;
        if(x > n)
            x -= n;
        if(x == i)
            continue;
        else
            break;
    }
    if(i == n && x == n-1){
        cout << "Yes";
    }else{
        cout << "No";
    }
//    }else{
//        for(i = 0; i < n; i++){
//                if(i % 2 == 0)
//                    x = (a[i] + l)%n;
//                else
//                    x = (a[i] - l)%n;
//                if(x == i)
//                    continue;
//                else
//                    break;
//        }
//        if(i == n && x == n-1)
//            cout << "Yes";
//        else
//            cout << "No";
//    }
}

