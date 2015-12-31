#include<bits/stdc++.h>

using namespace std;
bool func(pair<int, int> a, pair<int, int> b){
	return a.first > b.first;
}

bool func1(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}
int main()
{
	int n, x, y;
	cin >> n;
	vector<pair<int, int> > vp;
	vector<pair<int, int> > vn;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		pair<int, int> p;
		p.first = x;
		p.second = y;
		if(x < 0){
			vp.push_back(p);
		}else{	
			vn.push_back(p);
		}
	}
	sort(vp.begin(), vp.end(), func);
	sort(vn.begin(), vn.end(), func1);
	int lenp = vp.size();
	int lenn = vn.size();
	int m = min(lenp, lenn);
	int sum = 0;
	if(lenp < lenn){
		for(int i = 0; i < m; i++){
			sum += vn[i].second;
			sum += vp[i].second;
		}
		sum += vn[m].second;			
	}else if(lenp > lenn){	
		for(int i = 0; i < m; i++){
			sum += vn[i].second;
			sum += vp[i].second;
		}
		sum +=	vp[m].second;		
	}else{
		for(int i = 0; i < m; i++){
			sum += vn[i].second;
			sum += vp[i].second;			
		}
	}
	cout << sum;
}
