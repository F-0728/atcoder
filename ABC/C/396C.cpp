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
#define Yes cout << "Yes" << "\n"
#define No cout << "No" << "\n"
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
ll pc(ll x) { return __builtin_popcountll(x); }
void argsort(vll& v, vll& idx) {
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&v](ll i1, ll i2) { return v[i1] < v[i2]; });
}
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << "\n";
}
void outvmint(const vector<mint>& v) {
    for (const auto& e : v) {
        cout << e.val() << " ";
    }
    cout << "\n";
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
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    vll B(N);
    rep(i, N) { cin >> B[i]; }
    vll C(M);
    rep(i, M) { cin >> C[i]; }
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    vll cSum(N + 1, 0);
    rep(i, N) {
        cSum[i + 1] = cSum[i] + B[i];
    }

    vll cSum2(M + 1, 0);
    rep(i, M) {
        cSum2[i + 1] = cSum2[i] + C[i];
    }

    // outv(cSum);
    // outv(cSum2);

    ll positiveCount = 0;
    rep(i, N) {
        if (B[i] >= 0) {
            positiveCount++;
        }
    }

    ll maxB = 0;
    rep(i, positiveCount) {
        maxB += B[i];
    }

    ll ans = maxB;
    rep(i, M) {
        ll white = i + 1;
        ll sum = cSum2[i + 1];
        if (white > N) break;
        if (white <= positiveCount) {
            sum += maxB;
        } else {
            sum += cSum[white];
        }
        ans = max(ans, sum);
    } 

    cout << ans << "\n";

    return 0;
}
