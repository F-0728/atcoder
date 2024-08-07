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
    string S;
    cin >> S;
    ll N = S.size();
    vector<vector<mint>> dp(N, vector<mint>(N, 0));
    if (N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (S.at(0) == '(' || S.at(0) == '?') {
        dp.at(0).at(1) = 1;
    } else {
        cout << 0 << endl;
        return 0;
    }
    rep(i, N - 1) {
        if (S.at(i + 1) == '(') {
            rep(j, N - 1) { dp.at(i + 1).at(j + 1) += dp.at(i).at(j); }
        } else if (S.at(i + 1) == ')') {
            rep(j, N - 1) { dp.at(i + 1).at(j) += dp.at(i).at(j + 1); }
        } else {
            rep(j, N - 1) {
                dp.at(i + 1).at(j + 1) += dp.at(i).at(j);
                dp.at(i + 1).at(j) += dp.at(i).at(j + 1);
            }
        }
    }
    cout << dp.at(N - 1).at(0).val() << endl;

    return 0;
}
