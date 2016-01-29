#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m, k, d;
struct node1{
    int pt;
    ll cost;
    bool prop;
};

struct node2{
    int pt;
    ll cost;
    int d;
};

vector<vector<node1> > g;
class cmpc{
public:
    bool operator() (node2 &a, node2 &b){
        return a.cost > b.cost;
    }
};

ll dikstra(void){

    priority_queue<node2, vector<node2>, cmpc> pq;
    ll cost[n][d+1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= d; j++)
            cost[i][j] = LLONG_MAX;
    }
    node2 temp;
    temp.cost = 0;
    temp.d = 0;
    temp.pt = 0;

    pq.push(temp);
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        if(temp.d > d){
            continue;
        }
        if(cost[temp.pt][temp.d] <= temp.cost)
            continue;
        cost[temp.pt][temp.d] = temp.cost;

        int x = temp.pt;
        int c = temp.cost;
        temp.d++;
        for(int i = 0; i < g[x].size(); i++){
            node1 temp1 = g[x][i];
            if(temp1.prop){
                temp.pt = temp1.pt;
                if(cost[temp.pt][temp.d] > temp1.cost + c){
                    temp.cost = temp1.cost + c;
                    pq.push(temp);
                }
            }else{
                temp.pt = temp1.pt;
                if(cost[temp.pt][temp.d-1] > temp1.cost + c){
                    temp.cost = temp1.cost + c;
                    temp.d--;
                    pq.push(temp);
                    temp.d++;
                }
            }
        }
    }
    ll ans = cost[n-1][0];
    for(int i = 0; i <= d; i++){
   //     cout << cost[n-1][i] << " ";
        ans = min(ans, cost[n-1][i]);
    }
    //cout << endl;
    if(ans == LLONG_MAX){
        return -1;
    }else{
        return ans;
    }

}



int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        scanf("%d%d%d%d", &n, &m, &k, &d);
        int u, v, w;
        g.resize(n);
        for(int j = 0; j < m; j++){
            scanf("%d%d%d", &u, &v, &w);
            node1 temp;
            temp.pt = v;
            temp.cost = w;
            temp.prop = false;
            g[u].push_back(temp);
        }
        for(int j = 0; j < k; j++){
            scanf("%d%d%d", &u, &v, &w);
            node1 temp;
            temp.pt = v;
            temp.cost = w;
            temp.prop = true;
            g[u].push_back(temp);
        }
       /* for(int l = 0; l < g.size(); l++){
            for(int m = 0; m < g[l].size(); m++){
                cout << g[l][m].pt << " " << g[l][m].cost << " " << g[l][m].prop << endl;
            }
            cout << endl;
        }
*/
        ll ans = dikstra();
        if(ans == -1){
            printf("Case %d: Impossible\n", i);
        }else{
            printf("Case %d: %lld\n", i, ans);
        }
        g.clear();
    }

}
