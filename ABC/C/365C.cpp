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
    vll A(N);
    rep(i, N) cin >> A.at(i);
    sort(A.begin(), A.end());
    vll cSum(N + 1, 0);
    rep(i, N) {
        cSum.at(i + 1) = cSum.at(i) + A.at(i);
    }

    if (cSum.at(N) <= M) {
        cout << "infinite" << endl;
        return 0;
    }
    if (A.at(0) * N > M) {
        cout << M / N << endl;
        return 0;
    }

    ll l = 0, r = M;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll count = 0;
        rep(i, N) {
            count += min(A.at(i), mid);
        }
        if (count <= M) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;

    return 0;
}
