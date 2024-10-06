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
    ll N;
    cin >> N;
    string s;
    cin >> s;
    vector<char> stack;
    rep(i, N) {
        if (stack.size() < 2) {
            stack.push_back(s[i]);
        } else {
            if (stack[stack.size() - 2] == 'f' && stack[stack.size() - 1] == 'o' && s[i] == 'x') {
                stack.pop_back();
                stack.pop_back();
            } else {
                stack.push_back(s[i]);
            }
        }
    }

    cout << stack.size() << endl;

    return 0;
}
