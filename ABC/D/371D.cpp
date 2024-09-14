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
    vll X(N);
    rep(i, N) {
        cin >> X[i];
    }
    vll P(N);
    rep(i, N) {
        cin >> P[i];
    }
    vll PcSum(N + 1, 0);
    rep(i, N) {
        PcSum[i + 1] = PcSum[i] + P[i];
    }

    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll L, R;
        cin >> L >> R;
        ll left = lower_bound(X.begin(), X.end(), L) - X.begin();
        ll right = upper_bound(X.begin(), X.end(), R) - X.begin();
        cout << PcSum[right] - PcSum[left] << endl;
    }

    return 0;
}
