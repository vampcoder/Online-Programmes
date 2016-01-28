#include<bits/stdc++.h>

using namespace std;
struct node{
    int h;
    int c;
};

int t, u, v, w, n, m;
vector<vector<node> > g;

class cmpc{
public:
    bool operator() (node &a, node &b){
        return a.c > b.c;
    }
};

int dikstra(void){
    bool visited[n+1];
    memset(visited, 0, sizeof visited);
    int cost[n+1];
    for(int i = 0; i <= n; i++)
        cost[i] = INT_MAX;
    priority_queue<node, vector<node>, cmpc> pq;

    node temp;
    temp.h = 1;
    temp.c = 0;
    pq.push(temp);
    cost[temp.h] = 0;
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        if(visited[temp.h] || cost[temp.h] < temp.c)
            continue;
        visited[temp.h] = true;
        for(int i = 0; i < g[temp.h].size(); i++){
            node temp1 = g[temp.h][i];
            if(!visited[temp1.h] && cost[temp1.h] > temp.c + temp1.c){
                temp1.c += temp.c;
                cost[temp1.h] = temp1.c;
                pq.push(temp1);
            }
        }
    }
    if(cost[n] == INT_MAX){
        return -1;
    }else{
        return cost[n];
    }
}


int main()
{

    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n >> m;
        g.resize(n+1);
        for(int j = 0; j < m; j++){
            cin >> u >> v >> w;
            node temp;
            temp.c = w;
            temp.h = v;
            g[u].push_back(temp);
            temp.h = u;
            g[v].push_back(temp);
        }
        int ans = dikstra();
        if(ans != -1)
            cout << "Case " << i << ": " << ans << endl;
        else
            cout << "Case " << i << ": Impossible\n";
        g.clear();
    }


}
