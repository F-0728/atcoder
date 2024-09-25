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
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    queue<pll> q;
    q.push({0, 0});

    ll water = -INF, sugar = -INF;
    set<pll> done;
    while (!q.empty()) {
        auto [w, s] = q.front();
        q.pop();

        if (w + s > F) continue;
        if (s * 100 > w * E) continue;
        if (done.count({w, s})) continue;
        done.insert({w, s});

        if (sugar * (w + s) < (water + sugar) * s) {
            water = w;
            sugar = s;
        }

        q.push({w + A * 100, s});
        q.push({w + B * 100, s});
        q.push({w, s + C});
        q.push({w, s + D});
    }

    cout << water + sugar << " " << sugar << endl;


    return 0;
}
