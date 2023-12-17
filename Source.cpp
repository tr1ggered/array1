#include <iostream>
#include <ctime>
using namespace std;

// ������� ��� ��������� ���������� ����� � ��������� �� min �� max
int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

// ������� ��� ���������� ������� ���������� �������
void fillArrayWithRandom(int** arr, int rows, int cols) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = getRandomNumber(1, 100);
        }
    }
}

// ������� ��� ���������� ������� � ����������
void fillArrayFromUser(int** arr, int rows, int cols) {
    cout << "Enter Array Elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
}

// ������� ��� ������ ������� �� �����
void printArray(int** arr, int rows, int cols) {
    cout << "Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// ������� ��� ������ ������������ �������� ������ ������ �� ����
void replaceMinWithZero(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int minElement = arr[i][0];
        for (int j = 1; j < cols; j++) {
            if (arr[i][j] < minElement) {
                minElement = arr[i][j];
            }
        }
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == minElement) {
                arr[i][j] = 0;
            }
        }
    }
}

// ������� ��� �������� �������� � ��������� �������������� ����������
void removeColumnsWithOddPositiveElements(int** arr, int& rows, int& cols) {
    for (int j = 0; j < cols; j++) {
        bool containsOddPositive = false;
        for (int i = 0; i < rows; i++) {
            if (arr[i][j] > 0 && arr[i][j] % 2 != 0) {
                containsOddPositive = true;
                break;
            }
        }
        if (containsOddPositive) {
            for (int i = 0; i < rows; i++) {
                for (int k = j + 1; k < cols; k++) {
                    arr[i][k - 1] = arr[i][k];
                }
            }
            cols--;
            j--;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns of the array: ";
    cin >> n >> m;

    // �������� ���������� ������������� �������
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    // ���������� �������
    cout << "Select how to fill the array: " << endl;
    cout << "1 - Generate random numbers." << endl;
    cout << "2 - Fill in from the keyboard." << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        fillArrayWithRandom(arr, n, m);
    }
    else if (choice == 2) {
        fillArrayFromUser(arr, n, m);
    }
    else {
        cout << "Incorrect choice. Filling an array with random numbers." << endl;
        fillArrayWithRandom(arr, n, m);
    }

    // ����� ������� �� �����
    printArray(arr, n, m);

    // ������ ������������ �������� ������ ������ �� ����
    replaceMinWithZero(arr, n, m);

    // �������� �������� � ��������� �������������� ����������
    removeColumnsWithOddPositiveElements(arr, n, m);

    // ����� ������������ ������� �� �����
    printArray(arr, n, m);

    // ������������ ������
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}