#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m, s, t, p;
struct node{
    int pt;
    ll c;
    node() {}
    node(int a, ll b) : pt(a), c(b) {}
    bool operator <(const node &a) const {
        return c > a.c;
    }
};


vector<vector<node> > g1;
vector<vector<node> > g2;



ll dikstra(void){
    vector<ll > cost1(g1.size(), LLONG_MAX);
    vector<ll > cost2(g1.size(), LLONG_MAX);
    priority_queue<node> pq;
    node temp;
    temp.pt = s;
    temp.c = 0;
    pq.push(temp);

    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        if(cost1[temp.pt] <= temp.c)
            continue;
        cost1[temp.pt] = temp.c;

        for(int i = 0; i < g1[temp.pt].size(); i++){
            node temp1 = g1[temp.pt][i];
            if(cost1[temp1.pt] > temp.c + temp1.c){
                temp1.c += temp.c;
                pq.push(temp1);
            }
        }
    }

    temp.pt = t;
    temp.c = 0;
    pq.push(temp);

    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        if(cost2[temp.pt] <= temp.c)
            continue;
        cost2[temp.pt] = temp.c;

        for(int i = 0; i < g2[temp.pt].size(); i++){
            node temp1 = g2[temp.pt][i];
            if(cost2[temp1.pt] > temp.c + temp1.c){
                temp1.c += temp.c;
                pq.push(temp1);
            }
        }
    }

    ll best = -1;
    for(int i = 0; i < g1.size(); i++){
        for(int j = 0; j < g1[i].size(); j++){
            temp = g1[i][j];
            int x = i, y = temp.pt;
            if(cost1[x] != LLONG_MAX && cost2[y] != LLONG_MAX){
                if(cost1[x] + temp.c + cost2[y] <= p){
                    best = max(best, temp.c);
                }
            }
        }
    }
    return best;
}


int main()
{
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
       // cin >> n >> m >> s >> t >> p;
        g1.resize(n+1);
        g2.resize(n+1);
        for(int j = 0; j < m; j++){
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            node temp;
            temp.pt = v;
            temp.c = c;
            g1[u].push_back(temp);
            temp.pt = u;
            g2[v].push_back(temp);
        }
        printf("Case %d: %lld\n", i, dikstra());
        //cout << "Case " << i << ": " << dikstra() << endl;
        g1.clear();
        g2.clear();
    }
}
