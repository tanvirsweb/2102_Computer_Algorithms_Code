using namespace std;

// Function to find the maximum element in the array
int findMax(std::vector<int>& arr) {
    int max = arr[0];
    for (int num : arr) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

// Counting Sort for a specific digit (place value)
void countingSort(std::vector<int>& arr, int exp) {
    const int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr) {
    int max = findMax(arr);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}
