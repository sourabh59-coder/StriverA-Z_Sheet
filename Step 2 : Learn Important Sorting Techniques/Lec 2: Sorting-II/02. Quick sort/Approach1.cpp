#include <bits/stdc++.h>
#define int long long 
using namespace std;

int partitioning(vector<int> &v, int low, int high) {
    int pivot = v[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && v[i] <= pivot) {
            i++;
        }
        while (j >= low && v[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(v[i], v[j]);
        }
    }

    swap(v[low], v[j]); // Corrected swap position
    return j;
}

void QuickSort(vector<int> &v, int low, int high) {
    if (low < high) {
        int ind = partitioning(v, low, high);

        QuickSort(v, low, ind - 1);
        QuickSort(v, ind + 1, high);
    }
}

signed main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    QuickSort(v, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
