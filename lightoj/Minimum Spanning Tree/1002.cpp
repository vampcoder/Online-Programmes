#include<bits/stdc++.h>

using namespace std;

int arr[500][500];

void func(int t, int n){
	int a[n];
	for(int i = 0; i < n; i++)
		a[i] = INT_MAX;
//	cout << a[0] << " "  << a[1] << endl;
	queue<pair<int, int> > q;
	pair<int, int> p;
	p.first = t;
	p.second = 0;
	a[t] = 0;
	q.push(p);
	
	while(!q.empty()){
		p = q.front();
		q.pop();
		int idx = p.first;
		int cost = p.second;
		if(cost > a[idx])
			continue;
		for(int i = 0; i < n; i++){
			if(arr[idx][i] != -1){
				int next = i;
				int c;
				if(cost == 0){
					c = arr[idx][next];	
				}else{
					c = max(cost, arr[idx][next]);
				}
				if(c < a[next]){
					a[next] = c;
					p.first = next;
					p.second = a[next];
					q.push(p);
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(a[i] != INT_MAX){
			cout << a[i] << endl;
		} else {
			cout << "Impossible" << endl;
		}		
	}
}

int main()
{
	int T, n, m, u, v, w, t;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> n >> m;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				arr[j][k] = -1;
			}
		}		
		for(int j = 0; j < m; j++){
			cin >> u >> v >> w;
			if(arr[u][v] == -1){
				arr[u][v] = w;
				arr[v][u] = w;
			}else{
				if(arr[u][v] > w){
					arr[u][v] = w;
					arr[v][u] = w;
				}
			}	
		}
		cin >> t;
		cout << "Case " << i << ":\n";
		func(t, n);		

	}	
}
