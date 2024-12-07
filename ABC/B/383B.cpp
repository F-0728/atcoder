#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <chrono>
#include <bitset>
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
ll power(ll x, ll y) {ll res = 1; while(y > 0){if (y % 2 == 1) {res *= x;} x *= x; y >>= 1;}return res;}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll H, W, D;
    cin >> H >> W >> D;
    vector<string> S(H);
    rep(i, H) {
        cin >> S[i];
    }

    vpll yuka;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '.') {
                yuka.push_back({i, j});
            }
        }
    }

    ll N = yuka.size();
    ll ans = 0;
    rep(i, N - 1) {
        for (ll j = i + 1; j < N; j++) {
            pll yuka1 = yuka[i];
            pll yuka2 = yuka[j];

            vvbool hum(H, vbool(W, false));
            queue<pair<ll, pll>> q;
            q.push({D, yuka1});
            q.push({D, yuka2});
            while (!q.empty()) {
                auto [d, yuka] = q.front();
                q.pop();
                ll x = yuka.first;
                ll y = yuka.second;
                if (x < 0 || x >= H || y < 0 || y >= W) continue;
                if (hum[x][y]) continue;
                hum[x][y] = true;
                if (d == 0) continue;
                for (auto [dx, dy] : dir) {
                    q.push({d - 1, {x + dx, y + dy}});
                }
            }
            ll res = 0;
            rep(x, H) {
                rep(y, W) {
                    if (hum[x][y] && S[x][y] == '.') res++;
                }
            }
            ans = max(ans, res);
        }
    }

    cout << ans << endl;

    return 0;
}
