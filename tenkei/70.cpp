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

int main() {
    ll N;
    vector<ll> X;
    vector<ll> Y;
    cin >> N;

    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll xMed = X[N / 2];
    ll yMed = Y[N / 2];

    ll ans = 0;
    rep(i, N) {
        ans += abs(X[i] - xMed);
        ans += abs(Y[i] - yMed);
    }

    cout << ans << endl;


    return 0;
}
