#include<bits/stdc++.h>

using namespace std;

void process(int q, int l){
    q = q-l;
    vector<int> div;
    int p = sqrt(q);
    for(int i = 1; i <= p; i++){
        if(q%i == 0){
            if(i > l)
                div.push_back(i);
            if(p != i){
                if(q/i > l)
                    div.push_back(q/i);
            }
        }
    }
    sort(div.begin(), div.end());

    bool flag = true;
    for(int i = 0; i < div.size(); i++){
            printf(" %d", div[i]);
            flag = false;
    }
    if(flag){
        printf(" impossible");
    }
}



int main()
{
    int t, p, l;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d%d", &p, &l);
        printf("Case %d:", i);
        process(p, l);
        printf("\n");
    }
}
