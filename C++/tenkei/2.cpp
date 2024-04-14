#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() {
    int N;
    cin >> N;
    if (N % 2 != 0) {
        return 0;
    }
    for (int i = 0; i < (1 << N); i++) {
        string s = "";
        int sum = 0;
        for (int j = N - 1; j >= 0; j--) {
            if (i & (1 << j)) {
                s += ")";
                sum -= 1;
            } else {
                s += "(";
                sum += 1;
            }
            if (sum < 0) {
                break;
            }
        }
        if (sum == 0) {
            cout << s << endl;
        }
    }
    return 0;
}
