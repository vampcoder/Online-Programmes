#include <iostream>
#include <algorithm>
using namespace std;
int b[1][2];
main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //bsf = best so far
    //bn = best now
    //bsisf = best start index so far
    //bstsf = best stop index so far
    //bsin = best start index now
    int bsf = 0, bn = 0, bsisf = -1, bstsf = -1, bsin = -1, val = 0;
    for (int i = 0; i < n; i++) {
        val = bn + a[i];
        if (val > 0) {
            if (bn == 0)
                bsin = i;
            bn = val;
        } else {
            bn = 0;
        }
        if(bn > bsf) {
            bsf = bn;
            bstsf = i;
            bsisf = bsin;
        }
    }
    for (int i = bsisf; i <= bstsf; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

