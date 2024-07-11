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

int main() {
    ll N;
    cin >> N;
    map<ll, ll> mp;
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        ll count = 1;
        while (x % 2 == 0) {
            x /= 2;
            count *= 2;
        }
        mp[x] += y * count;
    }
    ll ans = 0;
    for (auto [x, y] : mp) {
        // cout << x << " " << y << endl;
        while (y > 0) {
            if (y % 2 == 1) {
                ans++;
            }
            y /= 2;
        }
    }
    cout << ans << endl;

    return 0;
}
