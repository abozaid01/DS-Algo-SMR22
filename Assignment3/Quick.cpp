#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void swap(int &x, int &y) {
   int temp;
   temp = x; 
   x = y; 
   y = temp;
  
   return;
}

int Partition(vector<int> &v, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}

void quickSort_recursive(vector<int> &v, int start, int end ){

    if(start<end){
		int p = Partition(v,start,end);
		quickSort_recursive(v,start,p-1);
		quickSort_recursive(v,p+1,end);
	}

}
void quickSort(vector<int> &arr){

	int start = 0;
    int end = arr.size()-1;
    quickSort_recursive(arr,start,end);
	
}

int main(){

    vector<int> vec {1,4,5,6,1,9,-19,28,3,4,3};
    quickSort(vec);
    for(const auto &v:vec) cout << v << "  ";
    return 0;
}