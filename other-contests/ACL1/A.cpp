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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N;
    cin >> N;
    vpll points(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    vll order(N);
    rep(i, N) { order[i] = points[i].first - 1; }

    sort(points.begin(), points.end());

    dsu d(N);
    vpll stack;
    rep(i, N) {
        if (stack.empty()) {
            stack.push_back({points[i].second, i});
            continue;
        }
        if (stack.back().first > points[i].second) {
            stack.push_back({points[i].second, i});
            continue;
        }
        pll last = stack.back();
        while (!stack.empty() && stack.back().first < points[i].second) {
            d.merge(stack.back().second, i);
            stack.pop_back();
        }
        stack.push_back(last);
    }

    rep(i, N) {
        ll v = order[i];
        cout << d.size(v) << endl;
    }

    // auto ans = d.groups();
    // for (auto& group : ans) {
    //     for (auto& v : group) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
