#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
struct node{
	int x;
	int y;
};
bool cmpc(struct node l, struct node m){
	if(l.x == m.x)
		return l.y < m.y;
	else
		return l.x < m.x;
}
int n, temp[200007];
struct node a[50007], seg[200007], seg1[200007];

void construct(int seg_start, int seg_end, int index){
	if(seg_start == seg_end){
		seg[index] = a[seg_start];
		seg1[index] = a[seg_start];
		temp[index] = 1;
		return;
	}
	int mid = (seg_start + seg_end)/2;
	construct(seg_start, mid, 2*index+1);
	construct(mid+1, seg_end, 2*index + 2);
	seg[index].x = min(seg[2*index+1].x, seg[2*index+2].x);
	seg[index].y = max(seg[2*index+1].y, seg[2*index+2].y);
	if(seg1[2*index+1].y < seg1[2*index+2].x){
		seg1[index].x = -1;
		seg1[index].y = -1;
		temp[index] = 0;
	}else{
		seg1[index].x = seg1[2*index+2].x;
		seg1[index].y = min(seg1[2*index+1].y, seg1[2*index+2].y);
		temp[index] = temp[2*index+1] + temp[2*index+2];
	}
	return;
}
int query(int seg_start, int seg_end, int index, int q_start, int q_end){
	if(q_start > seg[index].y || q_end < seg[index].x){
		return 0;
	}
	if(q_start >= seg1[index].x && q_end <= seg1[index].y){
		return temp[index];
	}	
	int mid = (seg_start + seg_end)/2;
	return query(seg_start, mid, 2*index+1, q_start, q_end) + query(mid+1, seg_end, 2*index+2, q_start, q_end);
} 
void print(struct node p[], int n){
	for(int i = 0; i < n; i++){
		cout << p[i].x << " " << p[i].y <<endl;
	}

}
int main()
{	
	int t, q, r, l, m;
	scanf("%d", &t);
	for(int j = 1; j <= t; j++){
		scanf("%d%d", &n, &q);
		for(int i = 0; i < n; i++){
			scanf("%d%d", &l, &m);
			a[i].x = l;
			a[i].y = m;
		}
		sort(a, a+n, cmpc);
//		print(a, n);
		construct(0, n-1, 0);
		printf("Case %d:\n", j);
		while(q--){
			scanf("%d", &r);
			printf("%d\n", query(0, n-1, 0, r, r));
		}
	}
}
