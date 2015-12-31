#include<iostream>

using namespace std;

int powers[25];

bool check(int x){
	for(int i = 0; i < 25; i++)
			if(powers[i] == x)
					return true;
	return false;
}

int main()
{
	powers[0] = 1;
	for(int i = 1; i < 25; i++){
		powers[i] = powers[i-1]*2;
	}
	int t;
	cin >> t;
	int ini, des;
	while(t--){
		cin >> ini >> des;
		if(ini == des){
			cout << "0\n";
			continue;
		}
		int count  = 0;
		while(!check(ini) && ini != 1){
			ini /= 2;
			count++;
		}
		if(ini == des){
			cout << count << endl;
		}else if(ini > des){
			while(ini != des){
				ini /= 2;
				count++;
			}
			cout << count << endl;
		}else{
			while(ini != des){
				ini *= 2;
				count++;
			}
			cout << count << endl;
		}
	}
}
