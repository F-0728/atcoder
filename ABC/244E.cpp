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
    ll N, M;
    cin >> N >> M;
    vll A(N + 1);
    rep(i, N + 1) cin >> A.at(i);
    reverse(A.begin(), A.end());
    vll C(N + M + 1);
    rep(i, N + M + 1) cin >> C.at(i);
    reverse(C.begin(), C.end());
    vll B(M + 1, 0);
    rep(i, M + 1) {
        ll quotient = 0;
        if (A.at(0) != 0) {
            quotient = C.at(i) / A.at(0);
        }
        B.at(i) = quotient;
        rep(j, N + 1) {
            C.at(i + j) -= A.at(j) * quotient;
        }
    }
    reverse(B.begin(), B.end());
    outv(B);

    return 0;
}
