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
    ll N, M, P;
    cin >> N >> M >> P;
    vll A(N);
    rep(i, N) {
        cin >> A.at(i);
    }
    vll B(M);
    rep(i, M) {
        cin >> B.at(i);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vll cSumB(M + 1, 0);
    rep(i, M) {
        cSumB.at(i + 1) = cSumB.at(i) + B.at(i);
    }
    ll ans = 0;
    rep(i, N) {
        ll idx = upper_bound(B.begin(), B.end(), P - A.at(i)) - B.begin();
        ans += A.at(i) * idx + cSumB.at(idx);
        ans += (M - idx) * P;
    }
    cout << ans << endl;

    return 0;
}
