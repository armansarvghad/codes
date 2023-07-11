#include <iostream>

void multiplyArray(int* arr, int size, int scalar) {
    for (int i = 0; i < size; i+=4) {
        arr[i] *= scalar;
        arr[i + 1] *= scalar;
        arr[i + 2] *= scalar;
        arr[i + 3] *= scalar;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    multiplyArray(arr, size, 2);

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
