#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() {
    int A, B, C;
    int X;
    cin >> A >> B >> C >> X;
    X /= 50;
    int ans = 0;
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            for (int k = 0; k <= C; k++) {
                if (10 * i + 2 * j + k == X) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
