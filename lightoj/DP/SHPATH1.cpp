#include<bits/stdc++.h>

using namespace std;
#define pi pair<int, int>
#define vpi vector<pi >
vector<pi > v[10010];
class cmpc{
	public:
	bool operator() (pi x, pi y){
		return x.second > y.second;
	}
};
int cost[10010];

int bfs(int s, int d){
    if(s == d)
        return 0;

    priority_queue<pi, vpi, cmpc> q;
    q.push(make_pair(s, 0));
    cost[s] = 0;
    while(!q.empty()){
        pi temp = q.top();
        q.pop();
        if(temp.first == d){
            return temp.second;
        }
        if(cost[temp.first] == temp.second){
            int cur = temp.first;
            for(int i = 0; i < v[cur].size(); i++){
                int neigh = v[cur][i].first;
                int c = v[cur][i].second;
                if(cost[neigh] == -1 || cost[neigh] > c + temp.second){
                    cost[neigh] = c + temp.second;
                    q.push(make_pair(neigh, cost[neigh]));
                }
            }
        }
    }
    return cost[d];
}

int main()
{
    int t, n, p, nr, q, neigh;
    scanf("%d", &t);
    while(t--){
        char str[12], des[12];
        map<string, int> m;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%s", &str);
            string s(str);
            m[s] = i;
            cin >> neigh;
            while(neigh--){
                scanf("%d%d", &p, &nr);
                v[i].push_back(make_pair(p, nr));
            }
        }
        scanf("%d", &q);
        while(q--){
            scanf("%s%s", &str, &des);
            string s(str), d(des);
            int s1 = m[s];
            int d1 = m[d];
            memset(cost, -1, sizeof cost);
            printf("%d\n", bfs(s1, d1));
        }
        for(int i = 0; i < 10010; i++){
            v[i].clear();
        }
        cout << endl;
    }

}
