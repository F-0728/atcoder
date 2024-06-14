#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll N;
    cin >> N;
    vector<string> S(N), T(N);
    rep(i, N) {
        cin >> S.at(i);
    }
    rep(i, N) {
        cin >> T.at(i);
    }

    vpll s1, s2, s3, s4, t;
    rep(i, N) {
        rep(j, N) {
             if (S.at(i).at(j) == '#') {
                s1.push_back({i, j});
            }
            if (S.at(N - 1 - i).at(N - 1 - j) == '#') {
                s3.push_back({i, j});  
            }
            if (S.at(N - 1 - j).at(i) == '#') {
                s4.push_back({i, j});
            }
            if (S.at(j).at(N - 1 - i) == '#') {
                s2.push_back({i, j});
            }
            if (T.at(i).at(j) == '#') {
                t.push_back({i, j});
            }
        }
    }

    if (s1.size() != t.size()) {
        No;
        return 0;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    sort(s3.begin(), s3.end());
    sort(s4.begin(), s4.end());
    sort(t.begin(), t.end());

    rep(i, s1.size()) {
        if (i == 0) continue;
        s1.at(i).first -= s1.at(0).first;
        s1.at(i).second -= s1.at(0).second;
        t.at(i).first -= t.at(0).first;
        t.at(i).second -= t.at(0).second;
        s2.at(i).first -= s2.at(0).first;
        s2.at(i).second -= s2.at(0).second;
        s3.at(i).first -= s3.at(0).first;
        s3.at(i).second -= s3.at(0).second;
        s4.at(i).first -= s4.at(0).first;
        s4.at(i).second -= s4.at(0).second;
    }
    s1.at(0) = {0, 0};
    s2.at(0) = {0, 0};
    s3.at(0) = {0, 0};
    s4.at(0) = {0, 0};
    t.at(0) = {0, 0};

    if (s1 == t || s2 == t || s3 == t || s4 == t) {
        Yes;
    } else {
        No;
    }

    

    return 0;
}
