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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll H, W, K;
    cin >> H >> W >> K;

    vector<string> S(H);
    rep(i, H) cin >> S[i];

    ll ans = INF;
    rep(i, 1 << (H - 1)) {
        ll n = 0;
        map<ll, vll> mp;
        rep(j, H - 1) {
            mp[n].push_back(j);
            if (i >> j & 1) {
                n++;
            }
        }
        mp[n].push_back(H - 1);
        vll count(n + 1, 0);
        ll res = n;
        ll lastCut = -1;
        bool ok = true;
        rep(j, W) {
            for (auto [k, v] : mp) {
                for (ll l : v) {
                    if (S[l][j] == '1') {
                        count[k]++;
                    }
                }
            }
            bool over = false;
            for (ll c : count) {
                if (c > K) {
                    over = true;
                }
            }
            if (over) {
                if (lastCut == j - 1) {
                    ok = false;
                    break;
                }
                lastCut = j - 1;
                res++;
                count = vll(n + 1, 0);
                j--;
            }
        }
        for (ll c : count) {
            if (c > K) {
                ok = false;
            }
        }
        if (ok) {
            // outv(count);
            // cout << res << endl;
            ans = min(ans, res);
        }
    }

    cout << ans << endl;

    return 0;
}
