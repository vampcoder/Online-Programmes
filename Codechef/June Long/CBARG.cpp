#include<iostream>

using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        long long int a = 0, b, allo = 0;
        while(n--){
            b = a;
            cin >> a;
            if(a > b)
                allo += (a-b);
        }
        cout << allo << endl;
    }
}
