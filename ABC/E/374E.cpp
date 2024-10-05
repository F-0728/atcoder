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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, X;
    cin >> N >> X;
    vector<pair<pll, pll>> machine(N);
    rep(i, N) {
        ll A, P, B, Q;
        cin >> A >> P >> B >> Q;
        machine[i] = {{A, P}, {B, Q}};
    }

    ll l = -1, r = 1e9 + 1;
    while (r - l > 1) {
        // mid...達成可能なminWの最大値
        ll mid = (l + r) / 2;
        vll cost(N, inf);
        rep(i, N) {
            ll A = machine[i].first.first;
            ll P = machine[i].first.second;
            ll B = machine[i].second.first;
            ll Q = machine[i].second.second;

            ll cnt = INF;
            rep(j, B + 1) {
                if (j * A > mid) break;
                ll rest = mid - j * A;
                cnt = min(cnt, j * P + (rest + B - 1) / B * Q);
            }
            rep(j, A + 1) {
                if (j * B > mid) break;
                ll rest = mid - j * B;
                cnt = min(cnt, j * Q + (rest + A - 1) / A * P);
            }
            cost[i] = cnt;
        }
        ll sum = 0;
        rep(i, N) {
            sum += cost[i];
        }
        if (sum > X) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << l << endl;

    return 0;
}
