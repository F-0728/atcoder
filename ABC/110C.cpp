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
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    string S, T;
    cin >> S >> T;
    map<char, char> charsS;
    map<char, char> charsT;

    rep(i, S.size()) {
        if (charsS.count(S[i]) > 0) {
            if (charsS[S[i]] != T[i]) {
                No;
                return 0;
            }
        }
        if (charsT.count(T[i]) > 0) {
            if (charsT[T[i]] != S[i]) {
                No;
                return 0;
            }
        }
        else {
            charsS[S[i]] = T[i];
            charsT[T[i]] = S[i];
        }
    }
    Yes;
    

    return 0;
}
