#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printArray(const vector<int>& arr, int highlight = -1) {
    cout << "[ ";
    for (int i = 0; i < (int)arr.size(); i++) {
        if (i == highlight)
            cout << "*" << arr[i] << "* ";
        else
            cout << arr[i] << " ";
    }
    cout << "]";
}

int lomutoPartition(vector<int>& arr, int low, int high, int depth) {
    string indent(depth * 2, ' ');

    int pivot = arr[low];
    cout << indent << " Partitioning sub-array: ";
    for (int i = low; i <= high; i++) cout << arr[i] << " ";
    cout << "\n";
    cout << indent << "   Pivot = " << pivot
         << "  (index " << low << ")\n";

    swap(arr[low], arr[high]);
    cout << indent << "   Moved pivot to end: ";
    for (int i = low; i <= high; i++) cout << arr[i] << " ";
    cout << "\n";

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            if (i != j) {
                cout << indent << "   Swap arr[" << i << "]=" << arr[i]
                     << " and arr[" << j << "]=" << arr[j] << "\n";
                swap(arr[i], arr[j]);
                cout << indent << "   Array now: ";
                for (int k = low; k <= high; k++) cout << arr[k] << " ";
                cout << "\n";
            }
        }
    }

    int pivotPos = i + 1;
    swap(arr[pivotPos], arr[high]);
    cout << indent << "   Pivot " << pivot
         << " placed at final position index " << pivotPos << "\n";
    cout << indent << "   Sub-array after partition: ";
    for (int k = low; k <= high; k++) cout << arr[k] << " ";
    cout << "\n\n";

    return pivotPos;
}
void quickSort(vector<int>& arr, int low, int high, int depth = 0) {
    if (low < high) {
        int pi = lomutoPartition(arr, low, high, depth);
        quickSort(arr, low, pi - 1, depth + 1);
        quickSort(arr, pi + 1, high, depth + 1);
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "  A1 — Quick Sort \n";

    cout << "Initial array: ";
    printArray(arr);
    cout << "\n\n";

    quickSort(arr, 0, (int)arr.size() - 1);

    cout << "Sorted array:  ";
    printArray(arr);
    cout << "\n";

    return 0;
}
