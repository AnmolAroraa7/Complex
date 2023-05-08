#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void bucketSort(double arr[], int n){

    vector<vector<double> > buckets(n);

    for (int i = 0; i < n; i++){
        buckets[floor(n*arr[i])].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++){
        sort(buckets[i].begin(),buckets[i].end());
    }

    int idx = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < buckets[i].size(); j++){
            arr[idx] = buckets[i][j];
            idx++;
        }
    }

}

int main(){

    double arr[] = {0.21, 0.46, 0.71, 0.18, 0.32, 0.79, 0.25};
    int size = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr,size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
