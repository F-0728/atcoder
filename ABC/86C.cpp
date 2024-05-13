#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() {
    int N;
    cin >> N;
    bool flag = true;
    int tprev, xprev, yprev;
    tprev = xprev = yprev = 0;
    for (int i = 0; i < N; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        int elapsed = t - tprev;
        // todokanai
        if (x + y + elapsed < xprev + yprev || x + y > xprev + yprev + elapsed) {
            flag = false;
        }
        // parity
        if ((x + y + t) % 2 != 0) {
            flag = false;
        }
        tprev = t;
        xprev = x;
        yprev = y;
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
