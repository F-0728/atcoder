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
    ll N, K;
    string S;
    cin >> N >> K >> S;
    vll streak;
    if (S[0] == '0') {
        streak.push_back(0);
    }
    ll count = 0;
    rep(i, N) {
        if (i == 0) {
            count++;
        } else if (S[i] == S[i - 1]) {
            count++;
        } else {
            streak.push_back(count);
            count = 1;
        }
    }
    streak.push_back(count);
    if (S.back() == '0') {
        streak.push_back(0);
    }

    vll cumSum(streak.size() + 1, 0);
    rep(i, streak.size()) { cumSum[i + 1] = cumSum[i] + streak[i]; }

    ll ans = 0;
    for (ll left = 0; left < cumSum.size(); left += 2) {
        ll right = min(left + K * 2 + 1, (ll)cumSum.size() - 1);
        ans = max(ans, cumSum[right] - cumSum[left]);
    }
    cout << ans << endl;

    return 0;
}
