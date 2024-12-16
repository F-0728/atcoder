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
using LL = __int128_t;
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

ll N;
vll C;
vll weight;
void dfs(ll v, ll p, vvll& G, vll& C) {
    ll res = C[v];
    for (ll nv : G[v]) {
        if (nv == p) continue;
        if (weight[nv] == 0) {
            dfs(nv, v, G, C);
        }
        res += weight[nv];
    }
    weight[v] = res;
}

int main() {
    cin >> N;
    vvll G(N);
    rep(i, N - 1) {
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    C.resize(N);
    weight.assign(N, 0);
    ll weightSum = 0;

    vll C(N);
    rep(i, N) { cin >> C[i]; }
    rep(i, N) {
        weightSum += C[i];
    }

    dfs(0, -1, G, C);

    vll dist(N, INF);
    queue<pll> q;
    q.push({0, 0});
    while (!q.empty()) {
        ll d = q.front().first;
        ll v = q.front().second;
        q.pop();
        dist[v] = d;
        for (ll nv : G[v]) {
            if (dist[nv] != INF) continue;
            q.push({d + 1, nv});
        }
    }

    vector<LL> score(N, INF);
    LL now = 0;
    rep(i, N) { now += C[i] * dist[i]; }
    score[0] = now;

    queue<ll> q2;
    q2.push(0);
    while (!q2.empty()) {
        ll v = q2.front();
        q2.pop();
        for (ll nv : G[v]) {
            if (score[nv] != INF) continue;
            ll next = score[v] - weight[nv] + weightSum - weight[nv];
            score[nv] = next;
            q2.push(nv);
        }
    }

    // outv(score);

    LL ans = score[0];
    rep(i, N) { ans = min(ans, score[i]); }

    cout << (ll)ans << endl;

    return 0;
}
