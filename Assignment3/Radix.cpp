#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int getMax(std::vector<int> vec){
    int max = vec.at(0);
    for (int i = 1; i < vec.size(); i++)
        max = ((vec.at(i) > max)? max = vec.at(i) : max);
    return max;
}

void radixSort(std::vector<int>& arr){
    int max = getMax(arr);
    int radix = 1;
    while(max / radix)
    {
        // groups used for sorting. Each group representing a digit.
        std::vector<std::vector<int>> groups(10, std::vector<int>());
        for(const auto &num : arr){
            int digit = num / radix % 10;
            groups[digit].push_back(num);
        }
        int k = 0;
        // Take the elements out of groups into the array
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < groups[i].size(); j++)
            {
                arr[k] = groups[i][j];
                k++;
            }
        }
        radix *= 10;
    }
}

int main(){

    vector<int> vec {1,4,5,6,1,9,19,28,3,4,3}; 
    radixSort(vec); // won't work with negative numbers
    for(const auto &v:vec) cout << v << "  ";
    return 0;
}