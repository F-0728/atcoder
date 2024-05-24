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

vector<ll> divisors(ll x) {
    vector<ll> divs;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs.push_back(i);
            if (i * i != x) {
                divs.push_back(x / i);
            }
        }
    }
    sort(divs.rbegin(), divs.rend());
    return divs;
}

int main() {
    ll N;
    cin >> N;
    vll a(N + 1);
    rep(i, N) cin >> a.at(i + 1);
    vvll divsN(N + 1);
    rep(i, N + 1) divsN.at(i) = divisors(i);

    vvll op(N + 1);
    rep(i, N + 1) {
        for (ll j : divsN.at(i)) {
            op.at(j).push_back(i);
        }
    }

    vll balls(N + 1, 0);
    ll ans = 0;
    for (ll i = N; i >= 1; i--) {
        ll ballSum = 0;
        for (ll j : op.at(i)) {
            if (i != j) ballSum += balls.at(j);
        }
        if (ballSum % 2 != a.at(i)) {
            balls.at(i) += 1;
            ans += 1;
        }
    }
    cout << ans << endl;
    for (ll i = 1; i <= N; i++) {
        if (balls.at(i) == 1) {
            cout << i << " ";
        }
    }

    return 0;
}
