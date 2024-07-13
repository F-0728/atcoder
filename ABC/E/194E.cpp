#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll N, M;
    cin >> N >> M;
    vvll index(N);
    rep(i, N) {
        ll A;
        cin >> A;
        index.at(A).push_back(i);
    }
    rep(i, N) {
        if (index.at(i).size() == 0) {
            cout << i << endl;
            return 0;
        }
        if (index.at(i).size() == 1) {
            if (index.at(i).at(0) - M >= 0) {
                cout << i << endl;
                return 0;
            }
            if (index.at(i).at(0) + M < N) {
                cout << i << endl;
                return 0;
            }
        }
        for (ll j = 1; j < index.at(i).size(); j++) {
            if (index.at(i).at(j) - index.at(i).at(j - 1) > M) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << N << endl;
    return 0;
}
