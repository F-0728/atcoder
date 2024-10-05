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
    string S;
    cin >> S;
    ll N = S.size();

    vector<char> stack;
    vector<bool> ok(26, true);
    rep(i, N) {
        if (S[i] == '(') {
            stack.push_back(S[i]);
        } else if (S[i] == ')') {
            while (stack.back() != '(') {
                ok[stack.back() - 'a'] = true;
                stack.pop_back();
            }
            stack.pop_back();
        } else {
            if (!ok[S[i] - 'a']) {
                No;
                return 0;
            }
            ok[S[i] - 'a'] = false;
            stack.push_back(S[i]);
        }
    }

    Yes;


    return 0;
}
