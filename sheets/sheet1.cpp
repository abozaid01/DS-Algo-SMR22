#include <iostream>
/*
1- Write a function that takes an array of positive numbers and its size, and then
returns the total number of duplicate elements.
*/
int count_duplicates(int arr[], int size) {
    int count = 0;
    bool repeated = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    repeated = true;
                   arr[j] = -1;
                 }
            }
            if (repeated) {
                count++;
                repeated = false;
            }
        }
    }
    return count;
}
/*---------------------------------------------------------------------------------------------*/

/*
2- Write a function that takes an array and its size, and then reverse the order of its
elements.
*/

void reverse_arr(int arr[], int size){
    int begin = 0;
    int end = size-1;
    while (end > begin) {
        int temp = arr[begin];
        arr[begin] = arr[end];
        arr[end] = temp;
        begin++;
        end--;
    }
}
////////////////////////////////////
void swap(int &x , int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void reverse_arr2(int arr[], int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        swap(arr[left++], arr[right--]);
    }
}
/*---------------------------------------------------------------------------------------------*/

/*
3- Write a function that merges two arrays of the same size and sorted in descending
order.
*/



/*---------------------------------------------------------------------------------------------*/

class Player{
    
public:
    int *data;
    Player(int d) {
        data = new int;
        *data = d;
    };
    Player(const Player& other):Player{*other.data}{
        std::cout << "dddddddddd\n";
    }
};
int main(){
    Player p {66};
    Player p2 {p};

}




