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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vvll G(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    vpll security(K);
    rep(i, K) {
        ll c, d;
        cin >> c >> d;
        c--;
        security.at(i) = {c, d};
    }
    vll dist(N, -INF);
    priority_queue<pll> q;
    rep(i, K) {
        auto [c, d] = security.at(i);
        q.push({d, c});
        dist.at(c) = d;
    }
    while (!q.empty()) {
        auto [hp, now] = q.top();
        q.pop();
        if (dist.at(now) != hp) continue;
        for (auto next : G.at(now)) {
            if (dist.at(next) < hp - 1) {
                dist.at(next) = hp - 1;
                q.push({hp - 1, next});
            }
        }
    }
    vll ans;
    rep(i, N) {
        if (dist.at(i) >= 0) {
            ans.push_back(i + 1);
        }
    }
    // outv(dist);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    outv(ans);

    return 0;
}
