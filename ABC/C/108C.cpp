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

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

int main() {
    ll N, K;
    cin >> N >> K;

    if (K % 2 == 0){
        ll a = K / 2;
        cout << power(N / K, 3) + power((N + a) / K, 3) << endl;
        return 0;
    }
    cout << power(N / K, 3) << endl;

    return 0;
}
