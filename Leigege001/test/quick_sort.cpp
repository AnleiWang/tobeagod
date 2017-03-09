#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::swap;
class Vector {
private:
    int size, length;
    int * data;
    void quick_sort(int l, int r) {
        int pivot = data[l], i = l, j = r;
        do {
            while (i <= j && data[i] < pivot) {
                i++;
            }
            while (i <= j && data[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(data[i], data[j]);
                i++;
                j--;
            }
        } while (i <= j);
        if (l < j) {
            quick_sort(l, j);
        }
        if (i < r) {
            quick_sort(i, r);
        }
    }
public:
    Vector(int input_size) {
        size = input_size;
        length = 0;
        data = new int[size];
    }
    ~Vector() {
        delete[] data;
    }
    bool insert(int loc, int value) {
        if (loc < 0 || loc > length) {
            return false;
        }
        if (length >= size) {
            return false;
        }
        for (int i = length; i > loc; --i) {
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return true;
    }
    void print() {
        for (int i = 0; i < length; ++i) {
            if (i > 0) {
                cout << " ";
            }
            cout << data[i];
        }
        cout << endl;
    }
    void sort() {
        quick_sort(0, length - 1);
    }
};
int main() {
    int n;
    cin >> n;
    Vector arr(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.insert(i, x);
    }
    arr.sort();
    arr.print();
    return 0;
}

