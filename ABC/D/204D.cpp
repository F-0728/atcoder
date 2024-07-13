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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll N;
    cin >> N;
    vll dishes(N);
    ll sum = 0;
    rep(i, N) {
        cin >> dishes.at(i);
        sum += dishes.at(i);
    }
    vector<vector<bool>> dp(N + 1, vector<bool>(100005, false));
    dp.at(0).at(0) = true;
    rep(i, N + 1) {
        if (i == 0) continue;
        rep(j, 100001) {
            if (dp.at(i - 1).at(j)) {
                dp.at(i).at(j) = true;
                dp.at(i).at(j + dishes.at(i - 1)) = true;
            }
        }
    }
    ll m = (sum + 1) / 2;
    while (1) {
        if (dp.at(N).at(m)) {
            cout << m << endl;
            return 0;
        }
        m++;
    }

    return 0;
}
