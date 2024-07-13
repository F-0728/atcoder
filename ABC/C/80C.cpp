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
    cin >> N;
    vector<vector<ll>> F(N, vector<ll>(10));
    vector<vector<ll>> P(N, vector<ll>(11));
    rep(i, N) {
        rep(j, 10) { cin >> F[i][j]; }
    }
    rep(i, N) {
        rep(j, 11) { cin >> P[i][j]; }
    }

    vector<vector<ll>> bitSearch;
    rep(i, 1 << 10) {
        vector<ll> S;
        rep(bit, 10) {
            if (i & (1 << bit)) {
                S.push_back(bit);
            }
        }
        bitSearch.push_back(S);
    }

    ll ans = -1e9;
    for(ll i = 1; i < bitSearch.size(); i++) {
        vector<ll> S = bitSearch[i];
        ll sum = 0;
        rep(j, N) {
            ll count = 0;
            rep(k, 10) {
                if (F[j][k] == 1 && find(S.begin(), S.end(), k) != S.end()) {
                    count++;
                }
            }
            sum += P[j][count];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;

    return 0;
}
