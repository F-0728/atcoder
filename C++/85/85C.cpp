#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() { 
    int x, y, z;
    x = -1;
    y = -1;
    z = -1;
    int N, Y;
    cin >> N >> Y;
    Y /= 1000;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N - i; j++) {
            int k = N - i - j;
            if (i + j + k == N && 10 * i + 5 * j + k == Y) {
                x = i;
                y = j;
                z = k;
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }
    cout << x << " " << y << " " << z << endl;
    return 0;
}
