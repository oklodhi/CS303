#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <list>

using namespace std;

// Random sorting stuff

void generate_array(int arr[], int size){
    srand(time(NULL));
    
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 10000 + 1; 
        cout << arr[i] << " "; 
    }
}

void ShellSort(vector <int> &num) {
	int i, temp, flag = 1, numLength = num.size();
	int gap = numLength;
	bool insertionNeeded = false;
	int swapPos = 0;
	int key;

	while (true)  {    // boolean flag (true when not equal to 0) 
		gap = (gap - 1) / 2;
		if (gap == 0)
			break;

		for (int k = 0; k < gap; k++) {
			for (int j = gap + k; j < numLength; j += gap) {
				key = num[j];

				insertionNeeded = false;
				for (i = j - gap; i >= 0; i -= gap) {   // Smaller values move right

					if (key < num[i]) {
						swapPos = i;
						num[i + gap] = num[i];
						insertionNeeded = true;
					}
					else
						break;
				}
				if (insertionNeeded) {
					num[swapPos] = key;    //Put key into its proper location
				}
			}
		}
	}
	return;
}


void selection_sort(vector<int>& vec){

	for (int fill = 0; fill != vec.size(); ++fill) {
		int pos_min = fill;
		for (int next = fill + 1; next != vec.size(); ++next) {

			if (vec[next] < vec[pos_min])
				pos_min = next;

		}
		if (fill != pos_min)
			swap(vec[pos_min], vec[fill]);

	}
}


void BubbleSort(vector <int> &num){

	for (int i = 1; i <= num.size(); i++){
		for (int j = 0; j < num.size() - i; j++){
			if (num[j + 1] < num[j])
				swap(num[j], num[j + 1]);// swap elements
		}
	}
}

void bubble_sort_improved(vector <int> &vec){
	bool exchanges = false;
	for (int i = 1; i <= vec.size(); i++){
		exchanges = false;
		for (int j = 0; j < vec.size() - i; j++){
			if (vec[j + 1] < vec[j]){
				swap(vec[j], vec[j + 1]);// swap elements
				exchanges = true;
			}
		}
		if (!exchanges)
			break;
	}
}

void bubble_sort_list(list<int> &li){
	bool exchanges = false;
	list<int>::iterator itr = li.begin();
	for (int i = 1; i <= li.size(); i++){
		exchanges = false;
		itr = li.begin();
		for (int j = 0; j < li.size() - i; j++){
			list<int>::iterator current = itr;
			if (*(++itr)< *current){
				swap(*current, *itr);// swap elements
				exchanges = true;
			}
		}
		if (!exchanges)
			break;
	}
}

void insertion_sort(std::vector <int> &num) {
	int i, j, key;
	bool insertionNeeded = false;

	for (j = 1; j < num.size(); j++) {
		key = num[j];
		insertionNeeded = false;
		for (i = j - 1; i >= 0; i--){ // larger values move right

			if (key < num[i]) {
				num[i + 1] = num[i];
				insertionNeeded = true;
			}
			else
				break;
		}
		if (insertionNeeded)
			num[i + 1] = key;    //Put key into its proper location
	}
}


void merge(std::vector<int>& array, std::vector<int>& result, int lowPointer, int highPointer, int upperBound) {

	int j = 0;
	int lowerBound = lowPointer;
	int mid = highPointer - 1;
	int n = upperBound - lowerBound + 1; //number of items

	while (lowPointer <= mid && highPointer <= upperBound){

		if (array[lowPointer] < array[highPointer])
			result[j++] = array[lowPointer++];
		else
			result[j++] = array[highPointer++];
	}

	while (lowPointer <= mid) 
		result[j++] = array[lowPointer++];


	while (highPointer <= upperBound) 
		result[j++] = array[highPointer++];
	

	for (j = 0; j < n; j++) //copy the items from the temporary array to the original array
		array[lowerBound + j] = result[j];
}

void mergesort(std::vector<int>& array, std::vector<int>& result, int lowerBand, int upperBand) {
	int midpoint;
	if (lowerBand < upperBand) {
		midpoint = (lowerBand + upperBand) / 2;
		mergesort(array, result, lowerBand, midpoint); //merge sort the left half
		mergesort(array, result, midpoint + 1, upperBand); //merge sort the right half
		merge(array, result, lowerBand, midpoint + 1, upperBand);
	}
}

void mergeSort(std::vector<int>& array){
	std::vector<int> result = array;
	mergesort(array, result, 0, array.size() - 1);
}



int partition(int first, int last, std::vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.
	int up = first+1;
	int down = last-1;
	do {

		while ((up != last) && !(arr[first] < arr[up])) {
			++up;
		}
		while (arr[first] < arr[down]) {
			--down;
		}
		if (up < down) {
			// if up is to the left of down,
			swap(arr[up], arr[down]);
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[down], arr[first]);
	return down;
}

void sort_median(std::vector<int>& arr, int first, int last){

	bool exchanges = true;
	int middle = (first + last) / 2;
	if (arr[first]>arr[middle])
		swap(arr[first], arr[middle]);
	if (arr[middle] > arr[last])
		swap(arr[middle], arr[last]);
	if (arr[first] > arr[middle])
		swap(arr[first], arr[middle]);


	//swap the middle with the left 
	swap(arr[middle], arr[first]);
}

int partitionB(int first, int last, std::vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.


	int up = first+1;
	int down = last-1;
	sort_median(arr, first, last-1);
	int mid = first;
	do {
		while ((up != last - 1) && !(arr[mid] < arr[up])) {
			++up;
		}
		while (arr[mid] < arr[down]) {
			--down;
		}
		if (up < down) {
			// if up is to the left of down,
			swap(arr[up], arr[down]);
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[mid], arr[down]);
	
	return down;
}

void middle_quick_sort(int first, int last, std::vector<int>& arr) {
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partitionB(first, last, arr);

		// Sort the left half.
		middle_quick_sort(first, pivot, arr);

		// Sort the right half.
		middle_quick_sort(pivot + 1, last, arr);
	}
}

void middle_quick_sort_wrapper(vector<int>& arr){
	middle_quick_sort(0, arr.size(), arr);
}

void quick_sort(int first, int last, std::vector<int>& arr) {
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partition(first, last, arr);

		// Sort the left subarray.
		quick_sort(first, pivot, arr);

		// Sort the right subarray.
		quick_sort(pivot + 1, last, arr);
	}
}

void quick_sort_wrapper(vector<int>& arr){
	quick_sort(0, arr.size(), arr);
}

int main(){
    const int size = 10000;
    int randomArr[size];
    
    generate_array(randomArr, size);
}
