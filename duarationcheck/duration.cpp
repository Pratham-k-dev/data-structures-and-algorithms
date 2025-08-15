#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Pivot is last element
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
using namespace std::chrono;
int main (){
      auto start = high_resolution_clock::now();

    // 🔁 Code you want to measure

    vector<int> vec={{42, 7, 13, 89, 21, 5, 66, 30, 18, 3, 54, 77, 1, 36, 25,37,80,9,23}};
    insertionSort(vec);
    for(int i: vec){
        cout<<i<<' ';
    }
    

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;
    return 0;
}