/***********************************************************************
 *
 *	Merge Sort (and Insertion sort) Microassignment
 *   Aaron S. Crandall, 2016
 *
 *   CptS 223
 *
 *	Modified by: Kimi Phan, Fall 2016
 *	Modified functions:
 * 		-executeMergeSort
 *		-executeInsertionSort
 *	Fucntions add:
 *		-mergesort
 *		-merge
 */


#include <iostream>
#include <chrono>
#include <vector>
#include <stdlib.h>  // rand
#include <time.h>    // time for srand

using namespace std::chrono;
using namespace std;

enum SortType {doMergeSort, doInsertionSort, doBubbleSort};

//void showFirstNElements(vector<int> &data, int n);
//bool are_VectorsIdentical(vector<int> &vecA, vector<int> &vecB);
//void executeMergeSort(vector<int> &data);
void mergesort(vector<int> &data, vector<int> &temp, int left, int right);
void merge(vector<int> &data, vector<int> &temp, int left, int center, int right);


/**********************************************************/
void showFirstNElements(vector<int> &data, int n)
{
	cout << data[0];
	for( int i = 1; i < n; i++ )
	{
		cout << ", " << data[i];
	}
	cout << endl;
}


/**********************************************************/
bool are_VectorsIdentical(vector<int> &vecA, vector<int> &vecB)
{
	bool result = true;
	for( int i = 0; i < vecA.size(); i++ )
	{
		if( vecA[i] != vecB[i] )
		{
			result = false;
			return(result);
		}
	}
	return result;
}

// Date Modfied: November 6, 2016
/**********************************************************/
void executeMergeSort(vector<int> &data)
{
	cout << " [x] Doing Merge Sort." << endl;

	vector<int> temp(data.size());
	mergesort(data, temp, 0, data.size() - 1);
}

// Date Added: November 6, 2016
// Description: Recursively calls itself to keep splitting up the list until
// 							it seperates it into single elements then it merges the list
//							back together.
void mergesort(vector<int> &data, vector<int> &temp, int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2; //splits the list in half
		mergesort(data, temp, left, center); //focuses on the left sublist
		mergesort(data, temp, center + 1, right); //focuses on the right sublist
		merge(data, temp, left, center, right); //merges the elements back together
	}
}

// Date Added: November 6, 2016
// Description: Sorts the sublists and merges the two sublists back together
void merge(vector<int> &data, vector<int> &temp, int left, int center, int right)
{
	int leftPos = left;
	int rightPos = left;
	int rightBeg = center + 1;

	//main loop
	while(leftPos <= center && rightBeg <= right)
	{
		if (data[leftPos] < data[rightBeg]) //compares the two lists
		{
			temp[rightPos++] = data[leftPos++];
		}
		else
		{
			temp[rightPos++] = data[rightBeg++];
		}
	}

	//copies over the rest of the left half of the list
	while(leftPos <= center)
	{
		temp[rightPos++] = data[leftPos++];
	}

	//copies over the rest of the right half of the list
	while(rightBeg <= right)
	{
		temp[rightPos++] = data[rightBeg++];
	}

	//copies the temp list back into the original list.
	for(leftPos = left; leftPos < rightPos; leftPos++)
	{
		data[leftPos] = temp[leftPos];
	}
}

// Date Modified: November 6, 2016
/**********************************************************/
void executeInsertionSort(vector<int> &data)
{
	cout << " [x] Doing Insertion Sort." << endl;

	int length = data.size();
	int temp = 0;
	int j = 0;

	for(int i = 0; i < length; i++)
	{
		j = i;

		while(j > 0 && data[j] < data[j - 1])
		{
			// swap is performed
			temp = data[j];
			data[j] = data[j - 1];
			data[j - 1] = temp;
			j--;
		}
	}
}


/**********************************************************/
void executeBubbleSort(vector<int> &data)
{
	cout << " [x] Doing Bubble Sort." << endl;
	int n = data.size();
	int swap = 0;
	for (int c = 0 ; c < ( n - 1 ); c++)
	{
		for (int d = 0 ; d < n - c - 1; d++)
		{
			if (data[d] > data[d+1])
			{
				swap      = data[d];
				data[d]   = data[d+1];
				data[d+1] = swap;
			}
		}
	}
}


/*****************************************************************************/
std::chrono::duration<double> do_Benchmark(SortType sortType, vector<int> &data)
{
	//set up clock variables
    std::chrono::time_point<std::chrono::system_clock> start_time, end_time;
	start_time = std::chrono::system_clock::now();    // Grab starting time

	switch(sortType)
	{
		case doMergeSort : executeMergeSort(data); 			break;
		case doInsertionSort : executeInsertionSort(data);	break;
		case doBubbleSort : executeBubbleSort(data);		break;
	}

	end_time = std::chrono::system_clock::now();          // Grab end time

	return std::chrono::duration<double>(end_time - start_time);
}

/******************************************************************************/
int main(int argc, char *argv[])
{
	//generate large list of number
    srand(time(NULL));
	vector<int> merge_vector{};
	vector<int> insertion_vector{};
	vector<int> bubble_vector{};

	int curr_num = 0;
	for (int i = 0; i < 10000; i++)	//Creating 3 copies of the random series
	{
		curr_num = rand() % 100000;
		merge_vector.push_back(curr_num);
		insertion_vector.push_back(curr_num);
		bubble_vector.push_back(curr_num);
	}

	cout << " [x] Starting sorts and tests " << endl;
	cout << " *********************************************" << endl;

	cout << " [x] Merge sort time: "
		 << do_Benchmark(doMergeSort, merge_vector).count() << " secs" << endl;

	cout << " [x] Insertion sort time: "
		 << do_Benchmark(doInsertionSort, insertion_vector).count() << " secs" << endl;

	cout << " [x] Bubble sort time: "
		 << do_Benchmark(doBubbleSort, bubble_vector).count() << " secs" << endl;

	cout << " *********************************************" << endl;
	cout << " [x] Resulting sorted array samples: " << endl;
	cout << " [x] Merge: " ; showFirstNElements(merge_vector, 10);
	cout << " [x] Inser: " ; showFirstNElements(insertion_vector, 10);
	cout << " [x] Bubbl: " ; showFirstNElements(bubble_vector, 10);
	cout << " *********************************************" << endl;
	cout << " [x] Correct results? " << endl;
	if(are_VectorsIdentical(bubble_vector, merge_vector))
		cout << " [x] Merge Sort is: CORRECT " << endl;
	else
		cout << " [!] Merge Sort is: WRONG " << endl;

	if(are_VectorsIdentical(bubble_vector, insertion_vector))
		cout << " [x] Insertion Sort is: CORRECT " << endl;
	else
		cout << " [!] Insertion Sort is: WRONG " << endl;

	if(are_VectorsIdentical(bubble_vector, bubble_vector))
		cout << " [x] Bubble Sort is: CORRECT " << endl;
	else
		cout << " [!] Bubble Sort is: WRONG " << endl;


}
