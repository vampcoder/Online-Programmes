#include<bits/stdc++.h>

using namespace std;

vector<int> divisors[100010];

double dp[100010];

void preprocess(){
    divisors[1].push_back(1);
    divisors[2].push_back(2);
    divisors[3].push_back(3);
    for(int i = 4; i < 100010; i++){
        int l = sqrt(i) + 1;
        for(int j = 2; j < l; j++){
            if(i % j == 0){
                divisors[i].push_back(j);
                if(j == i/j)
                    continue;
                divisors[i].push_back(i/j);
            }
        }
        divisors[i].push_back(i);
    }
}

void print(int n){
    for(int i = 0; i < divisors[n].size(); i++){
        cout << divisors[n][i] << " ";
    }
    cout << endl;

}

double func(int num){
    if(num == 1)
        return 0.0;
    if(dp[num] > -1){
       return dp[num];
    }
    double ans = 0.0;
    for(int i = 0; i < divisors[num].size(); i++){
        if(divisors[num][i] == num)
            continue;
        ans += func(divisors[num][i]);
    }
    ans += ((double)(divisors[num].size()+1));
    ans /= ((double)divisors[num].size());

    return dp[num] = ans;
}

int main()
{
    preprocess();
    int t, n;
    cin >> t;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        //print(n);
        printf("Case %d: %0.10lf\n", i+1, func(n));
    }
}
