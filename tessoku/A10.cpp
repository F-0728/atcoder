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
    rep(i, N) cin >> A.at(i);
    vll leftMax(N), rightMax(N);
    leftMax.at(0) = A.at(0);
    rightMax.at(N-1) = A.at(N-1);
    for (ll i = 1; i < N; i++) {
        leftMax.at(i) = max(leftMax.at(i - 1), A.at(i));
    }
    for (ll i = N - 2; i >= 0; i--) {
        rightMax.at(i) = max(rightMax.at(i + 1), A.at(i));
    }
    ll D;
    cin >> D;
    rep(i, D) {
        ll L, R;
        cin >> L >> R;
        L -= 2;
        cout << max(leftMax.at(L), rightMax.at(R)) << endl;
    }

    return 0;
}
