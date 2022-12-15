#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void bubbleSort(std::vector<int>& arr){
    int temp =0;
    int size = arr.size();
    for(int i = 0; i < size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){

    vector<int> vec {1,4,5,6,1,9,-19,28,3,4,3};
    bubbleSort(vec);
    for(const auto &v:vec) cout << v << "  ";
    return 0;
}