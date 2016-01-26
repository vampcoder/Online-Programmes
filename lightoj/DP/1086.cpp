#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, t, m, s;
int graph[110][110];
struct node{
	ll ans;
	bool cor;  //correct or not
};

node rec(int last, int mask){
	
    node temp;	
    if(__builtin_popcount(mask) == n){
	temp.ans = graph[last][s];
	if(graph[last][s] != 0){
        	temp.cor = true;
	}else{
		temp.cor = false;
	}
	return temp;
    }
		
    temp.ans = LLONG_MAX;
    temp.cor = false;
    node t;
    for(int i = 1; i <= n; i++){
        if(!(mask & (1 << i))){
	    if(graph[i][last] != 0){
		t = rec(i, (mask | (1 << i)));
		if(t.cor == true){
			temp.ans = min(temp.ans, graph[i][last] + t.ans);
			temp.cor = true;		
		}
	    }
        }
    }

    return temp;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++){
        memset(graph, 0, sizeof(graph));
        cin >> n;
        cin >> m;
        int x, y, cost;
        for(int j = 0; j < m; j++){
            cin >> x >> y >> cost;
            if(graph[x][y] == 0){
                graph[x][y] = cost;
                graph[y][x] = cost;
            }else if(graph[x][y] > cost){
                graph[x][y] = cost;
                graph[y][x] = cost;
            }
        }
	node temp;
	temp.ans = LLONG_MAX;
	temp.cor = false;
	for(int j = 1; j <= n; j++){
		s = j;
		node t = rec(j, (1 << j));
		if(t.cor == true)
			temp.ans = min(temp.ans , t.ans);
	}
	cout << temp.ans;
    }
}
