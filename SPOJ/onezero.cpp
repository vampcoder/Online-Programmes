#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>

using namespace std;
struct node{
	char arr[2000];
	int mod;
};
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		int visited[200000] = {0};
		cin >> n;
		queue<node> q;
		node temp1, temp2, temp;
		strcpy(temp.arr, "1");
		temp.mod = 1%n;
		visited[temp.mod] = 1;
		q.push(temp);
		while(!q.empty()){
			temp = q.front();
			q.pop();
			int num;
			if(temp.mod == 0){
				cout << temp.arr << endl;
				break;			
			}
			strcpy(temp1.arr, temp.arr);
			strcat(temp1.arr, "0");	
			num = atoi(temp1.arr);
			temp1.mod = num%n;
			if(visited[temp1.mod] == 0){
				visited[temp1.mod] = 1;
				q.push(temp1);
			}
			strcpy(temp2.arr, temp.arr);
			strcat(temp2.arr, "1");
			num = atoi(temp2.arr);
			temp2.mod = num%n;
			if(visited[temp2.mod] == 0){
				visited[temp2.mod] = 1;
				q.push(temp2);
			}
		}		
	}
}
