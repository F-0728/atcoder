#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    cin >> N;
    ll sum = 0;
    vector<ll> A;
    A.push_back(0);
    rep(i, N) {
        ll a;
        cin >> a;
        A.push_back(a + A.back());
        sum += a;
    }
    ll last = A.back();
    for (int i = 1; i < N; i++) {
        A.push_back(A[i] + last);
    }
    if (sum % 10 != 0) {
        No;
        return 0;
    }
    ll tar = sum / 10;

    rep(i, A.size()) {
        ll left = A[i];
        if (binary_search(A.begin(), A.end(), left + tar)) {
            Yes;
            return 0;
        }
    }
    No;
    return 0;
}
