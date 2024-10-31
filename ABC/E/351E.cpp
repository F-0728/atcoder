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
    vpll points(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    vll evenX, oddX, evenY, oddY;
    rep(i, N) {
        ll X = points[i].first;
        ll Y = points[i].second;
        if ((X + Y) % 2 == 0) {
            evenX.push_back(X + Y);
            evenY.push_back(X - Y);
        } else {
            oddX.push_back(X + Y);
            oddY.push_back(X - Y);
        }
    }

    sort(evenX.begin(), evenX.end());
    sort(evenY.begin(), evenY.end());
    sort(oddX.begin(), oddX.end());
    sort(oddY.begin(), oddY.end());

    ll ans = 0;
    rep(i, evenX.size()) {
        ans += evenX.at(i) * (i * 2 + 1 - evenX.size());
    }
    rep(i, evenY.size()) {
        ans += evenY.at(i) * (i * 2 + 1 - evenY.size());
    }
    rep(i, oddX.size()) {
        ans += oddX.at(i) * (i * 2 + 1 - oddX.size());
    }
    rep(i, oddY.size()) {
        ans += oddY.at(i) * (i * 2 + 1 - oddY.size());
    }

    cout << ans / 2 << endl;
    


    return 0;
}
