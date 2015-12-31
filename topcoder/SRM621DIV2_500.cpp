#include<vector>
using namespace std;

class NumberChallenge{
	static const int MAX = 100000 * 20 + 1;
	bool poss[2000007] = {false};
 	public:
	int MinNumber(vector<int> S){
    	int n = S.size();
    // All subsets:
    	for (int mask = 0; mask < (1<<n); mask++) {
        	int sum = 0;
        	for (int i = 0; i < S.size(); i++) {
            	if (mask & (1<<i)) {
                	sum += S[i];
            	}
        	}
        	poss[sum] = true;
    	}
    	int x = 1;
    	while (poss[x]) {
        	x++;
    	}
    	return x;
	}
};
