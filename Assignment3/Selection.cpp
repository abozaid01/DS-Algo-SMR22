#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void selectionSort(std::vector<int>& arr){
    int size = arr.size();
    for(int i=0; i<size-1; i++){
        int min = arr[i];
        int min_index = i;
        for(int j=i+1; j<size; j++){
            if(min>arr[j]){
                min = arr[j];
                min_index = j;
            }

        }
        if(min_index !=i){
            arr[min_index] = arr[i];
            arr[i] = min;
        }

    }
}

int main(){

    vector<int> vec {1,4,5,6,1,9,-19,28,3,4,3};
    selectionSort(vec);
    for(const auto &v:vec) cout << v << "  ";
    return 0;
}