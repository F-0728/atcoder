#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A.at(i);
    sort(A.begin(), A.end());
    vector<bool> furuiOnArray(A.at(N - 1) + 1, true);
    rep(i, N) {
        ll num = A.at(i);
        if (furuiOnArray.at(num)) {
            for (ll j = num * 2; j <= A.at(N - 1); j += num) {
                furuiOnArray.at(j) = false;
            }
        }
        if (i < N - 1) {
            if (A.at(i) == A.at(i + 1)) {
                furuiOnArray.at(A.at(i)) = false;
            }
        }
    }
    ll ans = 0;
    rep(i, N) {
        if (furuiOnArray.at(A.at(i))) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
