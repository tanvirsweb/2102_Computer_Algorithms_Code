using namespace std;

void countingSort(std::vector<int>& arr) {
    // Find the maximum value in the array to determine the range.
    int max_value = arr[0];
    int min_value = arr[0];
    for (int num : arr) {
        if (num > max_value) {
            max_value = num;
        }
        if (num < min_value) {
            min_value = num;
        }
    }

    // Create a counting array to store the count of each element.
    std::vector<int> count(max_value - min_value + 1, 0);

    // Count the occurrences of each element in the input array.
    for (int num : arr) {
        count[num - min_value]++;
    }

    // Reconstruct the sorted array from the counting array.
    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            arr[index] = i + min_value;
            index++;
            count[i]--;
        }
    }
}
