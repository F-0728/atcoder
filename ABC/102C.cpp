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
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
        A[i] -= i + 1;
    }
    sort(A.begin(), A.end());
    ll b = A[N / 2];
    ll ans = 0;
    rep(i, N) {
        ans += abs(A[i] - b);
    }
    cout << ans << endl;

    return 0;
}
