#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// constant variable declarations
const int SIZE = 10000; 
const int TYPE_RANDOM = 0;
const int TYPE_SORTED = 1; 
const int TYPE_REVERSE = 2; 

// global counters for comparisons and exchanges
int comparisons = 0;
int num_exchanges = 0;

// set comparisons and exchnages to 0, used after any type of sort is used
void set_to_zero() {
	comparisons = 0;
	num_exchanges = 0;
}

// generate the arrays of SIZE with depending on RANDOM, ASCENDING, and DESCENDING
void generate_arrays(int arr[], int size, int arrtype) {
	if (arrtype == 0) { // random fill
		srand(time(NULL));
		for (int i = 0; i < size; i++) {
			// fill from 1 - 10000 randomly
			arr[i] = rand() % size + 1; 
			//cout << arr[i] << " ";
		}
		//cout << endl << endl;
	}
	else if (arrtype == 1) { // asceding sorted fill
		for (int i = 0; i < size; i++) {
			// fill from 1 - 10000
			arr[i] = i+1;
			//cout << arr[i] << " ";
		}
		//cout << endl << endl;
	}
	else if (arrtype == 2) { // reverse sorted fill
	    int j = 0; 
		for (int i = size; i > 0; i--) {
			// fill from 10000 - 1
			arr[j] = i;
			j++;
			//cout << arr[i] << " ";
		}
		//cout << endl << endl;
	}
}

// refill array data
void refillArrays(int random_array[], int sorted_array[], int reverse_array[], int SIZE) {
	generate_arrays(random_array, SIZE, 0);
	generate_arrays(sorted_array, SIZE, 1);
	generate_arrays(reverse_array, SIZE, 2);
}

// swapping elements
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp; 
}

// selection sort algo
void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			comparisons++; 
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i){
		    num_exchanges++;
		} 
		swap(arr, min, i);
	}
}

// bubble sort algo
void bubbleSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			comparisons++;
			if (arr[j+1] < arr[j]) {
				num_exchanges++;
				swap(arr, j, j+1);
			}
		}
	}
}

// insertion sort algo
void insertionSort(int arr[], int size)
{
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i;

		comparisons++;
		while (j >= 0 && arr[j-1] > key)
		{
			comparisons++;
			num_exchanges++;
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = key;
	}
}

// shell sort algo
void shellSort(int arr[], int size) {
	int x = size / 2;
	while (x > 0)
	{
		for (int i = x; i < size; i++)
		{
			for (int j = i; j >= x; j = j - x)
			{
				comparisons++;
				if (arr[j] < arr[j - x])
				{
					num_exchanges++;
					swap(arr, j, j - x);
				}
				else
				{
					break;
				}
			}
		}

		x = x / 2;
	}
}

// merge function
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) {
		num_exchanges++;
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++) {
		num_exchanges++;
		R[j] = arr[m + 1 + j];
	}

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		comparisons++;
		if (L[i] <= R[j])
		{
			num_exchanges++;
			arr[k] = L[i];
			i++;
		}
		else
		{
			num_exchanges++;
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		num_exchanges++;
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		num_exchanges++;
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

// quick sort swap
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// quick sort partition
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		comparisons++;
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element  
			num_exchanges++;
			swap(&arr[i], &arr[j]);
		}
	}
	num_exchanges++;
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// quick sort algo
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void sort_median(int arr[], int first, int last) {

	int middle = (first + last) / 2;
	comparisons++;
	if (arr[first] > arr[middle]) {
		num_exchanges++;
		swap(arr[first], arr[middle]);
	}
	comparisons++;
	if (arr[middle] > arr[last]) {
		num_exchanges++;
		swap(arr[middle], arr[last]);
	}
		
	comparisons++;
	if (arr[first] > arr[middle]) {
		num_exchanges++;
		swap(arr[first], arr[middle]);
	}


	//swap the middle with the left 
	num_exchanges++;
	swap(arr[middle], arr[first]);
}

