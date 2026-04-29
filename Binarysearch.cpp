#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(const vector<int>& arr, int low = -1, int high = -1, int mid = -1) {
    cout << "[ ";
    for (int i = 0; i < (int)arr.size(); i++) {
        if      (i == mid)  cout << "[M:" << arr[i] << "] ";
        else if (i == low)  cout << "[L:" << arr[i] << "] ";
        else if (i == high) cout << "[H:" << arr[i] << "] ";
        else if (i > low && i < high)
                            cout << arr[i] << " ";
        else                cout << "(" << arr[i] << ") ";
    }
    cout << "]\n";
}

int binarySearch(const vector<int>& arr, int target) {
    int low  = 0;
    int high = (int)arr.size() - 1;
    int step = 1;

    cout << "\nSearching for T2 = " << target << "\n";

    while (low <= high) {
        int mid = low + (high - low) / 2;

        cout << "Step " << step++ << ":\n";
        cout << "  Low=" << low << "  High=" << high
             << "  Mid=" << mid
             << "  arr[Mid]=" << arr[mid] << "\n";
        cout << "  Array view: ";
        printArray(arr, low, high, mid);

        if (arr[mid] == target) {
            cout << "  arr[Mid]=" << arr[mid] << " == " << target
                 << "  --> TARGET FOUND at index " << mid << "!\n";
            return mid;
        } else if (arr[mid] < target) {
            cout << "  arr[Mid]=" << arr[mid] << " < " << target
                 << "  --> Search RIGHT half  (Low = Mid+1 = " << mid+1 << ")\n\n";
            low = mid + 1;
        } else {
            cout << "  arr[Mid]=" << arr[mid] << " > " << target
                 << "  --> Search LEFT half   (High = Mid-1 = " << mid-1 << ")\n\n";
            high = mid - 1;
        }
    }

    cout << "  Low > High: search space exhausted.\n";
    cout << "  Target " << target << " NOT found.\n";
    cout << string(55, '-') << "\n";
    return -1;
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int T2 = 27;

    cout << "  B3 — Binary Search\n";

    cout << "\nOriginal dataset: [ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";

    sort(arr.begin(), arr.end());
    cout << "\nSorted dataset:   [ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";
    cout << "(Binary Search requires a sorted array)\n";

    cout << "\nSecondary Target T2 = " << T2 << "\n";

    int result = binarySearch(arr, T2);

    if (result != -1)
        cout << "\nResult: T2=" << T2 << " found at index " << result
             << " in the sorted array.\n";
    else
        cout << "\nResult: T2=" << T2 << " not found.\n";

    cout << "\n Time Complexity Analysis \n";
    cout << "Best  Case: O(1)       — target is exactly the mid element\n";
    cout << "Worst Case: O(log n)   — target is at a leaf or not present\n";
    cout << "Avg   Case: O(log n)\n";
    cout << "  Each step halves the search space.\n";
    cout << "  For n=" << arr.size() << ", max steps = ceil(log2(" << arr.size()
         << ")) = 3\n";
    cout << "  Compare: Linear O(n)=" << arr.size()
         << " steps vs Binary O(log n)=3 steps\n";

    return 0;
}
