#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, u, v, w, q, c, s, t;

struct node{
    int pt;
    int cost;
    int fuel;

    node() {}
    node(int a, int b, int c) : pt(a), cost(b), fuel(c) {}

    bool operator< (const node& a) const{
        return cost > a.cost;
    }
};

vector<int> price;
vector<vector<node> > g;

int dikstra(void){

    int cost[n][101];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 101; j++)
            cost[i][j] = INT_MAX;
    }
    priority_queue<node> pq;

    node temp(s, 0, 0);
    cost[s][0] = 0;
    pq.push(temp);
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();

        if(cost[temp.pt][temp.fuel] < temp.cost)
            continue;

        if(temp.pt == t)
            return cost[temp.pt][temp.fuel];
        int co = temp.cost;
        int fuel = temp.fuel;
        int x = temp.pt;
       // cout << temp.pt << " " << temp.cost << " " << temp.fuel << endl;
        for(int i = 0; i < g[x].size(); i++){
            node temp1 = g[x][i];
            if(temp1.cost > c)continue;
            if(fuel >= temp1.cost && cost[temp1.pt][fuel-temp1.cost] > cost[x][fuel]){
                cost[temp1.pt][fuel-temp1.cost] = cost[x][fuel];
                pq.push(node(temp1.pt, cost[temp1.pt][fuel-temp1.cost], fuel-temp1.cost));
            }
        }
        if(fuel < c){
            cost[x][fuel+1] = cost[x][fuel] + price[x];
            pq.push(node(x, cost[x][fuel+1], fuel+1));
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> n >> m;
        price.resize(n);
        g.resize(n);
        for(int j = 0; j < n; j++){
            cin >> price[j];
        }
        for(int j = 0; j < m; j++){
            cin >> u >> v >> w;
            node temp;
            temp.pt = v;
            temp.cost = w;
            g[u].push_back(temp);
            temp.pt = u;
            g[v].push_back(temp);
        }
        cin >> q;
        vector<int> ans;
        for(int j = 0; j < q; j++){
            cin >> c >> s >> t;
            ans.push_back(dikstra());
        }
        cout << "Case " << i << ":" << endl;
        for(int j = 0; j < ans.size(); j++){
            if (ans[j] == -1)
                cout << "impossible" << endl;
            else
                cout << ans[j] << endl;
        }
        price.clear();
        g.clear();
    }
}