int partitionB(int first, int last, int arr[]) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.


	int up = first + 1;
	int down = last - 1;
	sort_median(arr, first, last - 1);
	int mid = first;
	do {
		comparisons++;
		while ((up != last - 1) && !(arr[mid] < arr[up])) {
			comparisons++;
			++up;
		}
		comparisons++;
		while (arr[mid] < arr[down]) {
			comparisons++;
			--down;
		}
		if (up < down) {
			// if up is to the left of down,
			num_exchanges++;
			swap(arr[up], arr[down]);
		}
	} while (up < down); // Repeat while up is left of down.

	num_exchanges++;
	swap(arr[mid], arr[down]);

	return down;
}

void middle_quick_sort(int first, int last, int arr[]) {
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

// quick sort improved 
void middle_quick_sort_wrapper(int arr[], int SIZE) {
	middle_quick_sort(0, SIZE, arr);
}

int main() {
	// initiate arrays
	int random_array[SIZE]; 
	int sorted_array[SIZE];
	int reverse_array[SIZE]; 

	/*----------------------------------------------*/

	// SELECTION SORT COMPARISON AND EXCHANGES
	refillArrays(random_array, sorted_array, reverse_array, SIZE);
	selectionSort(random_array, SIZE);
	cout << "Selection Sort (Random) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	selectionSort(sorted_array, SIZE);
	cout << "Selection Sort (Ascend) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	selectionSort(reverse_array, SIZE);
	cout << "Selection Sort (Descen) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	// BUBBLE SORT COMPARISON AND EXCHANGES
	refillArrays(random_array, sorted_array, reverse_array, SIZE);
	bubbleSort(random_array, SIZE);
	cout << "Bubble Sort (Random) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	bubbleSort(sorted_array, SIZE);
	cout << "Bubble Sort (Ascend) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	bubbleSort(reverse_array, SIZE);
	cout << "Bubble Sort (Descen) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	// INSERTION SORT COMPARISON AND EXCHANGES
	refillArrays(random_array, sorted_array, reverse_array, SIZE);
	insertionSort(random_array, SIZE);
	cout << "Insertion Sort (Random) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	insertionSort(sorted_array, SIZE);
	cout << "Insertion Sort (Ascend) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	insertionSort(reverse_array, SIZE);
	cout << "Insertion Sort (Descen) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	// SHELL SORT COMPARISON AND EXCHANGES
	refillArrays(random_array, sorted_array, reverse_array, SIZE);
	shellSort(random_array, SIZE);
	cout << "Shell Sort (Random) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	shellSort(sorted_array, SIZE);
	cout << "Shell Sort (Ascend) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	shellSort(reverse_array, SIZE);
	cout << "Shell Sort (Descen) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	// MERGE SORT COMPARISON AND EXCHANGES
	refillArrays(random_array, sorted_array, reverse_array, SIZE);
	mergeSort(random_array, 0, SIZE - 1);
	cout << "Merge Sort (Random) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	mergeSort(sorted_array, 0, SIZE - 1);
		cout << "Merge Sort (Ascend) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	mergeSort(reverse_array, 0, SIZE - 1);
		cout << "Merge Sort (Descen) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	// QUICK SORT COMPARISON AND EXCHANGES
	refillArrays(random_array, sorted_array, reverse_array, SIZE);
	quickSort(random_array,0 , SIZE - 1);
	cout << "Quick Sort (Random) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	quickSort(sorted_array, 0, SIZE - 1);
	cout << "Quick Sort (Ascend) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	quickSort(reverse_array, 0, SIZE - 1);
	cout << "Quick Sort (Descen) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	// IMPROVED QUICK SORT COMPARISONS AND EXCHANGES
	refillArrays(random_array, sorted_array, reverse_array, SIZE);
	middle_quick_sort_wrapper(random_array, SIZE);
	cout << "Imp. Quick Sort (Random) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	middle_quick_sort_wrapper(sorted_array, SIZE);
	cout << "Imp. Quick Sort (Ascend) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();

	middle_quick_sort_wrapper(reverse_array, SIZE);
	cout << "Imp. Quick Sort (Descen) C: " << comparisons << "\t\tE: " << num_exchanges << endl;
	set_to_zero();
}
