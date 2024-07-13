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
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }
    for (ll b = K + 1; b <= N; b++) {
        ll div = N / b;
        ll rem = N % b;
        ans += div * (b - K) + max(0LL, rem - K + 1);
    }
    cout << ans << endl;


    return 0;
}
