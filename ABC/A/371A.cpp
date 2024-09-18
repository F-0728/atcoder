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
    char ab, ac, bc;
    cin >> ab >> ac >> bc;

    if (ab == '<') {
        if (ac == '<') {
            if (bc == '<') {
                cout << "B" << endl;
            } else {
                cout << "C" << endl;
            }
        } else {
            cout << "A" << endl;
        }
    } else {
        if (ac == '<') {
            cout << "A" << endl;
        } else {
            if (bc == '<') {
                cout << "C" << endl;
            } else {
                cout << "B" << endl;
            }
        }
    }


    return 0;
}