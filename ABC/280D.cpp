#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

vll prime_fact(ll x) {
    vll res;
    ll i = 2;
    while (x > 1) {
        while (i * i <= x) {
            if (x % i == 0) {
                res.push_back(i);
                x /= i;
            } else {
                i++;
            }
        }
        if (x > 1) {
            res.push_back(x);
            break;
        }
    }
    return res;
}

int main() {
    ll K;
    cin >> K;
    vll fact = prime_fact(K);
    map<ll, ll> mp;
    for (ll f : fact) {
        mp[f]++;
    }
    ll ans = 0;
    for (auto [key, value] : mp) {
        ll res = 0;
        rep(i, value) {
            ll pow = 0;
            ll quotient = key * (i + 1);
            while (quotient % key == 0 && quotient > 1) {
                quotient /= key;
                pow++;
            }
            res += pow;
            if (res >= value) {
                res = key * (i + 1);
                ans = max(ans, res);
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
