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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vll streak;
    ll cnt = 1;
    rep(i, N - 1) {
        if (S[i] == S[i + 1]) {
            cnt++;
        } else {
            streak.push_back(cnt);
            cnt = 1;
        }
    }
    streak.push_back(cnt);
    if (K >= streak.size() / 2) {
        cout << N - 1 << endl;
        return 0;
    }

    ll happy = 0;
    rep(i, streak.size()) {
        happy += streak[i] - 1;
    }
    cout << happy + 2 * K << endl;

    return 0;
}
