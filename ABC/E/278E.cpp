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
    ll H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vvll grid(H, vll(W));
    rep(i, H) rep(j, W) cin >> grid.at(i).at(j);
    map<ll, ll> mp;
    rep(i, H) {
        rep(j, W) { mp[grid.at(i).at(j)]++; }
    }
    rep(k, H - h + 1) {
        rep(i, h) {
            rep(j, w) { mp[grid.at(k + i).at(j)]--; }
        }
        rep(l, W - w + 1) {
            ll ans = 0;
            for (auto [key, value] : mp) {
                if (value > 0) {
                    ans++;
                }
            }
            cout << ans << " ";
            if (l != W - w) {
                rep(i, h) {
                    mp[grid.at(k + i).at(l)]++;
                    mp[grid.at(k + i).at(l + w)]--;
                }
            }
        }
        cout << endl;
        rep(i, h) {
            rep(j, w) { mp[grid.at(k + i).at(W - j - 1)]++; }
        }
    }

    return 0;
}
