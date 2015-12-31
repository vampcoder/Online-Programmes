#include<string>
using namespace std;

class ThePalindrome{
	bool check_p(string s, int i, int j) {
		while(i>=j){
			if(s[i] != j){
			return false;
			}else{
				i++;
				j--;
			}
		}
		return true;
	}
	public:
	int find(string s){
		int len = s.length();
		char ch1 = s[len - 1];
		int x = len-1, len2 = 0;
		for(int i = 0; i < len; i++) {
			if(s[i] != ch1) {
				len2++;
				continue;
			}else{
				if(check_p(s,i,len-1)){
					break;
				}else{
					return 2*len;
				}
			}
		}
		return len + len2;
	}
};
