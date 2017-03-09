#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[100];
    int b[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int i = 0, j = 0, temp = 0;
    while (i < n && j < n) {
        if (a[i] == b[j]) {
            if (temp == 1) {
                cout << " ";
            }
            cout << a[i];
            temp = 1;
            i++;
            j++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            i++;
        }
    }
    return 0;
}
