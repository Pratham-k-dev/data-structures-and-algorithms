#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i;
    int r = 2*i + 1;
    if(l <= n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r <= n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void delmax(int arr[], int& size){
    if(size == 0){
        cout << "Heap is empty...\n";
        return;
    }
    swap(arr[1], arr[size]);
    size--;
    heapify(arr, size, 1);
}

int main(){
    int n;
    cout << "Enter the number of nodes to be created in heap: ";
    cin >> n;
    
    int arr[n+1]; 
    for(int i = 1; i <= n; i++){
        cout << "Enter the value for node " << i << ": ";
        cin >> arr[i];
    }
    for(int i = n/2; i >= 1; i--){
        heapify(arr, n, i);
    }
    cout << "Heapified array: ";
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int heapSize = n;
    for(int i = n; i >= 2; i--){
        delmax(arr, heapSize);
    }
    cout << "Sorted Heap : ";
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}