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
    ll N, M;
    cin >> N >> M;

    vvll S(M);
    rep(i, M) {
        ll C;
        cin >> C;
        rep(j, C) {
            ll s;
            cin >> s;
            S[i].push_back(s);
        }
    }

    vvll bitSearch;
    rep(i, 1 << M) {
        vll v;
        rep(bit, M) {
            if (i & (1 << bit)) {
                v.push_back(bit);
            }
        }
        bitSearch.push_back(v);
    }

    ll ans = 0;

    for (auto V : bitSearch) {
        vector<bool> has(N, false);
        for (auto v : V) {
            for (auto s : S[v]) {
                has[s - 1] = true;
            }
        }
        bool ok = true;
        rep(i, N) {
            if (!has[i]) {
                ok = false;
            }
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
