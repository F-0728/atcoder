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
    ll K;
    cin >> K;
    string S, T;
    cin >> S >> T;
    vll cardsS(10, 0);
    vll cardsT(10, 0);
    rep(i, 4) {
        cardsS.at(S[i] - '0')++;
        cardsT.at(T[i] - '0')++;
    }
    ll scoreS = 0;
    ll scoreT = 0;
    rep(i, 10) {
        scoreS += i * pow(10, cardsS.at(i));
        scoreT += i * pow(10, cardsT.at(i));
    }
    double probability = 0;
    rep(i, 10) {
        if (i == 0) continue;
        rep(j, 10) {
            if (j == 0) continue;
            ll iRemaining = K - cardsS.at(i) - cardsT.at(i);
            ll jRemaining = K - cardsS.at(j) - cardsT.at(j);
            if (iRemaining <= 0 || jRemaining <= 0) continue;
            ll scoreSNew = scoreS - i * pow(10, cardsS.at(i)) + i * pow(10, cardsS.at(i) + 1);
            ll scoreTNew = scoreT - j * pow(10, cardsT.at(j)) + j * pow(10, cardsT.at(j) + 1);
            if (scoreSNew > scoreTNew) {
                if (i == j) {
                    probability += (double)iRemaining / (9 * K - 8) * (jRemaining - 1) / (9 * K - 9);
                } else {
                    probability += (double)iRemaining / (9 * K - 8) * jRemaining / (9 * K - 9);
                }
            }
        }
    }
    cout << fixed << setprecision(10) << probability << endl;
    
    return 0;
}
