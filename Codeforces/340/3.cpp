#include<bits/stdc++.h>

using namespace std;

struct point{
	int x;
	int y;
	double d1;
	double d2;
};

int main()
{
	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	struct point p[n];
	int x, y;
	for(int	i = 0; i < n; i++){
		cin >> x >> y;
		p[i].x = x;
		p[i].y = y;
		p[i].d1 = (x-x1)*(x-x1) + (y-y1)*(y-y1);
		p[i].d2 = (x-x2)*(x-x2) + (y-y2)*(y-y2);
	}
	double dist1 = 0;
	for(int i = 0; i < n; i++){
		dist1 = max(dist1, min(p[i].d1, p[i].d2));
	}
	int f = -1;
	for(int i = 0; i < n; i++){
		if(dist1 == p[i].d1)
			f = 1;
		if(dist1 == p[i].d2)
			f = 2;
    }

	double dist2 = 0;
	for(int i = 0; i < n; i++){
		if(f == 1){
			if(dist1 < p[i].d1)
				dist2 = max(dist2, p[i].d2);
		}else{
			if(dist1 < p[i].d2)
				dist2 = max(dist2, p[i].d1);
		}
	}
	cout << (int) dist1 + dist2;
}
