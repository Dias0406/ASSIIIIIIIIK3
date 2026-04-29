#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const int M = 7;
const int EMPTY = -1;

void printTable(const vector<int>& table) {
    cout << "\n  -----------------\n";
    cout << "  | Index | Value |\n";
    cout << "  -----------------\n";
    for (int i = 0; i < M; i++) {
        cout << "  |   " << i << "   |";
        if (table[i] == EMPTY)
            cout << "  ---  |\n";
        else
            cout << "  " << setw(3) << table[i] << "  |\n";
    }
    cout << "  -----------------\n\n";
}

void insert(vector<int>& table, int key) {
    int home    = key % M;
    int probe   = home;
    int attempt = 0;

    cout << "Insert key=" << key << "  h(" << key << ") = "
         << key << " mod 7 = " << home << "\n";

    while (attempt < M) {
        if (table[probe] == EMPTY) {
            if (attempt > 0)
                cout << "  Linear probe attempt " << attempt
                     << ": slot " << probe << " is free - placed here\n";
            else
                cout << "  Slot " << probe << " is free - placed here\n";
            table[probe] = key;
            cout << "  [OK] key=" << key << " stored at index " << probe << "\n\n";
            return;
        } else {
            cout << "  COLLISION at slot " << probe
                 << " (occupied by " << table[probe] << ")"
                 << "  - probe next slot\n";
            probe = (probe + 1) % M;
            attempt++;
        }
    }
    cout << "  [ERROR] Table is full! Cannot insert " << key << "\n\n";
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    vector<int> table(M, EMPTY);

    cout << "  B2 — Hashing (Modulo) with Linear Probing\n";
    cout << "\nDataset : [ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";
    cout << "Table size M = " << M << "\n";
    cout << "Hash function h(k) = k mod " << M << "\n";
    cout << "Collision resolution: Linear Probing  h(k,i) = (h(k) + i) mod M\n\n";

    cout << "Initial (empty) table:";
    printTable(table);

    cout << " Insertions \n\n";
    for (int key : arr)
        insert(table, key);

    cout << " Final Hash Table ";
    printTable(table);

    cout << " Load Factor \n";
    int filled = 0;
    for (int v : table) if (v != EMPTY) filled++;
    cout << "  Load factor λ = n/M = " << filled << "/" << M
         << " = " << fixed << setprecision(2)
         << (double)filled / M << "\n";
    cout << "  (λ < 0.7 is generally preferred for linear probing)\n";

    return 0;
}
