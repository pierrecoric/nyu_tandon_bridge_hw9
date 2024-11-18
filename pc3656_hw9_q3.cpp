//pc3656
//2024/11/13
//GetPosNum 1 to 4.

#include <iostream>
#include <random>
#include <ctime>
using namespace std;

//Functions prototypes
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void populateArray(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void printArrayFromPointer(int* arrPtr, int arrSize);
int countPositives(int arr[], int arrSize);
void separator();

int main () {
    //Seed the random number generator.
    srand(time(0));
    //Inilialize the size of the array and the size of the output array.
    int testSize(20), outSize(0);
    //Create a pointer and make it point to the variable outSize.
    int* outSizePtr;
    outSizePtr = &outSize;
    //Define a test array.
    int testArray [testSize];
    //Define a pointer to the output array.
    int* outArrayPtr;
    outArrayPtr = NULL;
    
    //1st function.
    //Populate the array.
    populateArray(testArray, testSize);
    cout << "Function #1" << endl
         << "-----------" << endl;
    cout << "Given the following array: " << endl;
    printArray(testArray, testSize);
    cout << "Function #1 results in: " << endl;
    outArrayPtr = getPosNums1(testArray, testSize, outSize);
    printArrayFromPointer(outArrayPtr, outSize);
    //Freeing the memory
    delete [] outArrayPtr;
    outArrayPtr = NULL;

    separator();

    //2nd function.
    //Populate the array and reset outSize.
    populateArray(testArray, testSize);
    outSize = 0;
    cout << "Function #2" << endl
         << "-----------" << endl;
    cout << "Given the following array: " << endl;
    printArray(testArray, testSize);
    cout << "Function #2 results in: " << endl;
    outArrayPtr = getPosNums2(testArray, testSize, outSizePtr);
    //Printing by using the pointer to the outSize variable to make sure that the function updated it correclty.
    printArrayFromPointer(outArrayPtr, *outSizePtr);
    //Freeing the memory
    delete [] outArrayPtr;
    outArrayPtr = NULL;

    separator();

    //3rd function.
    //Populate the array and reset outSize.
    populateArray(testArray, testSize);
    outSize = 0;
    cout << "Function #3" << endl
         << "-----------" << endl;
    cout << "Given the following array: " << endl;
    printArray(testArray, testSize);
    cout << "Function #3 results in: " << endl;
    getPosNums3(testArray, testSize, outArrayPtr, outSize);
    printArrayFromPointer(outArrayPtr, outSize);
    //Freeing the memory
    delete [] outArrayPtr;
    outArrayPtr = NULL;

    separator();

    //4th function.
    //Populate the array and reset outSize.
    populateArray(testArray, testSize);
    outSize = 0;
    cout << "Function #4" << endl
         << "-----------" << endl;
    cout << "Given the following array: " << endl;
    printArray(testArray, testSize);
    cout << "Function #4 results in: " << endl;
    getPosNums4(testArray, testSize, &outArrayPtr, outSizePtr);
    //Printing by using the pointer to the outSize variable to make sure the that function updated it correclty.
    printArrayFromPointer(outArrayPtr, *outSizePtr);
    //Freeing the memory
    delete [] outArrayPtr;
    outArrayPtr = NULL;
    
    //Exit the program.
    return 0;
}

//The four functions bellow.
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    outPosArrSize = countPositives(arr, arrSize);
    int* out;
    //Creating a dynamic array for the positive numbers only.
    out = new int[outPosArrSize];
    //Initializing the count of positive numbers to 0.
    int count = 0;
    for(int i = 0; i < arrSize; i ++) {
        if(arr[i] > 0) {
            out[count] = arr[i];
            count ++;
        }
    }
    return out;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    *outPosArrSizePtr = countPositives(arr, arrSize);
    int* out;
    //Creating a dynamic array for the positive numbers only.
    out = new int[*outPosArrSizePtr];
    //Initializing the count of positive numbers to 0.
    int count = 0;
    for(int i = 0; i < arrSize; i ++) {
        if(arr[i] > 0) {
            out[count] = arr[i];
            count ++;
        }
    }
    return out;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    outPosArrSize = countPositives(arr, arrSize);
    //Creating a dynamic array for the positive numbers only.
    outPosArr = new int[outPosArrSize];
    int count = 0;
    for(int i = 0; i < arrSize; i ++) {
        if(arr[i] > 0) {
            outPosArr[count] = arr[i];
            count ++;
        }
    }
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    *outPosArrSizePtr = countPositives(arr, arrSize);
    //Creating a dynamic array for the positive numbers only.
    *outPosArrPtr = new int[*outPosArrSizePtr];
    int count = 0;
    for(int i = 0; i < arrSize; i ++) {
        if(arr[i] > 0) {
            (*outPosArrPtr)[count] = arr[i];
            count ++;
        }
    }
}

//Helpers functions bellow.
void printArray(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i ++) {
        if(i < arrSize - 1) {
            cout << arr[i] << ", ";
        } else cout << arr[i];
    }
    cout << endl;
}

void printArrayFromPointer(int* arrPtr, int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        if(i < arrSize - 1) {
            cout << *(arrPtr + i) << ", ";
        } else cout << *(arrPtr + i);
    }
    cout << endl;
}

void populateArray(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i ++) {
        if (rand() % 2 == 0) {
            arr[i] = -(rand() % 10) + 1;
        } else arr[i] = (rand() % 10) + 1;
    }
}

void separator() {
    cout << endl;
    for(int i = 0; i < 30; i ++) {
        cout << ".";
    }
    cout << endl << endl; 
}

int countPositives(int arr[], int arrSize) {
    int count(0);
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            count ++;
        }
    }
    return count;
}