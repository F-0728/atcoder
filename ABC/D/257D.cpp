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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vvll jump(N, vll(3));
    rep(i, N) {
        rep(j, 3) {
            cin >> jump.at(i).at(j);
        }
    }

    vvld dist(N, vld(N, INF));
    rep(i, N) {
        dist.at(i).at(i) = 0;
    }
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            ll d = abs(jump.at(i).at(0) - jump.at(j).at(0)) + abs(jump.at(i).at(1) - jump.at(j).at(1));
            ld cost = (ld)d / jump.at(i).at(2);
            dist.at(i).at(j) = cost;
        }
    }

    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                dist.at(i).at(j) = min(dist.at(i).at(j), dist.at(i).at(k) + dist.at(k).at(j));
            }
        }
    }

    ll l = 0, r = 4e9 + 5;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        bool ok = false;
        rep(i, N) {
            ll start = i;
            vector<bool> visited(N, false);
            queue<ll> q;
            q.push(start);
            while (!q.empty()) {
                ll v = q.front();
                q.pop();
                if (visited.at(v)) continue;
                visited.at(v) = true;
                rep(j, N) {
                    if (visited.at(j)) continue;
                    if (dist.at(v).at(j) <= mid) {
                        q.push(j);
                    }
                }
            }
            bool allVisited = true;
            rep(j, N) {
                if (!visited.at(j)) {
                    allVisited = false;
                    break;
                }
            }
            if (allVisited) {
                ok = true;
                break;
            }
        }
        if (ok) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << endl;

    return 0;
}
