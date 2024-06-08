#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

ll powMod(ll x, ll y, ll MOD) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    string n = to_string(N);
    ll M = n.size();
    mint ans = 1;
    ll tmp = powMod(10, M, 998244353);
    ans *= powMod(tmp, N, 998244353);
    ans -= 1;
    ll divisor = powMod(10, M, 998244353) - 1;
    mint div = divisor;
    ans *= div.inv();
    ans *= N;
    cout << ans.val() << endl;

    return 0;
}
