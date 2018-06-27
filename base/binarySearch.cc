#include <iostream>
using namespace std;

/**
 * @brief 自己写的简化版本
 * 
 * @param arr 
 * @param length 
 * @param search 
 * @return int 
 */
int binarySearch(int arr[], int length, int search) {
    int left, right, mid;
    left = 0;
    right = length - 1;
    while (left < right) {
        int mid = (right + left) / 2;
        if (arr[mid] == search) {
            return mid;
        } else if (arr[mid] > search) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

/**
 * @brief 递归版本
 * 
 * @param array 
 * @param low 
 * @param height 
 * @param target 
 * @return int 
 */
int recursion(int array[], int low, int height, int target) {
    if (low > height) {
        return -1;
    }
    int mid = (low + height) / 2;
    if (array[mid] > target) {
        return recursion(array, low, mid - 1, target);
    }
    if (array[mid] < target) {
        return recursion(array, mid + 1, height, target);
    }

    return mid;
}

int main() {
    int a[] = {1,2};
    // int a[] = {1,2,3,4,5,6};
    cout << binarySearch(a, 2, 1) << endl;
}