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
using ld = long double;
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
    ll N, M, K;
    cin >> N >> M >> K;

    vvll oktests;
    vvll ngtests;
    rep(i, M) {
        ll C;
        cin >> C;
        vll now(C);
        rep(j, C) {
            cin >> now[j];
        }
        char t;
        cin >> t;
        if (t == 'o') {
            oktests.push_back(now);
        } else {
            ngtests.push_back(now);
        }
    }

    ll ans = 0;
    rep(i, 1 << N) {
        bool ok = true;
        rep(j, oktests.size()) {
            ll count = 0;
            rep(k, oktests[j].size()) {
                if (i & (1 << (oktests[j][k] - 1))) {
                    count++;
                }
            }
            if (count < K) {
                ok = false;
                break;
            }
        }
        rep(j, ngtests.size()) {
            ll count = 0;
            rep(k, ngtests[j].size()) {
                if (i & (1 << (ngtests[j][k] - 1))) {
                    count++;
                }
            }
            if (count >= K) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
