#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, x, last;
    cin >> n >> k;
    int gcount = 0;
    int b = 0;
    for(int i = 0; i < k; i++){
        int m;
        cin >> m;
        last = -2;
        bool flag = true;
        int count = 0;
        int rest = 1;

        for(int j = 0; j < m; j++){

            cin >> x;
            if(x == last+1 && flag){
                continue;
            }else{
                if(j == 0){
                    last = x;
                    continue;
                }else{
                    count += 1;
                    rest += 1;
                    flag = false;
                }
            }
            last = x;
        }
        if(count == 0)
            b += 1;
        gcount += count;
        gcount += rest;
    }
    gcount += (k-b+1);
    cout << gcount;
}
