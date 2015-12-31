#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	int num;
	int first;
	int last;
};
bool func(node a, node b){
	if(a.num > b.num)
		return true;
	else if(a.num < b.num)
		return false;
	else{
		if((a.last-a.first) < (b.last-b.first))
			return true;
		else
			return false;
	}
}

node c[1000001];
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < 1000001; i++){
		c[i].num = 0;
		c[i].first = -1;
		c[i].last = -1;
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
		c[a[i]].num++;
		if(c[a[i]].first == -1)
			c[a[i]].first = i;
		c[a[i]].last = i;
	}
	//sort(c, c+100001, func);
	int g_c = 0, g_f=0, g_l= n;
	for(int i = 0; i < 1000001; i++){
		if(g_c < c[i].num){
			g_c = c[i].num;
			g_f = c[i].first;
			g_l = c[i].last;
		}else if(g_c == c[i].num){
			if((g_l-g_f) > (c[i].last-c[i].first)){
				g_l = c[i].last;
				g_f = c[i].first;
			}
		}

	}
	cout << g_f+1 << " " << g_l+1;
	
}
