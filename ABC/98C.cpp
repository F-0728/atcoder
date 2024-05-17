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
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    string S;
    cin >> N >> S;
    vll E(N+1, 0), W(N+1, 0);
    rep(i, N) {
        if (S[i] == 'E') {
            E[i+1] = E[i] + 1;
            W[i+1] = W[i];
        } else {
            E[i+1] = E[i];
            W[i+1] = W[i] + 1;
        }
    }
    ll ans = N;
    rep(i, N) {
        ll tmp = W[i] + E[N] - E[i+1];
        ans = min(ans, tmp);
    }
    cout << ans << endl;

    

    return 0;
}
