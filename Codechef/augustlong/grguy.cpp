#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
	int t;
	cin >> t;
	char s1[200005], s2[200005];
	while(t--){
			scanf("%s%s", s1, s2);
			int i, j;
			int turn = 1;
			int count1 = 0, count2 = 0;
			bool possible1 = true, possible2 = true;
			if(s1[0] == '#' && s2[0] == '#'){
					cout << "No\n";
					continue;
			}
			for(i = 0, j = 0; s1[i] != '\0' && s2[i] != '\0'; i++, j++){
				if(turn == 1){
					if(s1[i] == '.')
							continue;
					else if(s2[i] == '.' || s2[i+1] == '.'){
						turn = 2;
						count1++;
					}else{
						possible1 = false;
						break;
					}
				}else if(turn == 2){
					if(s2[i] == '.')
							continue;
					else if(s1[i] == '.' || s1[i] == '.'){
						turn = 1;
						count1++;
					}else{
						possible1 = false;
						break;
					}
				}
			}
			turn = 2;
			for(i = 0, j = 0; s1[i] != '\0' && s2[i] != '\0'; i++, j++){
				if(turn == 1){
					if(s1[i] == '.')
							continue;
					else if(s2[i] == '.' || s2[i+1] == '.'){
						turn = 2;
						count2++;
					}else{
						possible2 = false;
						break;
					}
				}else if(turn == 2){
					if(s2[i] == '.')
							continue;
					else if(s1[i] == '.' || s1[i] == '.'){
						turn = 1;
						count2++;
					}else{
						possible2 = false;
						break;
					}
				}
			}
			if(possible1 && possible2)
					cout <<"Yes\n" <<  min(count1, count2) << endl;
			else if(possible1)
					cout << "Yes\n" << count1 << endl;
			else if(possible2)
					cout <<"Yes\n" << count2 << endl;
			else
					cout << "No\n";
	}
}
