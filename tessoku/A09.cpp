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

template< class T >
struct CumulativeSum2D {
  vector< vector< T > > data;

  CumulativeSum2D(int W, int H) : data(W + 1, vector< int >(H + 1, 0)) {}

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
    ll H, W, N;
    cin >> H >> W >> N;
    CumulativeSum2D<int> cs(H, W);
    rep(i, N) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        cs.add(a, b, 1);
        cs.add(a, d, -1);
        cs.add(c, b, -1);
        cs.add(c, d, 1);
    }
    cs.build();
    auto res = cs.get();
    rep(i, H) {
        rep(j, W) {
            cout << res[i + 1][j + 1] << " ";
        }
        cout << endl;
    }

    return 0;
}
