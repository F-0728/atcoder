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
    ll N, M;
    cin >> N >> M;
    vll A(2 * N);
    rep(i, N) {
        ll a;
        cin >> a;
        A.at(i) = a % M;
    }
    rep(i, N) {
        A.at(i + N) = A.at(i);
    }

    vll cSum(2 * N + 1, 0);
    rep(i, 2 * N) {
        cSum.at(i + 1) = cSum.at(i) + A.at(i);
        cSum.at(i + 1) %= M;
    }

    ll ans = 0;
    map<ll, ll> rem;
    // rep(i, N + 1) {
    //     rem[cSum.at(i)]++;
    // }
    // for (auto [key, value] : rem) {
    //     cout << key << " " << value << endl;
    //     ans += value * (value - 1) / 2;
    // }

    // rem[0]--;
    rep(i, N) {
        rem[cSum.at(i)]++;
    }
    ll once = 0;
    for (auto [key, value] : rem) {
        once += value * (value - 1) / 2;
    }
    rem.clear();
    rep(i, 2 * N) {
        // if (cSum.at(i) == 1 && i > N) {
        //     cout << i << endl;
        //     cout << rem[cSum.at(i)] << endl;
        //     cout << rem[cSum.at(i - N)] << endl;
        // }
        if (i >= N) {
            rem[cSum.at(i - N)]--;
        }
        ans += rem[cSum.at(i)];
        rem[cSum.at(i)]++;
        // cout << ans << endl;
    }
    // for (auto [key, value] : rem) {
    //     cout << key << " " << value << endl;
    // }

    ans -= once;
    cout << ans << endl;

    return 0;
}
