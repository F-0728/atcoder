#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

ll lis(vll& A) {
    ll N = A.size();
    vll dp(N + 1, INF);
    dp.at(0) = 0;
    rep(i, N) {
        ll idx = lower_bound(dp.begin(), dp.end(), A.at(i)) - dp.begin();
        dp.at(idx) = A.at(i);
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin() - 1;
}

int main() {
    ll N;
    cin >> N;
    vpll A(N);
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        A.at(i) = {a, b};
    }

    sort(A.begin(), A.end(), [](pll a, pll b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    vll B(N);
    rep(i, N) { B.at(i) = A.at(i).second; }

    cout << lis(B) << endl;

    return 0;
}
