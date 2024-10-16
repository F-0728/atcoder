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
    ll D, G;
    cin >> D >> G;
    G /= 100;
    vpll points(D);
    rep(i, D) {
        ll p, c;
        cin >> p >> c;
        c /= 100;
        points[i] = {p, c};
    }

    ll ans = INF;
    rep(i, 1 << D) {
        ll score = 0;
        ll solved = 0;
        rep(j, D) {
            if (i & (1 << j)) {
                score += points[j].first * (j + 1) + points[j].second;
                solved += points[j].first;
            }
        }
        if (score >= G) {
            ans = min(ans, solved);
            continue;
        }
        for (ll j = D - 1; j >= 0; j--) {
            if (i & (1 << j)) continue;
            ll solveNow;
            ll q = (G - score - 1) / (j + 1) + 1;
            solveNow = min(points[j].first, q);
            if (solveNow == points[j].first) {
                score += points[j].first * (j + 1) + points[j].second;
            } else {
                score += solveNow * (j + 1);
            }
            solved += solveNow;
            if (score >= G) {
                ans = min(ans, solved);
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
