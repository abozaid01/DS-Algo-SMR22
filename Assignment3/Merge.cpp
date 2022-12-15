#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void mergeSort(vector<int> &arr) {
    
    if (arr.size()>1) {
        int mid = arr.size()/2;
        vector<int> lefthalf(arr.begin(), arr.begin()+mid);
        vector<int> righthalf(arr.begin()+mid,arr.begin()+arr.size());

        mergeSort(lefthalf);
        mergeSort(righthalf);

        int i = 0; int j = 0; int k = 0;
        while (i < lefthalf.size() && j < righthalf.size()) {
            if (lefthalf[i] < righthalf[j]) {
                arr[k]=lefthalf[i];
                i++;
            } else {
                arr[k] = righthalf[j];
                j++;
            }
            k++;
        }

        while (i<lefthalf.size()) {
            arr[k] = lefthalf[i];
            i++;
            k++;
        }

        while (j<righthalf.size()) {
            arr[k]=righthalf[j];
            j++;
            k++;
        }

    }
}


int main(){

    vector<int> vec {1,4,5,6,1,9,-19,28,3,4,3};
    mergeSort(vec);
    for(const auto &v:vec) cout << v << "  ";
    return 0;
}