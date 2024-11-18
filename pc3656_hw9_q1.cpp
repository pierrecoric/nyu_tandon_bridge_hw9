//pc3656
//String analyzis
//2024/11/11

#include <iostream>
#include <string>

using namespace std;

//Prototypes.
int stringAnalyze(string str, int alphabet[]);
void initializeAlphabet(int alphabet[]);
bool isLetter(char c);
char toLower(char c);
int alphabetPositionLower(char c);
void printAlphabet(int alphabet[]);

const char TAB = '\t';

int main () {
    //Initializing an array to keep track of the occurence of each letter.
    int alphabet[26];
    initializeAlphabet(alphabet);
    
    //Getting a string from the user.
    string userInput;
    cout << "Please enter a lign of text: " << endl;
    getline(cin, userInput);

    //The function stringAnalyze identifies the amount of words in a string and update the array alphabet according to the reccurence of each letter.
    int amountWords = stringAnalyze(userInput, alphabet);

    //Checking if there is a plural amount of word(s).
    if(amountWords < 2) {
        cout << amountWords << TAB << "word" << endl;
    } else cout << amountWords << TAB << "words" << endl;
    //Printing out the alphabet array.
    printAlphabet(alphabet);
    
    //Exit the program.
    return 0;
}

//Functino that counts the words and the letters in a given string.
int stringAnalyze(string str, int alphabet[]) {
    int words = 0;
    bool newWord = false;
    for(char c : str) {
        //If c is a letter
        if(isLetter(c)) {
            newWord = true;
            //Increment the position relative to the current lower case letter in the alphabet.
            char l = toLower(c);
            alphabet[alphabetPositionLower(l)] ++;
        }
        //If c is a space
        else if(c == ' ') {
            words ++;
            newWord = false;
        }
    }
    //Increment the amount of words if the last part of the string is a word.
    if(newWord) {
        words ++;
    }
    return words;
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

//Function that returns the lower case letter of a given letter.
char toLower(char c) {
    if(int(c) >= 65 && int(c) <= 90) {
        return char(int(c) + 32);
    }
    else return c;
}

//Function to initialize the alphabet array
void initializeAlphabet(int alphabet[]){
    for(int i = 0; i < 26; i++) {
        alphabet[i] = 0;
    }
}

//Function that gives the position in the alphabet of a given lower case letter.
int alphabetPositionLower(char c) {
    return (int(c) - 97);
}

//Function to output the content of the alphabet array.
void printAlphabet(int alphabet[]) {
    for(int i = 0; i < 26; i ++) {
        if(alphabet[i] != 0) {
            cout << alphabet[i] << TAB << char(i + 97) << endl;
        }
    }
}