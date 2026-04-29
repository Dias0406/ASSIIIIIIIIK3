#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int>& arr) {
    cout << "[ ";
    for (int x : arr) cout << x << " ";
    cout << "]";
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    const int TRACE_PASSES = 3;

    cout << "Initial array: ";
    printArray(arr);
    cout << "\n\n";

    for (int pass = 1; pass < n; pass++) {
        bool swapped = false;

        cout << " Pass " << pass << " \n";
        if (pass <= TRACE_PASSES)
            cout << "  Start: "; printArray(arr); cout << "\n";

        for (int j = 0; j < n - pass; j++) {
            if (arr[j] > arr[j + 1]) {
                if (pass <= TRACE_PASSES)
                    cout << "  Swap arr[" << j << "]=" << arr[j]
                         << " and arr[" << j+1 << "]=" << arr[j+1] << "\n";

                swap(arr[j], arr[j + 1]);
                swapped = true;

                if (pass <= TRACE_PASSES) {
                    cout << "  After swap: ";
                    printArray(arr);
                    cout << "\n";
                }
            }
        }

        cout << "  State after pass " << pass << ": ";
        printArray(arr);
        cout << "\n";

        if (!swapped) {
            cout << "\n  [Early Exit] No swaps occurred in pass " << pass
                 << ".\n"
                 << "  The array is already sorted — stopping early.\n"
                 << "  Without Early Exit we would run " << (n - 1)
                 << " passes total; we stopped at pass " << pass << ".\n\n";
            break;
        }

        cout << "  (swapped = true → continue to next pass)\n\n";
    }
}


int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "  A2 — Bubble Sort with Early Exit\n\n";

    cout << " Early Exit Concept \n"
         << "A boolean flag 'swapped' is reset to false at the start of\n"
         << "each pass. If no two adjacent elements are swapped during a\n"
         << "pass, the array is already sorted and we break out early,\n"
         << "saving unnecessary iterations.\n\n";

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
