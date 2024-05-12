#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

ll MAX = 1e8;
ll HALF_MAX = 5e7;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }
    sort(A.begin(), A.end());
    ll divided;
    ll ans = 0;
    rep(i, N) {
        divided = 0;
        ans += A[i] * (N - 1);
        if (A[i] < HALF_MAX) {
            auto modBound = lower_bound(A.begin(), A.end(), MAX - A[i]);
            divided += A.end() - modBound;
            // cout << "divided: " << divided << endl;
        }
        ans -= divided * MAX;
        // cout << ans << endl;
    }
    auto halfBound = lower_bound(A.begin(), A.end(), HALF_MAX);
    divided = A.end() - halfBound;
    divided = divided * (divided - 1) / 2;
    ans -= divided * MAX;
    cout << ans << endl;

    return 0;
}
