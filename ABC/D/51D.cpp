#include <atcoder/all>
#include <bitset>
#include <chrono>
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
#define vld vector<ld>
#define vbool vector<bool>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvbool vector<vector<bool>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}
void outvmint(const vector<mint>& v) {
    for (const auto& e : v) {
        cout << e.val() << " ";
    }
    cout << endl;
}
template <typename T>
void outvv(const vector<vector<T>>& vv) {
    for (const auto& v : vv) {
        outv(v);
    }
}
void outvvmint(const vector<vector<mint>>& vv) {
    for (const auto& v : vv) {
        outvmint(v);
    }
}
template <typename T>
void outvp(const vector<pair<T, T>>& vp) {
    for (const auto& p : vp) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vpll> G(N);
    map<pll, ll> mp;
    vbool used(M, false);
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
        mp[{a, b}] = i;
        mp[{b, a}] = i;
    }

    rep(i, N) {
        ll start = i;
        vll dist(N, INF);
        vvll prev(N);
        priority_queue<vll, vvll, greater<vll>> pq;
        pq.push({0, start, -1});
        while (!pq.empty()) {
            ll d, v, p;
            d = pq.top()[0];
            v = pq.top()[1];
            p = pq.top()[2];
            pq.pop();
            if (dist[v] < d) continue;
            if (dist[v] == d) {
                prev[v].push_back(p);
            } else {
                prev[v] = {p};
            }
            dist[v] = d;
            for (auto [nv, c] : G[v]) {
                if (dist[nv] >= d + c) {
                    pq.push({d + c, nv, v});
                }
            }
        }
        rep(j, N) {
            for (auto p : prev[j]) {
                if (p != -1) {
                    used[mp[{j, p}]] = true;
                }
            }
        }
    }

    ll ans = 0;
    rep(i, M) {
        if (!used[i]) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
