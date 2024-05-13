#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() {
    int N, P, Q;
    cin >> N >> P >> Q;
    vector<int> rem(N);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        rem[i] = A % P;
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                for (int l = k + 1; l < N; l++) {
                    for (int m = l + 1; m < N; m++) {
                        if ((1LL * rem[i] * rem[j] % P) * rem[k] % P * rem[l] % P * rem[m] % P == Q) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    cout << count << endl;

    return 0;
}
