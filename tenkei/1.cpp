#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

vector<ll> A;
vector<ll> B;

bool cuttable(ll x, ll k) {
    ll cut = 0;
    ll length = 0;
    rep(i, B.size()) {
        length += B[i];
        if (length >= x) {
            cut++;
            length = 0;
        }
    }
    if (cut >= k) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ll N, L, K;
    ll a;
    cin >> N >> L >> K;
    rep(i, N) {
        cin >> a;
        A.push_back(a);
    }
    B.push_back(A[0]);
    rep(i, N - 1) B.push_back(A[i + 1] - A[i]);
    B.push_back(L - A[N - 1]);

    ll left = 0;
    ll right = L;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (cuttable(mid, K + 1)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;

    return 0;
}
