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

    vpll stack;
    stack.push_back({-INF, -1});
    vll ans(N);
    rep(i, N) {
        while (stack.back().first < A.at(i)) {
            stack.pop_back();
            if (stack.empty()) {
                break;
            }
        }
        if (stack.empty()) {
            ans.at(i) = -1;
        } else { 
            ans.at(i) = stack.back().second;
        }
        stack.push_back({A.at(i), i + 1});
    }
    rep(i, N) {
        cout << ans.at(i) << " ";
    }
    cout << endl;

    return 0;
}
