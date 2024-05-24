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
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A.at(i);
    vll x(N);
    ll x1 = 0;
    rep(i, N) {
        if (i % 2 == 0) x1 += A.at(i);
        else x1 -= A.at(i);
    }
    x.at(0) = x1;

    rep(i, N - 1) {
        x.at(i + 1) = 2 * A.at(i) - x.at(i);
    }

    rep(i, N) {
        cout << x.at(i) << " ";
    }

    return 0;
}
