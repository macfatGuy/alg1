#include <iostream>
#include <vector>

int countElementsGreaterThan(const std::vector<int>& arr, int threshold) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1; 

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= threshold) {
            left = mid + 1;
        }
        else {
            result = mid; 
            right = mid - 1; 
        }
    }

   
    if (result == -1) return 0;

    return arr.size() - result;
}

int main() {
    std::vector<int> sortedArray = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int threshold;

    std::cout << "Введите точку отсчёта: ";
    std::cin >> threshold;

    int count = countElementsGreaterThan(sortedArray, threshold);
    std::cout << "Количество элементов в массиве больших, чем " << threshold << ": " << count << std::endl;

    return 0;
}

