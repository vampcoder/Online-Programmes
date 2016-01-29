#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, r;
struct node{
    int pt;
    ll c;
};
class cmpc{
public:
    bool operator() (node& a, node& b){
        return a.c > b.c;
    }
};
vector<vector<node> > g;

int dikstra(){
    int visit[n+1];
    ll cost[n+1];
    memset(visit, 0, sizeof visit);
    for(int i = 0; i <= n; i++){
        cost[i] = LLONG_MAX;
    }
    priority_queue<node, vector<node>, cmpc> pq;

    node temp;
    temp.pt = 1;
    temp.c = 0;
    pq.push(temp);
    while(!pq.empty() && visit[n] < 2){
        temp = pq.top();
        pq.pop();
        if(visit[temp.pt] == 0){
            cost[temp.pt] = temp.c;
            visit[temp.pt]++;

        }else if(visit[temp.pt] == 2){
            continue;
        }else{
            if(cost[temp.pt] != temp.c){
                cost[temp.pt] = temp.c;
                visit[temp.pt]++;
            }
        }
        for(int i = 0; i < g[temp.pt].size(); i++){
            node temp1 = g[temp.pt][i];
            if((visit[temp1.pt] < 2)){
                temp1.c += temp.c;
                pq.push(temp1);
            }
        }
    }
    return cost[n];
}


int main()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++){
            cin >> n >> r;
            g.resize(n+1);
            int u, v, w;
            for(int j = 0; j < r; j++){
                cin >> u >> v >> w;
                node temp;
                temp.pt = u;
                temp.c = w;
                g[v].push_back(temp);
                temp.pt = v;
                g[u].push_back(temp);
            }

            cout <<"Case " << i << ": " << dikstra() << endl;
            g.clear();
    }
}
