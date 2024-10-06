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
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, X;
    cin >> N >> X;
    string S;
    cin >> S;

    vector<char> move;
    rep(i, N) {
        if (S[i] == 'U') {
            if (move.empty()) {
                move.push_back(S[i]);
            } else if (move.back() != 'U') {
                move.pop_back();
            } else {
                move.push_back(S[i]);
            }
        } else {
            move.push_back(S[i]);
        }
    }

    rep(i, move.size()) {
        if (move[i] == 'U') {
            X /= 2;
        } else if (move[i] == 'L') {
            X *= 2;
        } else {
            X = 2 * X + 1;
        }
    }

    cout << X << endl;

    return 0;
}
