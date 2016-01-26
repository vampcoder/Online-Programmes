#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi > vpi;
typedef vector<vpi > vvpi;

int t, n;
vvpi g1;
vvpi g2;
int visit[102];
int v = 0;
ll dfs(void){
    memset(visit, -1, sizeof(visit));
    ll cost = 0;
    stack<int> stck;
    stck.push(0);
    vector<int> path;
    while(!stck.empty()){
        int s = stck.top();
        stck.pop();
        visit[s] = 1;
        path.push_back(s);
        for(int i = 0; i < g1[s].size(); i++){
            pi temp = g1[s][i];
            int des = temp.first;
            if(visit[des] == -1){
                stck.push(des);
            }
        }
        for(int i = 0; i < g2[s].size(); i++){
            pi temp = g2[s][i];
            int des = temp.first;
            if(visit[des] == -1){
                stck.push(des);
            }
        }
    }
    path.push_back(0);
    ll cost1 = 0;
    ll cost2 = 0;
    int start = path[0];
    for(int i = 1; i < path.size(); i++){
        for(int j = 0; j < g2[path[i]].size(); j++){
            pi temp = g2[path[i]][j];
            if(temp.first == start){
                cost2 += temp.second;
            }
        }
        for(int j = 0; j < g1[path[i]].size(); j++){
            pi temp = g1[path[i]][j];
            if(temp.first == start){
                cost1 += temp.second;
            }
        }
        start = path[i];
    }

	return min(cost1, cost2);
}

void print_graph(){
    for(int i = 0; i < g1.size(); i++){
        cout << i+1;
        for(int j = 0; j < g1[i].size(); j++){
            pi temp = g1[i][j];
            cout << "  : -> " << temp.first+1 << " " << temp.second;
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < g2.size(); i++){
        cout << i+1;
        for(int j = 0; j < g2[i].size(); j++){
            pi temp = g2[i][j];
            cout << "  : -> " << temp.first+1 << " " << temp.second;
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
	cin >> t;
	 for(int i = 1; i <= t; i++){
		g1.clear();
		g2.clear();

	 	cin >> n;
	 	for(int j = 0; j < n; j++){
	 		vpi temp;
	 		g1.push_back(temp);
	 		g2.push_back(temp);
	 	}
	 	for(int j = 0; j < n; j++){
	 		int a, b, c;
	 		cin >> a >> b >> c;
	 		pi temp;
	 		temp.first = a-1;
	 		temp.second = c;
	 		g1[b-1].push_back(temp);
	 		temp.first = b-1;
	 		g2[a-1].push_back(temp);
	 	}
      //  print_graph();

        cout << "Case " << i << ": " <<  dfs() << endl;
	 }
	return 0;
}
