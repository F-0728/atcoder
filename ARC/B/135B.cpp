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
    vll S(N);
    rep(i, N) cin >> S[i];

    vll A(N + 2);
    vll param(N + 2);
    param.at(0) = param.at(1) = 0;
    rep(i, N) {
        param.at(i + 2) = S.at(i) - param.at(i) - param.at(i + 1);
    }

    // outv(param);

    vll MIN(3, INF);
    rep(i, N + 2) {
        MIN.at(i % 3) = min(MIN.at(i % 3), param.at(i));
    }

    if (MIN.at(0) + MIN.at(1) < -MIN.at(2)) {
        No;
        return 0;
    }

    // outv(MIN);

    rep(i, N + 2) {
        if (i % 3 == 0) {
            A.at(i) = param.at(i) - MIN.at(0);
        } else if (i % 3 == 1) {
            A.at(i) = param.at(i) - MIN.at(1);
        } else {
            A.at(i) = param.at(i) + MIN.at(0) + MIN.at(1);
        }
    }

    Yes;
    outv(A);



    return 0;
}
