#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() {
    int H, W;
    cin >> H >> W;
    int h, w;
    if (H == 1 || W == 1) {
        cout << max(H, W) << endl;
        return 0;
    }
    if (H % 2 == 0) {
        h = H / 2;
    } else {
        h = H / 2 + 1;
    }
    if (W % 2 == 0) {
        w = W / 2;
    } else {
        w = W / 2 + 1;
    }
    cout << h * w << endl;

    return 0;
}
