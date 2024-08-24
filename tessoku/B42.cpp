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
    ll N;
    cin >> N;
    vpll A(N);
    rep(i, N) {
        cin >> A.at(i).first >> A.at(i).second;
    }

    vpll YgteX;
    vpll YlteX;
    vpll YgteMX;
    vpll YlteMX;

    rep(i, N) {
        ll x = A.at(i).first;
        ll y = A.at(i).second;
        if (y >= x) {
            YgteX.push_back({x, y});
        }
        if (y <= x) {
            YlteX.push_back({x, y});
        }
        if (y >= -x) {
            YgteMX.push_back({x, y});
        }
        if (y <= -x) {
            YlteMX.push_back({x, y});
        }
    }
    ll ans = -INF;

    ll sumX = 0, sumY = 0;
    rep(i, YgteX.size()) {
        sumX += YgteX.at(i).first;
        sumY += YgteX.at(i).second;
    }
    ans = max(ans, abs(sumX) + abs(sumY));

    sumX = 0, sumY = 0;
    rep(i, YlteX.size()) {
        sumX += YlteX.at(i).first;
        sumY += YlteX.at(i).second;
    }
    ans = max(ans, abs(sumX) + abs(sumY));

    sumX = 0, sumY = 0;
    rep(i, YgteMX.size()) {
        sumX += YgteMX.at(i).first;
        sumY += YgteMX.at(i).second;
    }
    ans = max(ans, abs(sumX) + abs(sumY));

    sumX = 0, sumY = 0;
    rep(i, YlteMX.size()) {
        sumX += YlteMX.at(i).first;
        sumY += YlteMX.at(i).second;
    }
    ans = max(ans, abs(sumX) + abs(sumY));

    cout << ans << endl;

    return 0;
}
