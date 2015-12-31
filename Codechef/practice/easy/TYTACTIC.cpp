#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif

#define tr(a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define all(c) c.begin(), c.end()

using namespace std;

int read_int()
{
register char c=gc();
if(c >='A' || c <='Z'){
    return c;
}else{
while(c<'0'||c>'9')
    c=gc();  //ignore all characters till the first digit
int ret=0;
while(c>='0' && c<='9') //till we get a stream of digits.As soon as we get something else,we stop
{
ret=ret*10+(c-48);//construct the number
c=gc();
}
return ret;
}
}

typedef set<int> si;

vector<int> v(5);
void dfs(int i, si a[5]) {
	queue<int> q;
	q.push(i);
	v[i] = 1;
	cout << i+1<< " ";
	int top;
	while(q.empty() == false){
		top = q.front();
		q.pop();
		tr(a[top]){
			if(v[*it] != 1){
				q.push(*it);
				v[*it] = 1;
				cout << (*it) + 1 << " ";
			}
		}
	}
}
int main()
{   int n, m;
	si a[n];
	vector<int> skil(n);
	for(int i = 0; i < n; i++){
        v[i] = read_int();
	}
	do{

	}while();
	dfs(0, a);
}
