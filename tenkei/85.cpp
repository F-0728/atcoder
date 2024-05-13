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
    ll K;
    cin >> K;
    vector<ll> divs;

    for (ll i = 1; i * i <= K; i++) {
        if (K % i == 0) {
            divs.push_back(i);
            if (i * i != K) {
                divs.push_back(K / i);
            }
        }
    }

    sort(divs.begin(), divs.end());

    ll ans = 0;
    rep(i, divs.size()) {
        for (ll j = i; j < divs.size(); j++) {
            ll k = K / divs[i] / divs[j];
            if (k >= divs[j] && K % (divs[i] * divs[j]) == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
