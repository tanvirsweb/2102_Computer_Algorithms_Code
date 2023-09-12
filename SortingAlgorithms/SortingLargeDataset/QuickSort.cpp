using namespace std;

// Function to partition the array into two sub-arrays
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = (low - 1);    // Initialize the index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap arr[i] and arr[j]
        }
    }

    swap(arr[i + 1], arr[high]); // Swap the pivot element with the element at (i + 1)
    return (i + 1); // Return the index of the pivot element
}

// Function to perform QuickSort
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        // Find the partition index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
