#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;


void PrintArray(int* arrayPtr, int arraySize) {

    for (int i = 0; i < arraySize; i++)
        cout << arrayPtr[i] << " ";

    cout << endl;


}


int Merge(int* leftSubArrayPtr, int leftArraySize, int* rightSubArrayPtr, int rightArraySize, int* arrayPtr, int arraySize) {

    int leftIndex = 0;
    int rightIndex = 0;
    int arrayIndex = 0;
    int inv_count = 0;

    while (leftIndex < leftArraySize && rightIndex < rightArraySize) {

        if (leftSubArrayPtr[leftIndex] <= rightSubArrayPtr[rightIndex]) {

            arrayPtr[arrayIndex] = leftSubArrayPtr[leftIndex];
            leftIndex++;

        }
        else {

            arrayPtr[arrayIndex] = rightSubArrayPtr[rightIndex];
            inv_count = inv_count + (leftArraySize - leftIndex);
            for (int i = leftIndex; i < leftArraySize; i++)
                cout << "(" << leftSubArrayPtr[i] << "," << rightSubArrayPtr[rightIndex] << ")\n";
            rightIndex++;

        }

        arrayIndex++;

    }


    if (leftIndex == leftArraySize) {

        for (; rightIndex < rightArraySize; rightIndex++) {
            arrayPtr[arrayIndex] = rightSubArrayPtr[rightIndex];
            arrayIndex++;
        }

    }
    else {

        for (; leftIndex < leftArraySize; leftIndex++) {
            arrayPtr[arrayIndex] = leftSubArrayPtr[leftIndex];
            arrayIndex++;
        }

    }

    return inv_count;

}

int MergeSort(int* arrayPtr, int arraySize) {
    int inv_count = 0;

    if (arraySize > 1) {

        int* leftSubArrayPtr = new int[arraySize / 2];
        int* rightSubArrayPtr = new int[arraySize - arraySize / 2];

        for (int i = 0; i < (arraySize / 2); i++)
            leftSubArrayPtr[i] = arrayPtr[i];

        for (int i = arraySize / 2; i < arraySize; i++)
            rightSubArrayPtr[i - (arraySize / 2)] = arrayPtr[i];


        inv_count += MergeSort(leftSubArrayPtr, arraySize / 2);
        inv_count += MergeSort(rightSubArrayPtr, arraySize - arraySize / 2);

        inv_count += Merge(leftSubArrayPtr, arraySize / 2, rightSubArrayPtr, arraySize - arraySize / 2, arrayPtr, arraySize);

    }

    return inv_count;
}


int main() {

    int arraySize;
    cout << "Enter how large you want the array: ";
    cin >> arraySize;

    int maxVal = 50;

    srand(time(NULL));

    int* arrayPtr = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
        arrayPtr[i] = 1 + rand() % maxVal;

    cout << "Before sorting..." << endl;
    PrintArray(arrayPtr, arraySize);

    cout << "\nInversion Pairs\n";
    int inversion = MergeSort(arrayPtr, arraySize);
    cout << "\nnumber of Inversions = " << inversion << "\n";

    cout << "After sorting..." << endl;
    PrintArray(arrayPtr, arraySize);

    system("pause");

    return 0;
}