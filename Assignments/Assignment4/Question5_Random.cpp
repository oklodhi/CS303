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
int exchanges = 0;

void set_to_zero() {
	comparisons = 0;
	exchanges = 0;
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
		for (int i = size; i > 0; i--) {
			// fill from 10000 - 1
			arr[i] = i;
			//cout << arr[i] << " ";
		}
		//cout << endl << endl;
	}
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
			if (arr[j] < arr[i]) {
				min = j;
			}
		}
		exchanges++; 
		swap(arr, min, i);
	}
}

// bubble sort algo
void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			comparisons++;
			if (arr[i] < arr[j]) {
				exchanges++;
				swap(arr, i, j);
			}
		}
	}
}

// insertion sort algo
void insertionSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int temp = arr[i];
		int j = i; 

		comparisons++;
		while (j > 0 && temp < arr[j - 1]) {
			exchanges++;
			arr[j] = arr[j - 1];
			j--;
		}

		arr[j] = temp;
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
					exchanges++;
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


int main() {
	// initiate arrays
	int random_array[SIZE]; 
	int sorted_array[SIZE];
	int reverse_array[SIZE]; 

	// generate arrays with filled data
	generate_arrays(random_array, SIZE, 0);
	generate_arrays(sorted_array, SIZE, 1);
	generate_arrays(reverse_array, SIZE, 2);

	/*----------------------------------------------*/

	// SELECTION SORT COMPARISON AND EXCHANGES
	selectionSort(random_array, SIZE);
	cout << "Selection Sort (Random) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();

	selectionSort(sorted_array, SIZE);
	cout << "Selection Sort (Ascend) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();

	selectionSort(reverse_array, SIZE);
	cout << "Selection Sort (Descen) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();

	// BUBBLE SORT COMPARISON AND EXCHANGES
	bubbleSort(random_array, SIZE);
	cout << "Bubble Sort (Random) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();

	bubbleSort(sorted_array, SIZE);
	cout << "Bubble Sort (Ascend) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();

	bubbleSort(reverse_array, SIZE);
	cout << "Bubble Sort (Descen) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();

	// INSERTION SORT COMPARISON AND EXCHANGES
	insertionSort(random_array, SIZE);
	cout << "Insertion Sort (Random) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();

	insertionSort(sorted_array, SIZE);
	cout << "Insertion Sort (Ascend) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();

	insertionSort(reverse_array, SIZE);
	cout << "Insertion Sort (Descen) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();

	// SHELL SORT COMPARISON AND EXCHANGES
	shellSort(random_array, SIZE);
	cout << "Shell Sort (Random) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();

	shellSort(sorted_array, SIZE);
	cout << "Shell Sort (Ascend) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();

	shellSort(reverse_array, SIZE);
	cout << "Shell Sort (Descen) C: " << comparisons << "\tE: " << exchanges << endl;
	set_to_zero();
}
