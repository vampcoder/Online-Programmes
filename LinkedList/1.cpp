#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct node{
	int x;
	struct node* next;
};
struct node* create (struct node* start, int x){
	struct node *tmp = (struct node *) malloc(sizeof(struct node));
	tmp -> x = x;
	tmp -> next = NULL;
	if(start == NULL)
		start = tmp;
	else{
		struct node* tmp1 = NULL;
		for(tmp1 = start; tmp1 -> next != NULL; tmp1 = tmp1 -> next);
		tmp1 -> next = tmp;
	}
	return start;
}
void print(struct node *start){
	for(struct node* tmp = start; tmp != NULL; tmp = tmp -> next)
		cout << tmp -> x << " ";
	cout << endl;
}
struct node* remove(struct node* start, int x){
	struct node* tmp1 = start;
	struct node* tmp2 = NULL;
	if(tmp1 -> x == x) {
		start = start -> next;
		free(tmp1);
		return start;
	}
	for(tmp2 = start -> next; tmp2 != NULL && tmp2 -> x != x; tmp2 = tmp2 -> next, tmp1 = tmp1 -> next);
	if(tmp2 == NULL)
		return start;
//	cout << tmp1 -> x << " " << tmp2 -> x << endl;
	if(tmp2 -> x == x){
		tmp1 -> next = tmp2 -> next;
		free(tmp2);
	}
	return start;
}
int main()
{
	int x;
	cin >> x;
	struct node * start = NULL;
	while(x != -1){
		start = create(start, x);
		cin >> x;
	}
	print(start);
	cin >> x;
        start = remove(start, x);
	print(start);
}
