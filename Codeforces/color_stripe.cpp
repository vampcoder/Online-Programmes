#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>

using namespace std;

int n, c;
char str[500007], temp[500007], output[500007];
char *final;
int f_change = INT_MAX;
int change = 0;

void rec(int i, char ch){
	if(i >= n) {
		if(change < f_change){
			f_change = change;
			strcpy(output, temp);
		}
		return;
	}
	int x = 0;
	char ch1 = str[i];
	for(int j = 0; j < c; j++) {
		if(ch != (char)j+65){
			ch1 = temp[i];
			temp[i] = j+65;
			if((char)j == str[i]-65){
				rec(i+1,(char)j+65);
			}else{
		 		change++;
				rec(i+1,(char)j+65);
				change--;
			}
			temp[i] = ch1;
		}
	}	
}
int main()
{
	scanf("%d%d", &n, &c);
	scanf("%s",str);
	strcpy(temp, str);
	rec(0, '$');
	printf("%d\n%s\n", f_change, output);
}
