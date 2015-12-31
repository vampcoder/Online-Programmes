#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char a[n+1];
    scanf("%s", &a);
    int z = 0, o = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == '0')
            z++;
        if(a[i] == '1')
            o++;
    }
    cout << abs(z-o);
}
