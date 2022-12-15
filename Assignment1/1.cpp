/*Write a program to Generate 100 lowercase letters randomly and assign to an array CharArr of
100 characters. Count the occurrence of each letter in the array Counts of 26 integer. Pass the
Counts array to a function DisplayOccur to print each character with its occurrences.*/

#include <iostream>
#include <cstdlib>      // required for rand()
#include <ctime>       // required for time()
#include <cstring> 
#include <iomanip>       

using namespace std;

void DisplayOccur(short freq[]);

int main() {
    
    // a => 97
    // z => 122

    char random_char[100] {};
    short freq[26]{};
    short numOfLetters {100};         // number of random charchaters to generate
    short min {97};                  // lower bound (inclusive) 
    short max {122};                 // upper bound (inclusive)
    
    srand(time(nullptr));  

    for (size_t i{0}; i<numOfLetters; ++i)  {
        random_char[i] = rand() % (max-min + 1) + min;     // generate a random charchters [min, max]
        cout << random_char[i] << "  ";
    }
    cout << endl << endl;

    //sorting array elements ascending using Bubble sort method
    char temp{};
    int size =strlen(random_char);
    for (auto x:random_char)
        for (int j=0 ; j<size-1 ; j++)
            if(random_char[j]>random_char[j+1]){
                temp = random_char[j];
                random_char[j] = random_char[j+1];
                random_char[j+1] = temp;
            }

    for (size_t i{0}; i<numOfLetters; ++i)  {
        cout << random_char[i] << "  ";
    }
    cout << endl << endl;

    //initializing the freq array as freq[char] = count  for each character
    short alpha = 'a'; // alpha = 97;
    short count{0};
    short index =0;

    for(int i=0; i<size;i++){
        if(random_char[i] == alpha)
            count++;
        else{
            index ++;
            alpha++;
            count = ((random_char[i] != alpha)? 0 : 1);
            if(!count){
                alpha ++;
                freq[index++] = count;
                if(random_char[i] == alpha){
                    freq[index] = ++count;
                    continue;
                }
                else{
                    alpha ++;
                    freq[index++] = count++;
                    continue;
                }
            }
        }
        freq[index] = count;
    }
    //the freq already intialized by zeros
    // if(random_char[size-1] == alpha && alpha !='z')
    //         for(int i=alpha+1 ; i<='z'; ++i)
    //         freq[++index] = 0;


    for (size_t i{0}; i<=index; ++i)  {
        cout << freq[i] << "  ";
    }

    cout  << endl << endl;
    DisplayOccur(freq);
    cout  << endl;
    return 0;
}

void DisplayOccur(short freq[]){
    char a = 97; //char a = 'a';
    cout <<"\tCharacter\tFrequency\n------------------------------------------\n";
    for(int i=0 ;i<26;++i)
            cout<< setw(12) << a++ << setw(15) << freq[i] << endl;
        

}
