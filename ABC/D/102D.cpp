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
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    vll cSum(N + 1, 0);
    rep(i, N) cSum[i + 1] = cSum[i] + A[i];
    // outv(cSum);

    ll ans = INF;
    for (ll i = 1; i < N - 1; i++) {
        ll PQ = cSum[i + 1];
        vll p = {lower_bound(cSum.begin(), cSum.end(), PQ / 2) - cSum.begin() - 2};
        if (p[0] < i - 1) {
            p.push_back(p[0] + 1);
        }
        ll RS = cSum[N] - PQ;
        vll r = {lower_bound(cSum.begin(), cSum.end(), PQ + RS / 2) - cSum.begin() - 2};
        if (r[0] == i) {
            r[0]++;
        }
        if (r[0] != N - 1) {
            r.push_back(r[0] + 1);
        }
        for (ll pNow : p) {
            for (ll rNow : r) {
                vll now = {cSum[pNow + 1], PQ - cSum[pNow + 1], cSum[rNow + 1] - PQ, cSum[N] - cSum[rNow + 1]};
                // outv(now);
                sort(now.begin(), now.end());
                if (now[0] <= 0) {
                    continue;
                }
                ans = min(ans, now[3] - now[0]);
            }
        } 
    }

    cout << ans << endl;

    return 0;
}
