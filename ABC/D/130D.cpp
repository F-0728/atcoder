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
    ll K;
    cin >> N >> K;
    vll A(N);
    vll cmlSum(N + 1, 0);
    rep(i, N) {
        cin >> A[i];
        cmlSum[i + 1] = cmlSum[i] + A[i];
    }

    ll ans = 0;
    ll l = 1, r = 1;
    for (ll i = 1; i <= N; i++) {
        l = i;
        while (cmlSum[min(N, r)] - cmlSum[l - 1] < K) {
            r++;
            if (r > N) {
                break;
            }
        }
        if (r < N) {
            ans += N - r + 1;
            // cout << "ans: " << ans << endl;
            continue;
        }
        if (r >= N && cmlSum[N] - cmlSum[l - 1] >= K) {
            ans++;
            // cout << "ans: " << ans << endl;
        }
    }
    cout << ans << endl;

    return 0;
}
