#include<iostream>
#include<cstdio>

using namespace std;

void update(int x, int val, int tree[], int n, int a[]){
	val  -= a[x];
	a[x] += val;
	while(x <= n){
		tree[x] += val;
		x += x&(-x);	
	}
}
int query(int a, int b, int tree[]){
	int x = 0;
	while(b >= a){
		x+= tree[b];
		b-= b&(-b);
	}
	a--;
	while(a != b){
		x-= tree[a];
		a -= a&(-a);
	}
	return x;
}
void create(int a[], int n, int tree[]){
	for(int i = 1; i <= n; i++){
		int x = i;
		while(x <= n){
			tree[x] += a[i];
			x += x&(-x);
		}
	}
}
void print(int tree[], int n){

	for(int i = 1; i <= n; i++)
		cout << tree[i] << " ";
	cout << endl;
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[n+1], tree[n+1];
	tree[0] = 0;
	a[0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		tree[i] = 0;
	}	
	create(a, n, tree);
	print(tree, n);
	update(1, 6, tree, n, a);
	print(tree, n);
	print(a, n);
	cout << query(1,3, tree) << endl;
}
