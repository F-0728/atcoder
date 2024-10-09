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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M;
    cin >> N >> M;
    vpll AB(M);
    rep(i, M) {
        cin >> AB[i].first >> AB[i].second;
        AB[i].first--;
        AB[i].second--;
    }

    ll K;
    cin >> K;
    vpll CD(K);
    rep(i, K) {
        cin >> CD[i].first >> CD[i].second;
        CD[i].first--;
        CD[i].second--;
    }
    ll ans = 0;
    rep(i, 1 << K) {
        vll dish(N, 0);
        rep(j, K) {
            if (i >> j & 1) {
                dish[CD[j].first]++;
            } else {
                dish[CD[j].second]++;
            }
        }
        ll cnt = 0;
        rep(j, M) {
            if (dish[AB[j].first] > 0 && dish[AB[j].second] > 0) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}
