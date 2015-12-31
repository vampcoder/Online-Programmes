#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int n, x, y;
		int count1 = 0;
		int count2 = 0;
		vector<int> v[20006];
		vector<int> status(20006);
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int j = 0;
		while(1){
			if(v[j].begin() == v[j].end()){
				j++;
				continue;
			}else{
				break;
			}
		}	
		queue<int> q;
		int g_max = 0, g_min = 0;
		status[j] = 1;
		count1++;
		q.push(j);
		while(!q.empty()){
			int current = q.front();
			q.pop();
			for(vector<int>::iterator it = v[current].begin(); it != v[current].end(); it++){
				int x = *it;	
				if(status[x] == 0){
					if(status[current] == 1){
						status[x] = 2;
						count2++;
					}else{
						status[x] = 1;
						count1++;
					}
					q.push(x);
				}
			}
			if(q.empty()){
				while(j < 20003){
				if(status[j] == 0){
					if(v[j].begin() != v[j].end()){
						g_max += (count1>count2)?count1:count2;
						g_min += (count1<count1)?count1:count2;
						count1 = 1;
						count2 = 0;
						break;
					}
					j++;
					}
				}		
			}
		}
		if(count1 > count2)
			cout << "Case " << i << ": " << count1 << endl;
		else
			cout << "Case " << i << ": " << count2 << endl;
	}
}
