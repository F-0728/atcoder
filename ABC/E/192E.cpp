#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    X--;
    Y--;
    dsu d(N);
    vector<vector<vector<ll>>> path(N);
    rep(i, M) {
        ll A, B, T, K;
        cin >> A >> B >> T >> K;
        A--;
        B--;
        d.merge(A, B);
        path.at(A).push_back({B, T, K});
        path.at(B).push_back({A, T, K});
    }
    if (!d.same(X, Y)) {
        cout << -1 << endl;
        return 0;
    }
    vll dist(N, INF);
    dist.at(X) = 0;
    priority_queue<pair<ll, ll>, vpll, greater<pair<ll, ll>>> pq;
    pq.push({0, X});
    while (!pq.empty()) {
        auto [d, x] = pq.top();
        pq.pop();
        if (dist.at(x) < d) {
            continue;
        }
        for (vector<ll> v : path.at(x)) {
            ll y = v.at(0);
            ll t = v.at(1);
            ll k = v.at(2);
            ll wait = (d + k - 1) / k * k;
            if (dist.at(y) > wait + t) {
                dist.at(y) = wait + t;
                pq.push({dist.at(y), y});
            }
        }
    }
    cout << dist.at(Y) << endl;
    return 0;
}
