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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N, H;
    cin >> N >> H;
    vector<pair<ll, ll>> points(N);
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        points[i] = make_pair(a, b);
    }
    sort(points.begin(), points.end());

    pair<ll, ll> hold = points[N - 1];
    sort(points.begin(), points.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second > b.second; });
    ll hitTimes = 0;
    // nageru
    rep(i, points.size()) {
        if (points[i].second >= hold.first) {
            H-= points[i].second;
            hitTimes++;
        } else {
            break;
        }
        if (H <= 0) {
            cout << hitTimes << endl;
            return 0;
        }
    }
    // furu
    hitTimes += (H / hold.first) + (H % hold.first != 0);
    cout << hitTimes << endl;

    return 0;
}
