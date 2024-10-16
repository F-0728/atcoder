#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
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

vector<vector<mint>> matrix_mul(vector<vector<mint>> A,
                                vector<vector<mint>> B) {
    ll N = A.size();
    ll M = B.size();
    ll L = B.at(0).size();
    vector<vector<mint>> res(N, vector<mint>(L, 0));
    rep(i, N) {
        rep(j, L) {
            rep(k, M) { res.at(i).at(j) += A.at(i).at(k) * B.at(k).at(j); }
        }
    }
    return res;
}

vector<vector<mint>> matrix_pow(vector<vector<mint>> A, ll n) {
    ll N = A.size();
    vector<vector<mint>> res(N, vector<mint>(N, 0));
    rep(i, N) { res.at(i).at(i) = 1; }
    while (n > 0) {
        if (n & 1) {
            res = matrix_mul(res, A);
        }
        A = matrix_mul(A, A);
        n >>= 1;
    }
    return res;
}

int main() {
    ll N, K;
    cin >> N >> K;

    vector<vector<mint>> A(N, vector<mint>(N));
    rep(i, N) {
        rep(j, N) {
            ll a;
            cin >> a;
            A[i][j] = a;
        }
    }

    vector<vector<mint>> B = matrix_pow(A, K);
    mint ans = 0;
    rep(i, N) {
        rep(j, N) {
            ans += B[i][j];
        }
    }

    cout << ans.val() << endl;


    return 0;
}
