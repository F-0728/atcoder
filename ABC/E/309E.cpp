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
    vvll G(N);
    rep(i, N - 1) {
        ll p;
        cin >> p;
        p--;
        G.at(p).push_back(i + 1);
    }
    vll insurance(N, -INF);
    rep(i, M) {
        ll v, w;
        cin >> v >> w;
        v--;
        insurance.at(v) = max(insurance.at(v), w);
    }
    vll covered(N, -INF);
    covered.at(0) = insurance.at(0);
    queue<ll> q;
    q.push(0);
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll u : G.at(v)) {
            if (insurance.at(u) >= 0) {
                covered.at(u) = max(covered.at(u), insurance.at(u));
            }
            covered.at(u) = max(covered.at(u), covered.at(v) - 1);
            q.push(u);
        }
    }
    
    ll ans = 0;
    rep(i, N) {
        if (covered.at(i) >= 0) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
