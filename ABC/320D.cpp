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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vvll> G(N);
    vpll dist(N, {INF, INF});
    dist.at(0) = {0, 0};
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        ll x, y;
        cin >> x >> y;
        G.at(a).push_back({b, x, y});
        G.at(b).push_back({a, -x, -y});
    }
    queue<ll> q;
    q.push(0);
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (vll e : G.at(v)) {
            ll u = e.at(0);
            ll x = e.at(1);
            ll y = e.at(2);
            if (dist.at(u).first == INF) {
                dist.at(u).first = dist.at(v).first + x;
                dist.at(u).second = dist.at(v).second + y;
                q.push(u);
            }
        }
    }
    rep(i, N) {
        if (dist.at(i).first == INF || dist.at(i).second == INF) {
            cout << "undecidable" << endl;
        } else {
            cout << dist.at(i).first << " " << dist.at(i).second << endl;
        }
    }

    return 0;
}
