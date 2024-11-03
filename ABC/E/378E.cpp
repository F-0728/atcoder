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
#define vld vector<ld>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
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

ll op(ll a, ll b) { return a + b; }

ll e() { return 0; }

int main() {
    ll N, M;
    cin >> N >> M;
    vll A(N);
    rep(i, N) { cin >> A[i]; }

    vll cSum(N + 1, 0);
    rep(i, N) {
        cSum[i + 1] = cSum[i] + A[i];
        cSum[i + 1] %= M;
    }

    vll order(N + 1);
    rep(i, N + 1) { order[i] = i; }
    sort(order.begin(), order.end(),
         [&](ll a, ll b) { 
            if (cSum[a] == cSum[b]) {
                return a > b;
            } else {
                return cSum[a] > cSum[b];
            }
         });

    vll cSumcSum(N + 2, 0);
    rep(i, N + 1) {
        cSumcSum[i + 1] = cSumcSum[i] + cSum[i];
    }

    map<ll, ll> count;
    rep(i, N + 1) {
        count[cSum[i]]++;
    }

    ll ans = 0;
    segtree<ll, op, e> countseg(N + 1);

    rep(i, N + 1) {
        ll idx = order[i];
        countseg.set(idx, 1);

        ans += idx * cSum[idx];
        ans -= cSumcSum[idx];
        ans += countseg.prod(0, idx) * M;
    }

    // for (auto [k, v] : count) {
    //     ans -= M * (v * (v - 1) / 2);
    // }

    cout << ans << endl;

    return 0;
}
