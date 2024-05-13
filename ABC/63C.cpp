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
    vector<ll> S(N);
    ll ans = 0;
    rep(i, N) {
        ll s;
        cin >> s;
        S[i] = s;
        ans += s;
    }

    sort(S.begin(), S.end());

    if (ans % 10 != 0) {
        cout << ans << endl;
        return 0;
    }

    rep(i, N) {
        if (S[i] % 10 != 0) {
            cout << ans - S[i] << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
