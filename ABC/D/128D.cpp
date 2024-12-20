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
    ll N, K;
    cin >> N >> K;
    deque<ll> q;
    rep(i, N) {
        ll v;
        cin >> v;
        q.push_back(v);
    }

    ll ans = 0;
    rep(i, K + 1) {
        ll pull = i;
        ll push = K - i;
        if (pull > N) continue;
        rep(j, pull + 1) {
            deque<ll> nq = q;
            multiset<ll> s;
            rep(k, j) {
                ll v = nq.front();
                nq.pop_front();
                s.insert(v);
            }
            rep(k, pull - j) {
                ll v = nq.back();
                nq.pop_back();
                s.insert(v);
            }
            rep(k, push) {
                if (s.empty()) break;
                ll v = *s.begin();
                if (v > 0) {
                    break;
                }
                s.erase(s.find(v));
            }
            // cout << "pull: " << pull << " push: " << push << " j: " << j << " ";
            // cout << "sum: " << reduce(s.begin(), s.end()) << endl;
            ll sum = reduce(s.begin(), s.end());
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;

    return 0;
}
