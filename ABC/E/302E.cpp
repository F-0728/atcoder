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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, Q;
    cin >> N >> Q;
    map<ll, set<ll>> mp;
    ll ans = N;
    rep(i, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll u, v;
            cin >> u >> v;
            if (mp[u].size() == 0) {
                ans -= 1;
            }
            if (mp[v].size() == 0) {
                ans -= 1;
            }
            mp[v].insert(u);
            mp[u].insert(v);
        } else {
            ll v;
            cin >> v;
            for (ll u : mp[v]) {
                if (mp[u].size() == 1) {
                    ans += 1;
                    mp[u].clear();
                } else {
                    mp[u].erase(v);
                }
            }
            if (mp[v].size() != 0) {
                mp[v].clear();
                ans += 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
