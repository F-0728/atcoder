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
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M;
    cin >> N >> M;

    vpll relation(M);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        relation[i] = {a, b};
    }

    ll ans = 1;
    rep(i, 1 << N) {
        ll n = popcount(unsigned(i));
        map<ll, ll> mp;
        rep(j, M) {
            if (i & (1 << relation[j].first) && i & (1 << relation[j].second)) {
                mp[relation[j].first]++;
                mp[relation[j].second]++;
            }
        }
        bool ok = true;
        for (auto p : mp) {
            if (p.second < n - 1) {
                ok = false;
                break;
            }
        }
        if (mp.empty()) ok = false;
        if (ok) {
            ans = max(ans, n);
        }
    }

    cout << ans << endl;

    return 0;
}
