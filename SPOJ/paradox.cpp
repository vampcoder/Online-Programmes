#include<iostream>
#include<queue>
#include<vector>

using namespace std;
#define vi vector<int>
#define pib pair<int, bool>
#define vpib vector<pib>
#define pibb pair<pib, bool>
int main()
{
	int n;
	while(1){
		cin >> n;
		vpib v(n+1);
		if(n == 0)
			break;
		int x;
		string str;
		for(int i = 0; i < n; i++){
			cin >> x >> str;
			if(str[0] == 't'){
				v[i+1].first= x; 
				v[i+1].second=true;
			}else{
				v[i+1].first = x;
				v[i+1].second = false;		
			}
		}
		vi visited(n+1);
		queue<pibb > q;
		pibb temp;
		temp.first = v[1];
		temp.second = true;
		visited[1] = 2;//2 means true
		q.push(temp);
		bool finale = true;
		while(!q.empty()){
			pibb p = q.front();
			q.pop();
			if(visited[p.first.first] == 0){
				if(p.second == true){
					if(p.first.second == true)
						visited[p.first.first] = 2;
					else
						visited[p.first.first] = 1;
				}else{
					if(p.first.second == true)
						visited[p.first.first] = 1;
					else
						visited[p.first.first] = 2;
				}
				temp.first = v[p.first.first];
				temp.second = p.first.second;
				q.push(temp);
			}else if(visited[p.first.first] == 1){
				if(p.second == true){
					if(p.first.second == true){	
						finale = false;
						break;
					}
				}else{
					if(p.first.second == false){
						finale = false;
						break;
					}
				}			
			}else{
				if(p.second == true){
					if(p.first.second == false){
						finale = false;
						break;
					}	
				}else{
					if(p.first.second == true){
						finale = false;
						break;
					}
				}
			}
		}
		if(finale)
			cout << "NOT PARADOX\n";
		else
			cout << "PARADOX\n";	
	}	
}
