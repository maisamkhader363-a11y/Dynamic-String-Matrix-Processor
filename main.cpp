#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int countVowels1D(char* arr) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U') {
            count++;
        }
    }
    return count;
}

int countVowels2D(char** matrix, int rows) {
    int totalCount = 0;
    for (int i = 0; i < rows; i++) {
        totalCount += countVowels1D(matrix[i]);
    }
    return totalCount;
}


char* findLongestString(char** arr, int rows) {
    int maxLen = 0;
    int longestIndex = 0;
    for (int i = 0; i < rows; i++) {
        int len = strlen(arr[i]);
        if (len > maxLen) {
            maxLen = len;
            longestIndex = i;
        }
    }
    return arr[longestIndex];
}

int main() {
    int m, n;
  
    cout << "Enter the number of strings (rows): ";
    cin >> m;
    cout << "Enter the maximum length of each string (columns including null): ";
    cin >> n;

    char** arr = new char* [m];
    for (int i = 0; i < m; i++) {
        arr[i] = new char[n];
    }

    cout << "Enter " << m << " strings (max " << n - 1 << " characters each):"<<endl;
    for (int i = 0; i < m; i++) {
        cout << "String [" << i + 1 << "]: ";
        cin >> arr[i];
    }

    int choice;
    do {
       
        cout << " Choose an operation to perform on the matrix:"<<endl;
        cout << "1. Count vowels per individual string"<<endl;
        cout << "2. Count total vowels in the entire matrix"<<endl;
        cout << "3. Find the longest string in the matrix"<<endl;
        cout << "4. Exit & Clean Memory"<<endl;
        cout << "Enter your choice (1-4): "<<endl;
        cin >> choice;
    

        switch (choice) {
        case 1:
            cout << "Results for choice 1:";
            for (int i = 0; i < m; i++) {
                cout << "the number of vowels in string( " << i + 1 << ") is:" << countVowels1D(arr[i]) << endl;
            
            }
            break;
        case 2:
            cout << "Results for choice 2:";
            cout << "Total number of vowels in the entire matrix: "
                << countVowels2D(arr, m) << endl;
            break;
        case 3: {
            cout << "Results for choice 3";
            char* longest = findLongestString(arr, m);
            cout << " The longest string is: " << longest << endl;
            cout << " Length: " << strlen(longest) << " characters"<<endl;
            break;
        }
        case 4:
            cout << "Releasing memory resources and exiting system..." << endl;
            break;
        default:
            cout << "Invalid choice! Please select an option from 1 to 4"<<endl;
        }
    } while (choice != 4);
    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
