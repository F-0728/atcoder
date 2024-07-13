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
    vector<ll> ans(N);
    vector<ll> C(N-1), S(N-1), F(N-1);
    rep (i, N-1) cin >> C[i] >> S[i] >> F[i];
    rep(currentStation, N) {
        ll elapsed = 0;
        rep(i, N - 1) {
            if (i < currentStation) continue;
            if (S[i] > elapsed) {
                elapsed = S[i];
            } else {
                if (elapsed % F[i] != 0) {
                    elapsed += F[i] - elapsed % F[i];
                }
            }
            elapsed += C[i];
        }
        ans[currentStation] = elapsed;
    }
    rep(i, N) cout << ans[i] << endl;

    return 0;
}
