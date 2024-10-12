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
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vpll points(N);
    rep(i, N){
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    ld ans = 0;
    pll now = {0, 0};
    rep(i, N) {
        ans += hypot(points[i].first - now.first, points[i].second - now.second);
        now = points[i];
    }
    ans += hypot(now.first, now.second);

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
