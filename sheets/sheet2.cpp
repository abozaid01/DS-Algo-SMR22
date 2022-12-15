#include <iostream>
/*
1- Write a non-recursive function that computes the factorial of a positive integer.
*/

double fact(int x){
    int f =1;
    for(int i=1; i<=x; i++){
        f*=i;
    }
    return f;
}

/*---------------------------------------------------------------------------------------------*/

/*
2- Re-write using a recursive function.
*/

double factorial(int x){
    if(x==1 || x==0) return 1;
    return x * factorial(x-1);
}

/*---------------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------------*/

/*
3- Write a non-recursive function that computes and returns the sum of all integers from 1 to n.
*/

double sum(int n){
    int s = 0;
    for(int i=1; i<=n; i++){
        s+=i;
    }
    return s;
}

/*---------------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------------*/

/*
4- Re-write using a recursive function.
*/

double Sum(int n){
    if(n==0) return 0;
    return n + Sum(n-1);
}

/*---------------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------------*/

/*
5- Write a non-recursive function that raises a number x to a positive integer power p.
*/

double power(int x, unsigned int p){
    double result =1;
    for(int i=1; i<=p; i++){
        result *=x;
    }
    return result;
}

/*---------------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------------*/

/*
6- Re-write using a recursive function.
*/

double Power(int x, unsigned int p){
    if(p == 0)
        return 1;
    return x*Power(x,p-1);
}

/*---------------------------------------------------------------------------------------------*/


/*
7- The following sequence is called the Fibonacci sequence:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …
It is a sequence that starts with F0 = 0 and F1 = 1. 
Every number after that is the sum of the previous two numbers before it (i.e., FN = FN-1 + FN-2). 
Write a non-recursive function that computes FN.
*/

double fibonacci(int num){
    int *Array = new int[num];
    Array[0] = 0;
    Array[1] = 1;
    for(int i =2; i<=num; i++){
        Array[i] = Array[i-2] + Array[i-1];
    }
    return Array[num];
}

/*---------------------------------------------------------------------------------------------*/


/*
8- Re-write using a recursive function.
*/

double Fibonacci(int num){
    if(num==0)return 0;
    if(num==1)return 1;
    return Fibonacci(num-2) + Fibonacci(num-1);
}

/*---------------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------------*/


/*
9- Define a complex number class. It should include both a real and an imaginary component. 
The class should have an empty constructor initializing them to zeroes and a non-empty constructor 
that initializes them according to arguments. Additionally, it should have all the following methods:
    • void print(): Formatted print of the current complex number
    • double getReal(): Returns the real part of the current complex number
    • double getIm(): Returns the imaginary part of the current complex number
    • double magnitude(): Returns the magnitude of the current complex number.
    • complex conjugate(): Returns the complex conjugate of the current complex number.
    • complex add(Complex c): Returns the result of adding the current
    • complex number and the passed complex number c.
    • complex sub(Complex c): Returns the result of subtracting the
    • passed complex c from the current complex number c.
*/



/*---------------------------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------------------------*/


/*
10- Write a recursive function that returns the greatest common divisor of two numbers, using Euclidean algorithm.
*/

int GCD(int x, int y){
    int r = x%y;
    if(r==0)
        return y;
    return GCD(y,r);
}

/*---------------------------------------------------------------------------------------------*/

/*
10- Write a recursive function, vowels, that returns the number of vowels in a string.
*/

int vowels(char *str){
    int counter = 0;
    if(str[0]=='\0')
        return 0;
    if(str[0] == 'a' || str[0] == 'A' || str[0] == 'e' || str[0] == 'E' || str[0] == 'u' || str[0] == 'U' || str[0] == 'i' || str[0] == 'I' || str[0] == 'o' || str[0] == 'O')
        counter++;

    return counter + vowels(&str[1]);
}

/*---------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------*/

/*
11- Write and implement a recursive version of the array sequential search algorithm.
*/
int search(int arr[],int size,int i, int num){
    if(arr[i] == num) return i;
    if(i == size) return -1;
    return search(arr,size,i+1,num);
}

/*---------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------*/

/*
12- Write and implement a recursive version of sum of digits.
*/
int sumOfDigits(int num){
    if(num == 0) return 0;
    int sum = num%10;
    return sum + sumOfDigits(num/10);
}

/*---------------------------------------------------------------------------------------------*/


int main(){

    int x = 1211; //3+0+2+1 =6
    std::cout << sumOfDigits(x) << std::endl; 
    return 0;
}