//pc3656
//Anagram checker
//24/11/13

#include <iostream>
#include <vector>
using namespace std;

//Function prototypes.
bool isEqualLength(vector<int> vA, vector<int> vB);
bool isLetter(char c);
void populateVector(string str, vector<int>& vect);
bool isAnagram(vector<int>& vectA, vector<int>& vectB);
void merge(vector<int>& vect, int left, int right, int middle);
void mergeSort(vector<int>& vect, int left, int right);

int main() {
    string strA, strB;
    vector<int> lettersA, lettersB; 
    cout << "Anagram Checker" << endl
         << "---------------" << endl
         << "Enter the first string: ";
    getline(cin, strA);
    cout << "Enter the second string: ";
    getline(cin, strB);

    //Populate the vectors
    populateVector(strA, lettersA);
    populateVector(strB, lettersB);

    //Let the user know wheter the input is an anagram or not.
    if(isAnagram(lettersA, lettersB)) {
        cout << strA << " is an anagram of " << strB << endl;
    } else cout << strA << " and " << strB << " are not anagrams" << endl;
    
    //Exit the program.
    return 0;
}

//Function that returns true if two vectors have the same length.
bool isEqualLength(vector<int> vA, vector<int> vB) {
    if(vA.size() == vB.size()) {
        return true;
    }
    else return false;
}

//Function that identifies if a given char is a letter.
bool isLetter(char c) {
    //Upper case letters.
    if(int(c) >= 65 && int(c) <= 90) {
        return true;
    }
    //Lower case lletters.
    if(int(c) >= 97 && int(c) <= 122) {
        return true;
    }
    else return false;
}

//Function that returns the ascii value of the lower case of a given letter.
int toLowerInt(char c) {
    if(int(c) >= 65 && int(c) <= 90) {
        return int(c) + 32;
    }
    else return int(c);
}

//Function that populates a vector with the lower cases letters from a string.
void populateVector(string str, vector<int>& vect) {
    for(int i = 0; i < str.length(); i ++) {
        if(isLetter(str[i])){
            vect.push_back(toLowerInt(str[i]));
        }
    }
}

//Merge function for the merge sort algorithm.
void merge(vector<int>& vect, int left, int middle, int right) {
    //Defining the size of the left and right vectors and delcaring two temporary vectors.
    int sizeL(middle - left + 1), sizeR(right - middle);
    vector<int> vectL(sizeL), vectR(sizeR);

    //Copy the data into the temporary vectors
    for(int i = 0; i < sizeL; i++) {
        vectL[i] = vect[left + i];
    }
    for(int i = 0; i < sizeR; i++) {
        vectR[i] = vect[middle + 1 + i];
    }

    //Declare variables to iterate over the vectors.
    int i(0), j(0), k(left);

    //merge the vectors
    while(i < sizeL && j < sizeR) {
        if(vectL[i] <= vectR[j]) {
            vect[k] = vectL[i];
            i++;
        }
        else {
            vect[k] = vectR[j];
            j++;
        }
        k++;
    }
    //Copy the potential remaining elements in vectL and in vectR
    while(i < sizeL) {
        vect[k] = vectL[i];
        i++;
        k++;
    }
    while(j < sizeR) {
        vect[k] = vectR[j];
        j++;
        k++;
    }
}

//Merge sort algorithm.
void mergeSort(vector<int>& vect, int left, int right) {
    //Base case.
    if (left >= right) {
        return;
    }
    //Find the middle of the vector.
    int middle = left + (right - left) / 2;
    //Sort the left side.
    mergeSort(vect, left, middle);
    //Sort the right side.
    mergeSort(vect, middle + 1, right);
    //Merge both sides.
    merge(vect, left, middle, right);
}

//Function that returns true if two vectors are anagrams.
bool isAnagram(vector<int>& vectA, vector<int>& vectB) {
    //Check if the vectors have the same length;
    if(isEqualLength(vectA, vectB)) {
        //Sort both vectors
        mergeSort(vectA, 0, (vectA.size() - 1));
        mergeSort(vectB, 0, (vectB.size() - 1));
        //Compare the vectors.
        if(vectA == vectB) {
            return true;
        } else return false;
    //If the vectors have different size at the begining of the function.
    } else return false;
}