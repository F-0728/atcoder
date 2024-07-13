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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) { cin >> A[i]; }
    set<ll> diffSet;
    rep(i, N) {
        for (ll j = i + 1; j < N; j++) {
            diffSet.insert(A[j] - A[i]);
        }
    }
    diffSet.insert(0);
    vll diff;
    for (auto d : diffSet) {
        diff.push_back(d);
    }
    ll M = diff.size();
    vector<vector<vector<mint>>> dp(
        N, vector<vector<mint>>(N + 1, vector<mint>(M, 0)));
    rep(i, N) {
        rep(j, M) {
            dp.at(i).at(1).at(j) = 1;
        }
        // 前回の要素全探索(前回: j)
        rep(j, i) {
            // 公差は確定
            ll diffCurrent = A[i] - A[j];
            ll diffIndex = lower_bound(diff.begin(), diff.end(), diffCurrent) - diff.begin();
            // 公差を固定，個数全探索(前回の個数: k)
            rep(k, i + 1) {
                dp.at(i).at(k + 1).at(diffIndex) += dp.at(j).at(k).at(diffIndex);
            }
        }
    }
    mint ans;
    rep(i, N + 1) {
        if (i == 0) continue;
        if (i == 1) {
            cout << N << " ";
            continue;
        }
        ans = 0;
        rep(j, N) {
            rep(k, M) {
                // if (dp.at(j).at(i).at(k) != 0) {
                //     cout << "dp[" << j << "][" << i << "][" << diff.at(k) << "] = " << dp.at(j).at(i).at(k).val() << endl;
                // }
                ans += dp.at(j).at(i).at(k);
            }
        }
        cout << ans.val() << " ";
    }
    cout << endl;

    return 0;
}
