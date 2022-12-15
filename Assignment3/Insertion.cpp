#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void insertionSort(std::vector<int>& arr){
    int size = arr.size();
    int temp {0};
    int index {0};
    for(int i=1; i<size; i++){
        if(arr[i] < arr[i-1]){
            temp = arr[i];
            index = i;
            do
            {
                arr[index] = arr[index-1];
                index--;
            } while (index>0 && arr[index-1] > temp);
            arr[index] = temp;
        }
    }
}

int main(){

    vector<int> vec {1,4,5,6,1,9,-19,28,3,4,3};
    insertionSort(vec);
    for(const auto &v:vec) cout << v << "  ";
    return 0;
}