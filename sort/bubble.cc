#include <iostream>

using namespace std;

/**
 * 简单排序
 **/
void bubbleSort1(int a[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 1; j < i; j++) {
            if (a[j - 1] > a[j]) {
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main() {
    int a[] = {5,2,3,4,1};
    bubbleSort1(a, 5);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }
    return 0;
}