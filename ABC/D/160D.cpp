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
    ll N, X, Y; 
    cin >> N >> X >> Y;
    X--; Y--;
    vll ans(N, 0);
    rep(i, N - 1) {
        for (ll j = i + 1; j < N; j++) {
            ll d = min(j - i, abs(X - i) + abs(Y - j) + 1);
            // cout << i << j << d << endl;
            ans.at(d)++;
        }
    }
    rep(i, N - 1) {
        cout << ans.at(i + 1) << endl;
    }

    return 0;
}
