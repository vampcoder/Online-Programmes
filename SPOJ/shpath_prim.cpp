#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi >
#define qpi priority_queue<pi,vpi, cmpc>
#define tr(a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
using namespace std;
class cmpc{
	public:
	bool operator()(pi x, pi y){
		return x.second > y.second;
	}
};
int s, n, m, x, y, val;
long long int prims(vpi v[]){
	qpi q;
	tr(v[0])
		q.push(*it);
	int c = 0;
	long long int w = 0;
	int visited[n];
	memset(visited, 0, sizeof(visited));
	visited[0] = 1;
	while(!q.empty() && c != n){
		pi temp = q.top();
		q.pop();
		if(visited[temp.first] == 0){
			visited[temp.first] = 1;
			c++;
			w += temp.second;
			tr(v[temp.first]){
				pi temp2 = *it;
				if(visited[temp2.first])
					continue;
				else
					q.push(temp2);
			}
		}
	}
	return w;
}
int main(){
	scanf("%d%d", &n, &m);
	vpi v[n];
	for(int i = 0; i < m; i++){
		pi temp;
		scanf("%d%d%d", &x, &y, &val);
		temp.first = y-1;
		temp.second = val;
		v[x-1].push_back(temp);
		temp.first = x-1;
		v[y-1].push_back(temp);
	}
	printf("%lld\n", prims(v));
}

