#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long factorial (unsigned long long n){
	if (n==1 || n==0)
		return 1;                   //base case
	return n*factorial(n-1);     //recursive case
}

int main(){


	
	string s1 = "Stack";
	cout<<s1.size()<<endl;
	cout << s1[4] << endl;
	cout<<s1[5] << endl;
	for(int i=s1.size()-1; i>=0; i--){
		cout << s1[i] << " ";
	}

	


	// std::cout << factorial(0) << std::endl;  //1
	// std::cout << factorial(1) << std::endl;  //1
	// std::cout << factorial(2) << std::endl;  //2
	// std::cout << factorial(3) << std::endl;  //6
	// std::cout << factorial(4) << std::endl;  //24
	// std::cout << factorial(5) << std::endl;  //120
	// std::cout << factorial(6) << std::endl;  //720
	// std::cout << factorial(7) << std::endl;  //5040
	// std::cout << factorial(8) << std::endl;  //40320
	return 0;
}