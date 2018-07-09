#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
Date Created: September 21, 2016
Date Last Modified: September 22, 2016
Description: Holds all the definitions of functions
*/

void bubblesort(vector<int> &arr, int n); // without checking time
void bubblesortBackward (vector<int> &arr, int n); // reverses the list
int getRandom();
float do_bubblesort(vector<int> &arr, int n); // keeps track of the time
float averageCase(vector<int> &arr, int n);
float bestCase(vector<int> &arr, int n);
float worseCase(vector<int> &arr, int n);
void bubblesortWrapper(); //puts everything together
