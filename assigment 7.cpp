#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string rowSequence;
    cout << "Enter the rowSequence: ";
    cin >> rowSequence;

    string columnSequence;
    cout << "Enter the columnSequence: ";
    cin >> columnSequence;

    int numRows = rowSequence.length() + 1;
    int numCols = columnSequence.length() + 1;
    int** twoDimTable = new int* [numRows];

    for (int rowIndex = 0; rowIndex < numRows; rowIndex++) {

        twoDimTable[rowIndex] = new int[numCols];

    }

   

    for (int rowIndex = 0; rowIndex < numRows; rowIndex++) {
        for (int colIndex = 0; colIndex < numCols; colIndex++) {
            if (rowIndex == 0 || colIndex == 0)
                twoDimTable[rowIndex][colIndex] = 0;

            else if (rowSequence[rowIndex - 1] == columnSequence[colIndex - 1])
                twoDimTable[rowIndex][colIndex] = twoDimTable[rowIndex - 1][colIndex - 1] + 1;

            else
                twoDimTable[rowIndex][colIndex] = max(twoDimTable[rowIndex - 1][colIndex], twoDimTable[rowIndex][colIndex - 1]);
        }
    }


    cout << "Printing the 2D table\n" << endl;
    for (int rowIndex = 0; rowIndex < numRows; rowIndex++) {
        for (int colIndex = 0; colIndex < numCols; colIndex++) {
            cout << twoDimTable[rowIndex][colIndex] << " ";
        }
        cout << endl;
    }

    cout << "\nLength of the LCS: " << twoDimTable[numRows - 1][numCols - 1] << endl;


    int i = twoDimTable[numRows - 1][numCols - 1];
    char* lcs = new char[i + 1];
    lcs[i] = '\0';

    int rowIndex = numRows - 1, colIndex = numCols - 1;

    while (rowIndex > 0 && colIndex > 0) {
  
        if (rowSequence[rowIndex - 1] == columnSequence[colIndex - 1]) {
            lcs[i - 1] = rowSequence[rowIndex - 1];
            rowIndex--;
            colIndex--;
            i--;
        }


        else if (twoDimTable[rowIndex - 1][colIndex] > twoDimTable[rowIndex][colIndex - 1])
            rowIndex--;
        else
            colIndex--;
    }

    cout << "\nLCS string: " << lcs << endl;



    return 0;

}
