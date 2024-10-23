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
    if (M < 0) {
        cout << -1 << endl;
        return 0;
    }
    if (M == N) {
        cout << -1 << endl;
        return 0;
    }
    if (N == 1) {
        if (M != 0) {
            cout << -1 << endl;
        } else {
            cout << 1 << " " << 2 << endl;
        }
        return 0;
    }

    vpll ans;
    ll l = 0, r = 1;
    rep(i, M + 1) {
        l += 2;
        r += 2;
        ans.push_back({l, r});
    }
    ans.push_back({1, r + 1});
    l++, r++;
    rep(i, N - M - 2) {
        l += 2;
        r += 2;
        ans.push_back({l, r});
    }

    if (N - M - 2 < 0) {
        cout << -1 << endl;
        return 0;
    }

    for (auto e : ans) {
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}
