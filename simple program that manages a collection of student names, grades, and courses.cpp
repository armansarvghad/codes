#include <iostream>
using namespace std;

float calculateAverage(const float grades[], int n) {
    float result = 0;
    for (int i = 0; i < n; i++) {
        result += grades[i];
    }
    result /= n;
    return result;
}

void findMaxGrade(const string names[], const float grades[], int n) {
    float maxGrade = grades[0];
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (grades[i] > maxGrade) {
            maxGrade = grades[i];
            maxIndex = i;
        }
    }
    cout << names[maxIndex] << ": " << maxGrade << endl;
}

int main(int argc, char** argv) {
    int n;
    cout << "Please Enter Number of Numbers: ";
    cin >> n;

    const int MAX_SIZE = n;
    string names[MAX_SIZE];
    float grades[MAX_SIZE];
    string courses[MAX_SIZE];

    cout << " ------------------------- " << endl;
    cout << "|                         |" << endl;
    cout << "| [1] --> Enter Names     |" << endl;
    cout << "|                         |" << endl;
    cout << "| [2] --> Enter Numbers   |" << endl;
    cout << "|                         |" << endl;
    cout << "| [3] --> Enter Courses   |" << endl;
    cout << "|                         |" << endl;
    cout << "| [4] --> Average         |" << endl;
    cout << "|                         |" << endl;
    cout << "| [5] --> Name with Max   |" << endl;
    cout << "|                         |" << endl;
    cout << "| [6] --> Show by Name    |" << endl;
    cout << "|                         |" << endl;
    cout << "| [7] --> Show All        |" << endl;
    cout << "|                         |" << endl;
    cout << "| [8] --> Exit            |" << endl;
    cout << " ------------------------- " << endl;

    while (true) {
        int item;
        cout << "Your item: ";
        cin >> item;

        switch (item) {
            case 1:
                for (int i = 0; i < n; i++) {
                    cout << "Name " << i + 1 << ": ";
                    cin.ignore();
                    getline(cin, names[i]);
                }
                break;

            case 2:
                for (int i = 0; i < n; i++) {
                    cout << names[i] << ": ";
                    cin >> grades[i];
                }
                break;

            case 3:
                for (int i = 0; i < n; i++) {
                    cout << "Course "<< i + 1 << ": "; 
                    cin >> courses[i];
                    } 
                    break;
            case 4:
            float average = calculateAverage(grades, n);
            cout << "Average is " << average << endl;
            break;

            case 5:
            findMaxGrade(names, grades, n);
            break;

            case 6:
            string searchName;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, searchName);
            for (int i = 0; i < n; i++) {
                if (names[i] == searchName) {
                    cout << courses[i] << ": " << grades[i] << endl;
                }
            }
            break;

            case 7:
            for (int i = 0; i < n; i++) {
                cout << names[i] << " : " << grades[i] << " , ";
            }
            cout << endl;
            break;

            case 8:
            return 0;

            default:
            cout << "*** Invalid item ***" << endl;
            break;
    }
}