#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printSub(const vector<int>& arr, int l, int r) {
    cout << "[ ";
    for (int i = l; i <= r; i++) cout << arr[i] << " ";
    cout << "]";
}

void merge(vector<int>& arr, int left, int mid, int right, int depth) {
    string indent(depth * 2, ' ');

    vector<int> L(arr.begin() + left,  arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    cout << indent << "MERGE: ";
    printSub(arr, left, mid);
    cout << " + ";
    printSub(arr, mid + 1, right);
    cout << "\n";
    cout << indent << "  Left  L: [ ";
    for (int x : L) cout << x << " ";
    cout << "]\n";
    cout << indent << "  Right R: [ ";
    for (int x : R) cout << x << " ";
    cout << "]\n";

    int i = 0, j = 0, k = left;

    cout << indent << "  Pointer trace (i=L-ptr, j=R-ptr):\n";
    while (i < (int)L.size() && j < (int)R.size()) {
        cout << indent << "    i=" << i << " L[i]=" << L[i]
             << "  j=" << j << " R[j]=" << R[j] << "  to ";
        if (L[i] <= R[j]) {
            cout << "pick L[i]=" << L[i] << " to arr[" << k << "]\n";
            arr[k++] = L[i++];
        } else {
            cout << "pick R[j]=" << R[j] << " to arr[" << k << "]\n";
            arr[k++] = R[j++];
        }
    }
    while (i < (int)L.size()) {
        cout << indent << "    Remaining L[i]=" << L[i]
             << " to arr[" << k << "]\n";
        arr[k++] = L[i++];
    }
    while (j < (int)R.size()) {
        cout << indent << "    Remaining R[j]=" << R[j]
             << " to arr[" << k << "]\n";
        arr[k++] = R[j++];
    }

    cout << indent << "  Merged result: ";
    printSub(arr, left, right);
    cout << "\n\n";
}

void mergeSort(vector<int>& arr, int left, int right, int depth = 0) {
    if (left >= right) return;

    string indent(depth * 2, ' ');
    int mid = left + (right - left) / 2;

    cout << indent << "DIVIDE ";
    printSub(arr, left, right);
    cout << " to ";
    printSub(arr, left, mid);
    cout << " | ";
    printSub(arr, mid + 1, right);
    cout << "\n";

    mergeSort(arr, left,    mid,   depth + 1);
    mergeSort(arr, mid + 1, right, depth + 1);
    merge(arr, left, mid, right, depth);
}

void printRecursionTree(const vector<int>& arr, int left, int right, int depth) {
    if (left > right) return;
    string indent(depth * 4, ' ');
    cout << indent;
    printSub(arr, left, right);
    cout << "\n";

    if (left == right) return;

    int mid = left + (right - left) / 2;
    printRecursionTree(arr, left,    mid,   depth + 1);
    printRecursionTree(arr, mid + 1, right, depth + 1);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    
    cout << "  A3 — Merge Sort \n\n";

    cout << "Initial array: ";
    printSub(arr, 0, arr.size() - 1);
    cout << "\n\n";

    cout << " Recursion / Divide Tree \n";
    printRecursionTree(arr, 0, arr.size() - 1, 0);
    cout << "\n";

    cout << " Divide + Merge Execution \n\n";
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printSub(arr, 0, arr.size() - 1);
    cout << "\n";

    return 0;
}
