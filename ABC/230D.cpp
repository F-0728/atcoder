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
    ll N, D;
    cin >> N >> D;
    vpll walls(N);
    rep(i, N) {
        ll l, r;
        cin >> l >> r;
        walls.at(i) = {r, l};
    } 
    sort(walls.begin(), walls.end());
    ll ans = 0;
    ll lastPunch = -INF;
    rep(i, N) {
        ll r = walls.at(i).first;
        ll l = walls.at(i).second;
        if (lastPunch + D - 1 < l) {
            lastPunch = r;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
