#include <iostream>
#include <vector>

using namespace std;

// Function to percolate an element down the heap
void percolate_down(vector<int>& heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    
    // Check if left child exists and is larger than the current node
    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }
    
    // Check if right child exists and is larger than the current node
    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }
    
    // If the largest element is not the current index, swap and percolate down
    if (largest != index) {
        swap(heap[index], heap[largest]);
        percolate_down(heap, largest);  // Recursive call to maintain the heap property
    }
}

// Function to pop the root of the max-heap (the first element)
int pop(vector<int>& heap) {
    if (heap.empty()) {
        return -1;  // Return an error value if heap is empty
    }
    
    // Swap the root (max element) with the last element
    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    
    // Restore the max-heap property by percolating down from the root
    percolate_down(heap, 0);
    
    return root;
}

// Function to heapify the heap (build the max-heap)
void heapify(vector<int>& heap) {
    // Start from the last non-leaf node and percolate down
    for (int i = heap.size() / 2 - 1; i >= 0; --i) {
        percolate_down(heap, i);
    }
}

// Function to find the kth smallest element using heap operations
int findKthSmallest(vector<int>& heap, int k) {
    // We first heapify the entire heap to ensure it satisfies the max-heap property
    heapify(heap);

    // Create a max-heap to keep track of the smallest k elements
    vector<int> maxHeap;

    // Build the initial max-heap with the first `k` elements
    for (int i = 0; i < k; ++i) {
        maxHeap.push_back(heap[i]);
        percolate_down(maxHeap, i);  // Ensure the heap property is maintained
    }

    // Process the remaining elements in the heap
    for (int i = k; i < heap.size(); ++i) {
        if (heap[i] < maxHeap[0]) {
            // Pop the root (max element) from the max-heap and insert the new element
            pop(maxHeap);
            maxHeap.push_back(heap[i]);
            percolate_down(maxHeap, 0);  // Restore max-heap property
        }
    }

    // The root of the max-heap will now be the kth smallest element
    return maxHeap[0];
}

// Function to check if the array is a max-heap
bool isMaxHeap(const vector<int>& heap) {
    for (size_t i = 0; i < heap.size() / 2; ++i) {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        
        if ((left < heap.size() && heap[i] < heap[left]) || 
            (right < heap.size() && heap[i] < heap[right])) {
            return false;  // Not a max-heap if any child is greater than parent
        }
    }
    return true;  // It's a valid max-heap
}

int main() {
    int N, k;
    while (cin >> N >> k) {  // Keep reading test cases until input ends
        vector<int> heap(N);
        for (int i = 0; i < N; ++i) {
            cin >> heap[i];
        }

        // Check if the heap is a max-heap before performing any heap operations
        bool isMax = isMaxHeap(heap);
        string isMaxHeapStr = isMax ? "Y" : "N";

        // Find the kth smallest element
        int kthSmallest = findKthSmallest(heap, k);

        // Output the result: whether it's a max-heap and the kth smallest element
        cout << isMaxHeapStr << "  " << kthSmallest << endl;
    }

    return 0;
}
