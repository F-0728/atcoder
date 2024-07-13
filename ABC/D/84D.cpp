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

vector<bool> primes(ll n) {
    vector<bool> res(n+1, true);
    res[0] = false;
    res[1] = false;
    rep(i, 2) res.push_back(false);
    for (ll i = 2; i <= n; i++) {
        if (res[i]) {
            for (ll j = 2 * i; j <= n; j += i) {
                res[j] = false;
            }
        }   
    }
    return res;
}

int main() {
    ll Q;
    cin >> Q;
    vector<bool> prime = primes(100001);

    vll good(100001, 0);
    rep(i, 100000) {
        ll num = (i + 1) / 2;
        if (prime[i + 1] && prime[num + 1] && i % 2 == 0) {
            good[i + 1] = 1;
        }
    }

    vll sum(100002, 0);
    rep(i, 100001) { sum[i + 1] = sum[i] + good[i]; }
    // rep(i, 100) { cout << i << " " << sum[i] << endl;}
    rep(i, Q) {
        ll l, r;
        cin >> l >> r;
        cout << sum[r + 1] - sum[l] << endl;
    }

    return 0;
}
