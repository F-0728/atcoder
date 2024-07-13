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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N;
    cin >> N;

    ll up = 1;
    ll down = N;
    ll left = 1;
    ll right = N;

    while (down - up > 1) {
        ll mid = (up + down) / 2;
        cout << "? " << up << " " << mid << " " << left << " " << right << endl;
        cout.flush();
        ll res;
        cin >> res;
        if (res == -1) return 0;
        if (res < mid - up + 1) {
            down = mid;
        } else {
            up = mid + 1;
        }
    }
    ll ansI = up;
    cout << "? " << up << " " << up << " " << 1 << " " << N << endl;
    cout.flush();
    ll res;
    cin >> res;
    if (res == -1) return 0;
    if (res == 1) {
        ansI = down;
    }
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        cout << "? " << 1 << " " << N << " " << left << " " << mid << endl;
        cout.flush();
        ll res;
        cin >> res;
        if (res == -1) return 0;
        if (res < mid - left + 1) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    ll ansJ = left;
    cout << "? " << 1 << " " << N << " " << left << " " << left << endl;
    cout.flush();
    cin >> res;
    if (res == -1) return 0;
    if (res == 1) {
        ansJ = right;
    }
    cout << "! " << ansI << " " << ansJ << endl;

    return 0;
}
