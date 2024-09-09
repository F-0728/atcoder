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
    string S;
    cin >> S;
    string T;
    cin >> T;

    vector<string> X;
    ll N = S.size();

    while (S != T) {
        rep(i, N) {
            if (S[i] > T[i]) {
                S[i] = T[i];
                X.push_back(S);
                continue;
            }
        }
        for (ll i = N - 1; i >= 0; i--) {
            if (S[i] < T[i]) {
                S[i] = T[i];
                X.push_back(S);
                continue;
            }
        }
    }

    cout << X.size() << endl;
    for (auto x : X) {
        cout << x << endl;
    }

    return 0;
}
