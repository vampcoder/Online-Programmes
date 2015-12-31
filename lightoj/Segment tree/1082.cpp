#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>

using namespace std;
int n, a[100007], seg[400007];

void construct(int seg_start, int seg_end, int index){
	if(seg_start == seg_end){
		seg[index] = a[seg_start];
		return;
	}
	int mid = (seg_start + seg_end)/2;
	construct(seg_start, mid, 2*index+1);
	construct(mid+1, seg_end, 2*index + 2);
	seg[index] = min(seg[2*index+1], seg[2*index+2]);
	return;
}
int query(int seg_start, int seg_end, int index, int q_start, int q_end){
	if(q_start > seg_end || q_end < seg_start)
		return INT_MAX;
	if(q_start <= seg_start && q_end >= seg_end){
		return seg[index];
	}	
	int mid = (seg_start + seg_end)/2;
	return min(query(seg_start, mid, 2*index+1, q_start, q_end), query(mid+1, seg_end, 2*index+2, q_start, q_end));
} 
int main()
{
	int t, q;
	char ch;
	cin >> t;
	for(int j = 1; j <= t; j++){
		scanf("%c", &ch);
		scanf("%d", &n);
		scanf("%d", &q);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < 4*n; i++)
			seg[i] = INT_MAX;
		construct(0, n-1, 0);
		int l, r;
		cout << "Case " << j << ":" << endl;
		for(int i = 0; i < q; i++){
			scanf("%d%d", &l, &r);
			printf("%d\n", query(0, n-1, 0, l-1, r-1));			
		}		
	}		
}
