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
    ll H, W;
    cin >> H >> W;
    ll Si, Sj;
    cin >> Si >> Sj;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];
    Si--; Sj--;
    string X;
    cin >> X;

    rep(i, X.size()) {
        char move = X[i];
        if (move == 'U' && Si > 0 && grid[Si - 1][Sj] == '.') {
            Si--;
        } else if (move == 'D' && Si < H - 1 && grid[Si + 1][Sj] == '.') {
            Si++;
        } else if (move == 'L' && Sj > 0 && grid[Si][Sj - 1] == '.') {
            Sj--;
        } else if (move == 'R' && Sj < W - 1 && grid[Si][Sj + 1] == '.') {
            Sj++;
        }
    }
    cout << Si + 1 << " " << Sj + 1 << endl;

    return 0;
}
