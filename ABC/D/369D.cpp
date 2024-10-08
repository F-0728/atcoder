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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
    }
    
    vvll dp(N, vll(2, 0));
    dp.at(0).at(1) = A.at(0);
    for (ll i = 1; i < N; i++) {
        dp.at(i).at(0) = max(dp.at(i - 1).at(0), dp.at(i - 1).at(1) + A.at(i) * 2);
        dp.at(i).at(1) = max(dp.at(i - 1).at(1), dp.at(i - 1).at(0) + A.at(i));
    }

    cout << max(dp.at(N - 1).at(0), dp.at(N - 1).at(1)) << endl;

    return 0;
}
