#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>

#define ll long long int
#define tr(a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pi pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vpi vector< pi >
#define vvpi vector< vpi >
#define ppi pair<pi, int >
#define vppi vector< ppi >
#define qpi priority_queue< pi, vpi, cmpc>
#define qppi priority_queue< ppi, vppi, cmpc>
#define vqpi vector< qpi >

using namespace std;

class cmpc{
	public:
	bool operator() (ppi x, ppi y){
		return x.second > y.second;
	}
};

int parent[10007];

int par(int x){
	if(parent[x] == x)
		return x;
	else return par(parent[x]);
}
void merge(int x, int y){
	int xp = par(x);
	int yp = par(y);
	if(xp < yp){
		parent[yp] = xp;
	}else{
		parent[xp] = yp;
	}
}
int main() {
	int n, m, x, y, cost;
	scanf("%d%d", &n, &m);
	qppi pq;
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &x, &y, &cost);
		ppi a;
		a.first.first = x;
		a.first.second = y;
		a.second = cost;
		pq.push(a);
	}
	for(int i = 0; i <= m; i++){
		parent[i] = i;
	}
	int t_cost = 0;
	while(!pq.empty()){
		ppi temp;
		temp = pq.top();
		pq.pop();
		int f = temp.first.first;
		int s = temp.first.second; 
		if(par(f) == par(s))
			continue;
		else{
			merge(f, s);
	//		cout << temp.second << " ";
			t_cost += temp.second;
		}
	}
//	cout << endl;
	printf("%d\n", t_cost);
}
