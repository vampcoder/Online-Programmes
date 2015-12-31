#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;
int n, a[510][510], seg[2100][2100];

void constructy(int seg_start, int seg_end, int seg_sx,int  seg_ex, int xindex, int yindex){
	if(seg_start == seg_end){
		if(seg_sx == seg_ex)
			seg[xindex][yindex] = a[seg_sx][seg_start];
		else
			seg[xindex][yindex] = max(seg[2*xindex+1][yindex], seg[2*xindex+2][yindex]);
		return;
	}
	int mid = (seg_start + seg_end)/2;
	constructy(seg_start, mid, seg_sx, seg_ex, xindex, 2*yindex+1);
	constructy(mid+1, seg_end, seg_sx, seg_ex, xindex, 2*yindex+2);
	seg[xindex][yindex] = max(seg[xindex][2*yindex+1], seg[xindex][2*yindex+2]);
	return;
}

void constructx(int seg_start, int seg_end, int xindex, int yindex){
	if(seg_start != seg_end){
		int mid = (seg_start + seg_end)/2;
		constructx(seg_start, mid, 2*xindex+1, yindex);
		constructx(mid+1, seg_end, 2*xindex+2, yindex);
	}
	constructy(0, n-1, seg_start, seg_end, xindex, yindex);
}
int y_query(int seg_start, int seg_end, int xindex, int yindex, int q_starty, int q_endy){
	if(q_starty > seg_end || q_endy < seg_start)
		return 0;
	if(q_starty <= seg_start && q_endy >= seg_end)
		return seg[xindex][yindex];
	int mid = (seg_start+seg_end)/2;
	return max(y_query(seg_start, mid, xindex, 2*yindex+1,q_starty, q_endy), y_query(mid+1, seg_end, xindex, 2*yindex+2, q_starty, q_endy));

}
int x_query(int seg_start, int seg_end, int xindex, int yindex, int q_startx, int q_endx, int q_starty, int q_endy){
	if(q_startx > seg_end || q_endx < seg_start)
		return 0;
	if(q_startx <= seg_start && q_endx >= seg_end){
		return y_query(0, n-1, xindex, yindex, q_starty, q_endy);
	}
	int mid = (seg_start + seg_end)/2;
	return max(x_query(seg_start, mid, 2*xindex+1, yindex, q_startx, q_endx, q_starty, q_endy), x_query(mid+1, seg_end, 2*xindex+2, yindex, q_startx, q_endx, q_starty, q_endy));
}

int main()
{
	int t, q;
	char ch;
	cin >> t;
	for(int j = 1; j <= t; j++){
		scanf("%c", &ch);
		scanf("%d%d", &n, &q);
		int x = 4*n;
		for(int i = 0; i < x; i++)
			for(int k = 0; k < x; k++)
				seg[i][k] = 0;
		for(int i = 0; i < n; i++)
			for(int k = 0; k < n; k++)
				scanf("%d", &a[i][k]);
		constructx(0, n-1, 0, 0);
		int qx, qy, s;
		cout << "Case " << j << ":" << endl;
		for(int i = 0; i < q; i++){
//	for(int i = 0; i < 4*n; i++){
//		for(int j = 0; j < 4*n; j++){
//			cout << seg[i][j] << " ";
//		}
//		cout << endl;
//	}
			scanf("%d%d%d", &qx, &qy, &s);
			printf("%d\n", x_query(0, n-1, 0, 0, qx-1, qx+s-2, qy-1, qy+s-2));;
		}
	}
}
