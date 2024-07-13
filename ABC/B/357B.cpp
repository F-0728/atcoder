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
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    string S;
    cin >> S;
    ll N = S.size();
    ll lowerCount = 0;
    ll upperCount = 0;
    rep(i, N) {
        if (islower(S[i])) {
            lowerCount++;
        } else {
            upperCount++;
        }
    }
    if (upperCount > lowerCount) {
        rep(i, N) {
            S[i] = toupper(S[i]);
        }
    } else {
        rep(i, N) {
            S[i] = tolower(S[i]);
        }
    }
    cout << S << endl;

    return 0;
}
