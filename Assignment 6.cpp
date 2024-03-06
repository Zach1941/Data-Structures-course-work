#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>//clock_t, clock, CLOCKS_PER_SEC

using namespace std;

// Sorting in increasing order, Based on FinishTime.
void SortBasedOnFinishTimes(int* activityIDs, int* startTimes, int* finishTimes, int numActivities) {
    int length = sizeof(startTimes) / sizeof(startTimes[0]);
    for (int i = 0; i < numActivities - 1; i++) {
        for (int j = i + 1; i < numActivities; j++) {
            if (finishTimes[i] > finishTimes[j]) {
                int t1 = finishTimes[i];
                finishTimes[i] = finishTimes[j];
                finishTimes[j] = t1;
                int t2 = startTimes[i];
                startTimes[i] = startTimes[j];
                startTimes[j] = t2;
                int t3 = activityIDs[i];
                activityIDs[i] = activityIDs[j];
                activityIDs[j] = t3;
            }
        }
    }
}

void PrintArray(int* array, int arraySize) {

    for (int index = 0; index < arraySize; index++) {

        cout << array[index] << "\t";
    }
}

int main() {

    int numActivities;
    cout << "Enter the number of activities: ";
    cin >> numActivities;

    srand(time(NULL));

    int* activityIDs = new int[numActivities];
    int* startTimes = new int[numActivities];
    int* finishTimes = new int[numActivities];

    int maxDiffSuccessiveStartTime = 3;
    int maxActivityDuration = 6;

    startTimes[0] = 1;

    for (int index = 0; index < numActivities; index++) {

        activityIDs[index] = index + 1;

        if (index > 0)
            startTimes[index] = startTimes[index - 1] + 1 + (rand() % maxDiffSuccessiveStartTime);

        finishTimes[index] = startTimes[index] + 1 + (rand() % maxActivityDuration);

    }

    cout << "Before sorting: " << endl;
    cout << "Activities and their start/finish times " << endl;
    PrintArray(activityIDs, numActivities);
    PrintArray(startTimes, numActivities);
    PrintArray(finishTimes, numActivities);



    SortBasedOnFinishTimes(activityIDs, startTimes, finishTimes, numActivities);

    cout << "After sorting: " << endl;
    cout << "Activities and their start/finish times " << endl;
    PrintArray(activityIDs, numActivities);
    PrintArray(startTimes, numActivities);
    PrintArray(finishTimes, numActivities);
    cout << endl;

    // Greedy Approach implementation 
    int* selectedActivities = new int[numActivities];
    int cur_f = finishTimes[0];
    int s_cnt = 0; // number of total selected activities.
    for (int i = 1; i < numActivities; i++) {
        if (startTimes[i] >= cur_f) {
            cur_f = finishTimes[i];
            selectedActivities[s_cnt] = activityIDs[i];
            s_cnt += 1;
        }
    }

    PrintArray(selectedActivities, s_cnt);

    system("pause");

    return 0;

}