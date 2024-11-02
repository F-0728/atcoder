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
    ll N, M;
    cin >> N >> M;
    vvll G(N);
    rep(i, M) {
        ll A, B;
        cin >> A >> B;
        A--, B--;
        G.at(A).push_back(B);
        G.at(B).push_back(A);
    }

    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll x, k;
        cin >> x >> k;
        x--;
        set<ll> ans;
        queue<pll> q;
        q.push({x, 0});
        while (!q.empty()) {
            auto [now, d] = q.front();
            q.pop();
            if (d == k) {
                ans.insert(now);
                continue;
            }
            ans.insert(now);
            for (auto next : G.at(now)) {
                q.push({next, d + 1});
            }
        }
        ll sum = 0;
        for (auto e : ans) {
            sum += e + 1;
        }
        cout << sum << endl;
    }

    return 0;
}
