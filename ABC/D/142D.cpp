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

vll primeF(ll x) {
    vll res = {1};
    ll i = 2;
    while (x > 1) {
        while (i * i <= x) {
            if (x % i == 0) {
                res.push_back(i);
                while (x % i == 0) {
                    x /= i;
                }
            } else {
                i++;
            }
        }
        if (x > 1) {
            res.push_back(x);
            x = 1;
        }
    }
    return res;
}

int main() {
    ll A, B;
    cin >> A >> B;
    ll C = gcd(A, B);
    vll divs = primeF(C);
    ll ans = divs.size();
    cout << ans << endl;

    return 0;
}
