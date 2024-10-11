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
    ll N, M;
    cin >> N >> M;
    vector<vpll> query(M);
    rep(i, M) {
        ll k;
        cin >> k;
        rep(j, k) {
            ll a, b;
            cin >> a >> b;
            a--;
            query[i].push_back({a, b});
        }
    }

    rep(i, 1 << N) {
        vector<bool> ok(M, false);
        rep(j, M) {
            rep(k, query[j].size()) {
                ll a = query[j][k].first;
                ll b = query[j][k].second;
                if (i & (1 << a)) {
                    if (b == 1) ok[j] = true;
                }
                if (!(i & (1 << a))) {
                    if (b == 0) ok[j] = true;
                }
            }
        }
        bool flag = true;
        rep(j, M) {
            if (!ok[j]) flag = false;
        }
        if (flag) {
            Yes;
            return 0;
        }
    }

    No;

    return 0;
}
