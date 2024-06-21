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
    vll A(N);
    rep(i, N) cin >> A.at(i);

    vll lisForward(N);
    vll dpForward(N, INF);
    rep(i, N) {
        ll idx = lower_bound(dpForward.begin(), dpForward.end(), A.at(i)) - dpForward.begin();
        dpForward.at(idx) = A.at(i);
        lisForward.at(i) = lower_bound(dpForward.begin(), dpForward.end(), INF) - dpForward.begin();
    }

    reverse(A.begin(), A.end());
    vll lisBackward(N);
    vll dpBackward(N, INF);
    rep(i, N) {
        ll idx = lower_bound(dpBackward.begin(), dpBackward.end(), A.at(i)) - dpBackward.begin();
        dpBackward.at(idx) = A.at(i);
        lisBackward.at(i) = lower_bound(dpBackward.begin(), dpBackward.end(), INF) - dpBackward.begin();
    }

    ll ans = 0;
    rep(i, N) {
        ans = max(ans, lisForward.at(i) + lisBackward.at(N - i - 1) - 1);
    }
    cout << ans << endl;


    return 0;
}
