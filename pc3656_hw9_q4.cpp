//pc3656
//2024/11/13
//Odds are kept even are flipped.

#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void populateArray(int arr[], int arrSize);
int countOdds(int arr[], int arrSize);
bool isOdd(int n);
void printArray(int arr[], int arrSize);

int main() {
    //Seed the random number generator.
    srand(time(0));
    int testSize(10);
    int testArray [testSize];

    //Populate an array with 10 random numbers.
    populateArray(testArray, testSize);
    //Output the array before and after the function call.
    cout << "State of the array before calling the function \"oddsKeepEvensFlip\": " << endl;
    printArray(testArray, testSize);
    oddsKeepEvensFlip(testArray, testSize);
    cout << "State of the array after calling the function \"oddsKeepEvensFlip\": " << endl;
    printArray(testArray, testSize);

    //Exit the program.
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    //count the amount of odd and even numbers.
    int amountOdds = countOdds(arr, arrSize);
    int amountEvens = arrSize - amountOdds;
    //create two temporary dynamic arrays.
    int* oddArr;
    int* evenArr;
    oddArr = new int[amountOdds];
    evenArr = new int[amountEvens];
    //Initialize counting variables for the odd and even numbers.
    int countOdds(0), countEvens(0);
    //Iterate over the array and assign the odds and the evens to their respective temporary array.
    for(int i = 0; i < arrSize; i ++) {
        if(isOdd(arr[i])) {
            oddArr[countOdds] = arr[i];
            countOdds ++;
        }
        else {
            //Add the even numbers from the back of the array in order to flip their order.
            evenArr[amountEvens - countEvens - 1] = arr[i];
            countEvens ++;
        }
    }
    //Update the main array.
    for(int i = 0; i < amountOdds; i++) {
        arr[i] = oddArr[i];
    }
    for(int i = 0; i < amountEvens; i++) {
        arr[i + amountOdds] = evenArr[i];
    }
    //Free the memory.
    delete [] oddArr;
    delete [] evenArr;
    oddArr = NULL;
    evenArr = NULL;
}

void populateArray(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i ++) {
        arr[i] = (rand() % 10) + 1;
    }
}

int countOdds(int arr[], int arrSize){
    int count = 0;
    for (int i =0; i < arrSize; i ++) {
        if(isOdd(arr[i])) {
            count ++;
        }
    }
    return count;
    
}

bool isOdd(int n) {
    if(n % 2 == 0) {
        return false;
    }
    else return true;
}

void printArray(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i ++) {
        if(i < arrSize - 1) {
            cout << arr[i] << ", ";
        } else cout << arr[i];
    }
    cout << endl;
}