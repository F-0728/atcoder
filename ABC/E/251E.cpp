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
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    // 0...その回であげた 1...その回であげなかった
    vvll dpwith0(N, vll(2, INF));
    dpwith0.at(0).at(0) = A.at(0);
    rep(i, N - 1) {
        dpwith0.at(i + 1).at(0) = min(dpwith0.at(i).at(0) + A.at(i + 1), dpwith0.at(i).at(1) + A.at(i + 1));
        dpwith0.at(i + 1).at(1) = min(dpwith0.at(i + 1).at(1), dpwith0.at(i).at(0));
    }

    ll ans = min(dpwith0.at(N - 1).at(0), dpwith0.at(N - 1).at(1));

    vvll dpwithout0(N, vll(2, INF));
    dpwithout0.at(0).at(1) = 0;
    rep(i, N - 1) {
        dpwithout0.at(i + 1).at(0) = min(dpwithout0.at(i).at(0) + A.at(i + 1), dpwithout0.at(i).at(1) + A.at(i + 1));
        dpwithout0.at(i + 1).at(1) = min(dpwithout0.at(i + 1).at(1), dpwithout0.at(i).at(0));
    }

    ans = min(ans, dpwithout0.at(N - 1).at(0));

    cout << ans << endl;


    return 0;
}
