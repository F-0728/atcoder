#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> d(N);
    int sumd = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        d[i] = abs(A[i] - B[i]);
    }
    for (int i = 0; i < N; i++) {
        sumd += d[i];
    }
    // parity
    if ((sumd + K) % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    // todokanai
    if (sumd > K) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
