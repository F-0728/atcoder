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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    rep(i, N) {
        if (S[i] == "-----") {
            cout << "0";
        } else if (S[i] == ".----") {
            cout << "1";
        } else if (S[i] == "..---") {
            cout << "2";
        } else if (S[i] == "...--") {
            cout << "3";
        } else if (S[i] == "....-") {
            cout << "4";
        } else if (S[i] == ".....") {
            cout << "5";
        } else if (S[i] == "-....") {
            cout << "6";
        } else if (S[i] == "--...") {
            cout << "7";
        } else if (S[i] == "---..") {
            cout << "8";
        } else if (S[i] == "----.") {
            cout << "9";
        }
    }
    cout << endl;

    return 0;
}
