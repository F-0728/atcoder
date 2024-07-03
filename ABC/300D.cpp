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

vector<bool> furui(ll n) {
    vector<bool> res(n + 1, true);
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
    ll N;
    cin >> N;
    vector<bool> f = furui(1e6);
    vll primes;
    rep(i, 6e5) {
        if (f[i]) {
            primes.push_back(i);
        }
    }
    ll P = primes.size();
    ll ans = 0;
    rep(i, P) {
        ll A = primes.at(i) * primes.at(i);
        ll k = P - 1;
        for (ll j = i + 1; j < P; j++) {
            ll B = primes.at(j);
            while (k > j) {
                if (A * B > N) {
                    k--;
                    continue;
                }
                if (A * B * primes.at(k) > N) {
                    k--;
                    continue;
                }
                if (A * B * primes.at(k) * primes.at(k) > N) {
                    k--;
                    continue;
                }
                break;
            }
            if (k > j) {
                ans += k - j;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
