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
    ll N, M, Sx, Sy;
    cin >> N >> M >> Sx >> Sy;
    map<ll, set<ll>> x;
    map<ll, set<ll>> y;
    rep(i, N) {
        ll X, Y;
        cin >> X >> Y;
        x[X].insert(Y);
        y[Y].insert(X);
    }

    vector<pair<char, ll>> action(M);
    rep(i, M) {
        char D;
        ll C;
        cin >> D >> C;
        action[i] = {D, C};
    }

    ll ans = 0;
    rep(i, M) {
        char D = action[i].first;
        ll C = action[i].second;
        vpll eraseList;
        // cout << D << " " << C << endl;
        // cout << Sx << " " << Sy << endl;
        // cout << ans << endl;
        if (D == 'U') {
            ll n = Sy + C;
            if (x[Sx].empty()) {
                Sy += C;
                continue;
            }
            auto prev = x[Sx].lower_bound(Sy);
            auto next = x[Sx].lower_bound(n);
            if (prev == x[Sx].end()) {
                Sy += C;
                continue;
            }
            while (prev != next) {
                ans++;
                ll Y = *prev;
                eraseList.push_back({Sx, Y});
                prev++;
            }
            if (*next == n) {
                ans++;
                eraseList.push_back({Sx, n});
            }
            Sy += C;
        }
        if (D == 'D') {
            ll n = Sy - C;
            if (x[Sx].empty()){
                Sy -= C;
                continue;
            }
            auto prev = x[Sx].lower_bound(Sy);
            auto next = x[Sx].lower_bound(n);
            if (prev == x[Sx].begin()) {
                Sy -= C;
                continue;
            }
            while (prev != next) {
                ans++;
                prev--;
                ll Y = *prev;
                eraseList.push_back({Sx, Y});
            }
            Sy -= C;
        }
        if (D == 'R') {
            ll n = Sx + C;
            if (y[Sy].empty()) {
                Sx += C;
                continue;
            }
            auto prev = y[Sy].lower_bound(Sx);
            auto next = y[Sy].lower_bound(n);
            if (prev == y[Sy].end()) {
                Sx += C;
                continue;
            }
            while (prev != next) {
                ans++;
                ll X = *prev;
                eraseList.push_back({X, Sy});
                prev++;
            }
            if (*next == n) {
                ans++;
                eraseList.push_back({n, Sy});
            }
            Sx += C;
        }
        if (D == 'L') {
            ll n = Sx - C;
            if (y[Sy].empty()) {
                Sx -= C;
                continue;
            }
            auto prev = y[Sy].lower_bound(Sx);
            auto next = y[Sy].lower_bound(n);
            if (prev == y[Sy].begin()) {
                Sx -= C;
                continue;
            }
            while (prev != next) {
                ans++;
                prev--;
                ll X = *prev;
                eraseList.push_back({X, Sy});
            }
            Sx -= C;
        }
        for (auto p : eraseList) {
            x[p.first].erase(p.second);
            y[p.second].erase(p.first);
        }
    }

    cout << Sx << " " << Sy << " " << ans << endl;

    return 0;
}
