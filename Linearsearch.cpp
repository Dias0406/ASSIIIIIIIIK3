#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int>& arr) {
    cout << "[ ";
    for (int x : arr) cout << x << " ";
    cout << "]";
}

int linearSearch(const vector<int>& arr, int target) {
    int comparisons = 0;
    cout << "\nSearching for T1 = " << target << "\n\n";
    

    for (int i = 0; i < (int)arr.size(); i++) {
        comparisons++;
        cout << "Step " << comparisons << ": Compare arr[" << i << "] = "
             << arr[i] << " with " << target;

        if (arr[i] == target) {
            cout << "  -- MATCH FOUND!\n\n";
            cout << "Target " << target << " found at index " << i << "\n";
            cout << "Total comparisons made: " << comparisons << "\n";
            return i;
        } else {
            cout << "  -- No match\n\n";
        }
    }
    cout << "Target " << target << " NOT found.\n";
    cout << "Total comparisons made: " << comparisons << "\n";
    return -1;
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int T1 = 43;

    cout << "  B1 — Linear Search\n";
    cout << "\nDataset: ";
    printArray(arr);
    cout << "\nSize n = " << arr.size() << "\n";
    cout << "Primary Target T1 = " << T1 << "\n";

    linearSearch(arr, T1);

    cout << "\n Time Complexity Analysis \n";
    cout << "Best  Case: O(1)    — target is the first element\n";
    cout << "Worst Case: O(n)    — target is last or not present\n";
    cout << "Avg   Case: O(n/2) = O(n)\n";
    cout << "  On average, we scan through half the array (n/2 elements)\n";
    cout << "  before finding the target, which simplifies to O(n).\n";
    cout << "  For this dataset (n=" << arr.size() << "), avg comparisons = "
         << arr.size() / 2.0 << "\n";

    return 0;
}
