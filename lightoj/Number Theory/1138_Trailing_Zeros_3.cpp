#include<bits/stdc++.h>

using namespace std;

vector<int>v;

long long func(long long num){
    long long n = 5;
    long long ans = 0;
    while(n <= num){
        ans += num/n;
        n *= 5;
    }
    return ans;
}

long long binarySearch(long long q){
    long long low = 0;
    long long high = 1000000000;

    bool flag = false;
    long long mid;
    while(low < high){
        mid = (low+high)/2;
        long long ret = func(mid);
        if(ret == q){
            flag = true;
        }
        if(ret < q){
            low = mid + 1;
        }else{
            high = mid;
        }
    }
    if(flag){
        return low;
    }else{
        return -1;
    }
}


int main(){
    //func();
//    cout << v[v.size()-1].first  << " " << v[v.size()-1].second << endl;;
    long long t, q;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> q;
        cout << "Case "<< i << ": ";
        int ans = binarySearch(q);
        if(ans == -1){
            cout << "impossible\n";
        }else{
            cout << ans << endl;
        }
    }
}
