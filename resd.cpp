#include<algorithm>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

	int searchy(string s, char ch){
		for(int i = 0; i < s.length(); i++){
			if(s[i] == ch)
				return i;
		}
		return 0;
	}
	string isSafeCommand(vector<string> board, string s){
		int u = board.size();
		int v[u];
		int sx=0, sy=0;
		for(int i = 0; i < u; i++){
			v[i] = board[i].length();
		}
		for(int i = 0; i < u; i++){
			if(find(board[i].begin(), board[i].end(), 'S') != board[i].end()){
				sx = i;
				sy = searchy(board[i], 'S');
			}
		}
		string D = "Dead";
		string A = "Alive";
		char ch;
		board[sx][sy] = '.';
		for(int i = 0; i < s.length(); i++){
            cout << i << " "<<sx <<" "<< sy << " " << board[sx][sy] << " " << s[i] <<endl;
			if(s[i] == 'U'){
				if(sx > 0){
					ch = board[sx-1][sy];
					if(ch == '.')
						sx -= 1;
				}else{
					return D;
				}
			}else if(s[i] == 'R'){
				if(sy < v[sx]-1){
					ch = board[sx][sy+1];
					if(ch == '.')
						sy += 1;
				}else
					return D;
			}else if(s[i] == 'D'){
				if(sx < u){
					ch = board[sx+1][sy];
					if(ch == '.')
						sx += 1;
				}else
					return D;
			}else {
				if(sy > 0){
					ch = board[sx][sy-1];
					if(ch == '.')
						sy -= 1;
				}else
					return D;
			}
		}
		return A;
	}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    string r;
    cin >> r;
    cout << r.length();
    cout << isSafeCommand(v, r);
}
