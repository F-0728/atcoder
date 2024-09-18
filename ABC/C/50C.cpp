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
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());

    mint ans = 1;
    ll now = 1;

    if (N % 2 != 0) {
        if (A[0] != 0 || (N >= 2 && A[1] == 0)) {
            cout << 0 << endl;
            return 0;
        }
        A.erase(A.begin());
        N--;
        now = 2;
    }

    for (ll i = 0; i < N; i++) {
        if (A[i] != now) {
            cout << 0 << endl;
            return 0;
        }
        if (i % 2 != 0) {
            ans *= 2;
            now += 2;
        }
    }

    cout << ans.val() << endl;

    return 0;
}
