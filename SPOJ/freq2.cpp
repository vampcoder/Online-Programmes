#include<iostream>
#include<cstdio>

using namespace std;
struct node{
	int l, c, r;
	int fl, fc, fr;
};
int n, a[100005]; 
struct node seg[400005];

void construct(int seg_start, int seg_end, int index){
	if(seg_start == seg_end){
		seg[index].l = a[seg_start];
		seg[index].c = a[seg_start];
		seg[index].r = a[seg_start];
		seg[index].fl = 1;
		seg[index].fc = 1;
		seg[index].fr = 1;
		return;
	}
	int mid = (seg_start + seg_end)/2;
	construct(seg_start, mid, 2*index+1);
	construct(mid+1, seg_end, 2*index + 2);
	seg[index].l= seg[2*index+1].l;
	seg[index].fl = seg[2*index+1].fl;
	seg[index].r = seg[2*index+2].r;
	seg[index].fr = seg[2*index+2].fr;
	
	int middle =((seg[2*index+2].fc < seg[2*index+1].fc)?seg[2*index+1].c:seg[2*index+2].c);
	
	int ml =((seg[2*index+2].fc < seg[2*index+1].fc)?seg[2*index+1].fc:seg[2*index+2].fc);
	
	if(seg[2*index+1].r == seg[2*index+2].l && ml < seg[2*index+1].fr+seg[2*index+2].fl){
		ml = seg[2*index+1].fr+seg[2*index+2].fl;
		middle = seg[2*index+1].r;
	}
	if(seg[2*index+1].r == seg[2*index+2].r)
		seg[index].fr = seg[2*index+1].fr+seg[2*index+2].fr;
	if(seg[2*index+1].l == seg[2*index+2].l)
		seg[index].fl = seg[2*index+1].fl+seg[2*index+2].fl;
	
	seg[index].c = middle;
	seg[index].fc = ml;
	return;
}
struct node query(int seg_start, int seg_end, int index, int q_start, int q_end){
	if(q_start > seg_end || q_end < seg_start){
		struct node temp;
		temp.l = 0; temp.fl = 0;temp.r = 0; temp.fr = 0; temp. c = 0; temp. fc = 0;
		return temp;
	}
	if(q_start <= seg_start && q_end >= seg_end){
		return seg[index];
	}	
	int mid = (seg_start + seg_end)/2;
	struct node temp1 = query(seg_start, mid, 2*index+1, q_start, q_end);
	struct node temp2 =  query(mid+1, seg_end, 2*index+2, q_start, q_end);
	struct node r_node;
	r_node.l = temp1.l;
	r_node.fl = temp1.fl;
	r_node.r = temp2.r;
	r_node.fr = temp2.fr;
	int middle = ((temp2.fc < temp1.fc)?temp1.c:temp2.c);
	int ml = ((temp2.fc < temp1.fc)?temp1.fc:temp2.fc);
	if(temp1.r == temp2.l && (temp1.fr+temp2.fl)< ml){
		middle = temp1.r;
		ml = temp1.fr + temp2.fl;
	}
	if(temp1.r == temp2.r)
		r_node.fr = temp1.fr+temp2.fr;
	if(temp1.l == temp2.l)
		r_node.fl = temp1.fl + temp2.fl;
	r_node.fc = ml;
	r_node.c = middle;
	return r_node;
} 
int main()
{
	int q, c, d;
	struct node temp, res;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	construct(0, n-1, 0);
	while(q--){
		scanf("%d%d", &c, &d);
		res = query(0, n-1, 0, c-1, d-1);
		printf("%d\n", res.fc);
	}
	scanf("%d", &c);
}
