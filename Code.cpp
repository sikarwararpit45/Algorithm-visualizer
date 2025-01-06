#include "algoviz.h"
#include <vector>

void quickSort(std::vector<int>& arr, int low, int high, AlgoViz::ArrayTracer& tracer, AlgoViz::LogTracer& logger) {
    if (low < high) {
        // Partition the array
        int pivotIndex = partition(arr, low, high, tracer, logger);

        // Recursively sort the left and right partitions
        quickSort(arr, low, pivotIndex - 1, tracer, logger);
        quickSort(arr, pivotIndex + 1, high, tracer, logger);
    }
}

int partition(std::vector<int>& arr, int low, int high, AlgoViz::ArrayTracer& tracer, AlgoViz::LogTracer& logger) {
    int pivot = arr[high];
    logger.log("Selected pivot: " + std::to_string(pivot));
    tracer.select(high);
    AlgoViz::delay(1000);

    int i = low - 1;

    for (int j = low; j < high; j++) {
        tracer.select(j);
        AlgoViz::delay(500);

        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            logger.log("Swapping " + std::to_string(arr[i]) + " and " + std::to_string(arr[j]));
            tracer.set(arr);
            AlgoViz::delay(1000);
        }

        tracer.deselect(j);
    }

    // Place pivot in the correct position
    std::swap(arr[i + 1], arr[high]);
    logger.log("Placing pivot " + std::to_string(pivot) + " at index " + std::to_string(i + 1));
    tracer.set(arr);
    AlgoViz::delay(1000);

    tracer.deselect(high);
    return i + 1;
}

int main() {
    // Initialize array and tracers
    std::vector<int> arr = {8, 4, 7, 3, 10, 1};
    AlgoViz::ArrayTracer tracer(arr);
    AlgoViz::LogTracer logger;

    logger.log("Starting Quick Sort...");
    tracer.set(arr);

    // Perform Quick Sort
    quickSort(arr, 0, arr.size() - 1, tracer, logger);

    logger.log("Quick Sort complete.");
    tracer.set(arr); // Final state of the array

    return 0;
}
