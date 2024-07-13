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
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll N, M;
    cin >> N >> M;
    vll H(N), W(M);
    rep(i, N) cin >> H.at(i);
    rep(i, M) cin >> W.at(i);
    sort(H.begin(), H.end());
    vll sumL(N / 2 + 1, 0), sumR(N / 2 + 1, 0);
    for (ll i = 1; i <= N - 2; i += 2) {
        sumL.at(i / 2 + 1) = sumL.at(i / 2) + abs(H.at(i) - H.at(i - 1));
    }
    for (ll i = N - 2; i >= 1; i -= 2) {
        sumR.at(i / 2) = sumR.at(i / 2 + 1) + abs(H.at(i) - H.at(i + 1));
    }
    // rep(i, N / 2 + 1) {
    //     cout << sumL.at(i) << " " << sumR.at(i) << endl;
    // }
    ll ans = 1e16;
    rep(i, M) {
        ll sum = 0;
        ll j = lower_bound(H.begin(), H.end(), W.at(i)) - H.begin();
        if (j >= N) {
            sum = sumL.at(N / 2) + abs(W.at(i) - H.at(N - 1));
        }
        else if (j == 0) {
            sum = sumR.at(0) + abs(H.at(0) - W.at(i));
        }
        else if (j % 2 == 0) {
            sum = sumL.at(j / 2) + sumR.at(j / 2) + abs(H.at(j) - W.at(i));
        }
        else {
            sum = sumL.at(j / 2) + sumR.at(j / 2) + abs(H.at(j - 1) - W.at(i));
        }
        ans = min(ans, sum);
        // if (ans == sum) cout << ans << endl;
    }
    cout << ans << endl;
    

    return 0;
}
