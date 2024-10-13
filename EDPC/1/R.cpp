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

vector<vector<mint>> mul(vector<vector<mint>> A, vector<vector<mint>> B) {
    ll N = A.size();
    ll M = B.size();
    ll L = B.at(0).size();
    vector<vector<mint>> res(N, vector<mint>(L, 0));
    rep(i, N) {
        rep(j, L) {
            rep(k, M) {
                res.at(i).at(j) += A.at(i).at(k) * B.at(k).at(j);
            }
        }
    }
    return res;
}

vector<vector<mint>> matrix_pow(vector<vector<mint>> A, ll n) {
    ll N = A.size();
    vector<vector<mint>> res(N, vector<mint>(N, 0));
    rep(i, N) {
        res.at(i).at(i) = 1;
    }
    while (n > 0) {
        if (n & 1) {
            res = mul(res, A);
        }
        A = mul(A, A);
        n >>= 1;
    }
    return res;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<vector<mint>> G(N, vector<mint>(N, 0));
    rep(i, N) {
        rep(j, N) {
            ll a;
            cin >> a;
            G.at(i).at(j) = (mint)a;
        }
    }
    vector<vector<mint>> res = matrix_pow(G, K);
    mint ans = 0;
    rep(i, N) {
        rep(j, N) {
            ans += res.at(i).at(j);
        }
    }
    cout << ans.val() << endl;
    

    return 0;
}
