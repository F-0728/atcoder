#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <chrono>
#include <bitset>
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
#define vbool vector<bool>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvbool vector<vector<bool>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
ll power(ll x, ll y) {ll res = 1; while(y > 0){if (y % 2 == 1) {res *= x;} x *= x; y >>= 1;}return res;}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
void outvmint(const vector<mint>& v){for(const auto& e : v){ cout << e.val() << " "; } cout << endl;}
template<typename T> void outvv(const vector<vector<T>>& vv){for(const auto& v : vv){ outv(v); }}
void outvvmint(const vector<vector<mint>>& vv){for(const auto& v : vv){ outvmint(v); }}
template<typename T> void outvp(const vector<pair<T, T>>& vp){for(const auto& p : vp){ cout << p.first << " " << p.second << endl; }}

// gx, gyは開区間で取る

template< class T >
struct CumulativeSum2D {
  vector< vector< T > > data;

  CumulativeSum2D(int W, int H) : data(W + 1, vector< T >(H + 1, 0)) {}

  void add(int x, int y, T z) {
    ++x, ++y;
    if(x >= data.size() || y >= data[0].size()) return;
    data[x][y] += z;
  }

  void build() {
    for(int i = 1; i < data.size(); i++) {
      for(int j = 1; j < data[i].size(); j++) {
        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  T query(int sx, int sy, int gx, int gy) {
    return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
  }

  // 1-indexed
  vector<vector<T>> get() {
      vector<vector<T>> res(data.size(), vector<T>(data[0].size()));
      rep(i, data.size()) {
          rep(j, data[i].size()) {
              res[i][j] = data[i][j];
          }
      }
      return res;
  }

};

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<string> P(N);
    rep(i, N) {
        cin >> P[i];
    }
    vvll cSum(N + 1, vll(N + 1, 0));
    rep(i, N) {
        rep(j, N) {
            if (P[i][j] == 'B') {
                cSum[i + 1][j + 1]++;
            }
        }
    }

    CumulativeSum2D<ll> cs(N, N);
    rep(i, N) {
        rep(j, N) {
            cs.add(i, j, cSum[i + 1][j + 1]);
        }
    }
    cs.build();

    auto count = [&](ll i, ll j) {
        ll res = 0;
        ll grid = (i / N) * (j / N);
        res += grid * cs.query(0, 0, N, N);
        res += (i / N) * cs.query(0, 0, N, j % N);
        res += (j / N) * cs.query(0, 0, i % N, N);
        i %= N;
        j %= N;
        res += cs.query(0, 0, i, j);
        return res;
    };

    rep(i, Q) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        C++; D++;
        ll ans = count(C, D) - count(A, D) - count(C, B) + count(A, B);

        cout << ans << endl;
    }

    return 0;
}
