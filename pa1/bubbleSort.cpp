#include "bubbleSort.h"

/*
Date Created: September 23, 2016
Description: Sorts the list in ascending order.
*/

void bubblesort(vector<int> &arr, int n)
{
	int i = 0, j = 0, temp = 0; //holding variable

        for (i = 0; i < n; ++i)
        {
                for (j = 0; j < n - i - 1; ++j)
                {
                        if (arr[j] > arr[j+1]) //ascending order
                        {
				//swapping happens here
                                temp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = temp;
                        }
                }
	}
}

/*
Date Created: September 23, 2016
Description: Sorts the list in descending order.
*/

void bubblesortBackward (vector<int> &arr, int n)
{
	int i = 0, j = 0, temp = 0; //holding variable

        for (i = 0; i < n; ++i)
        {
                for (j = 0; j < n - i - 1; ++j)
                {
                        if (arr[j] < arr[j+1]) //descending order
                        {
                                //swapping happens here
                                temp = arr[j];
				arr[j] = arr[j+1];
                                arr[j+1] = temp;
                        }
                }
        }

}

/*
Date Created: September 22, 2016
Date Last Modified: September 23, 2016
Description: Ramdomized numbers are generated so it can populate the vector
	     with random numbers.
*/

int getRandom()
{
	return rand();
}

/*
Date Created: September 22, 2016
Date Last Modified: September 23, 2016
Description: Runs bubblesort and it keeps track of the time and returns the
	     elapsed time of the program.
*/

float do_bubblesort(vector<int> &arr, int n)
{
	float time = 0.0;
	int i = 0, j = 0, temp = 0; //holding variable

	//allows the program to keep time
	chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now(); // start time before program

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	end = chrono::system_clock::now(); //end time
	chrono::duration<float> time_e = end - start; //elapsed time
	time = time_e.count(); // converts to a float

	return time;
}

/*
Date Created: September 23, 2016
Description: runs the average case which runs bubbersort with random integers
*/

float averageCase(vector<int> &arr, int n)
{
	float time;

	time = do_bubblesort(arr, n);

	return time;
}

/*
Date Created: September 23, 2016
Description: Runs the best case which means it runs bubblesort when the list
	     is already sorted.
*/

float bestCase(vector<int> &arr, int n)
{
	float time;

	// sorts the list before
	bubblesort(arr, n);
	// passing already sorted list
	time = do_bubblesort(arr, n);

	return time;
}

/*
Date Created: September 23, 2016
Description: Runs the worse case senrio where the list is backwards.
*/

float worseCase(vector<int> &arr, int n)
{
	float time;

	// sorts the list in reverse order
	bubblesortBackward(arr, n);
	// passing in reversed list
	time = do_bubblesort(arr, n);

	return time;
}

/*
Date Created: September 23, 2016
Description: Puts everything together.
*/

void bubblesortWrapper()
{
	srand(time(0));

	// Size 10
	vector<int> best(10, 0);
	vector<float> bestCase_time(5, 0);
	generate(best.begin(), best.end(), getRandom);

	vector<int> worse(10, 0);
	vector<float> worseCase_time(5, 0);
	generate(worse.begin(), worse.end(), getRandom);

	vector<int> average(10, 0);
	vector<float> averageCase_time(5, 0);
	generate(average.begin(), average.end(), getRandom);

	//Size 50
	vector<int> _50_best(50, 0);
        vector<float> _50_bestCase_time(5, 0);
        generate(_50_best.begin(), _50_best.end(), getRandom);

        vector<int> _50_worse(50, 0);
        vector<float> _50_worseCase_time(5, 0);
        generate(_50_worse.begin(), _50_worse.end(), getRandom);

        vector<int> _50_average(50, 0);
        vector<float> _50_averageCase_time(5, 0);
        generate(_50_average.begin(), _50_average.end(), getRandom);

	// Size 100
	vector<int> _100_best(100, 0);
        vector<float> _100_bestCase_time(5, 0);
        generate(_100_best.begin(), _100_best.end(), getRandom);

        vector<int> _100_worse(100, 0);
        vector<float> _100_worseCase_time(5, 0);
        generate(_100_worse.begin(), _100_worse.end(), getRandom);

        vector<int> _100_average(100, 0);
        vector<float> _100_averageCase_time(5, 0);
        generate(_100_average.begin(), _100_average.end(), getRandom);

	//Size 500
	vector<int> _500_best(500, 0);
        vector<float> _500_bestCase_time(5, 0);
        generate(_500_best.begin(), _500_best.end(), getRandom);

        vector<int> _500_worse(500, 0);
        vector<float> _500_worseCase_time(5, 0);
        generate(_500_worse.begin(), _500_worse.end(), getRandom);

        vector<int> _500_average(500, 0);
        vector<float> _500_averageCase_time(5, 0);
        generate(_500_average.begin(), _500_average.end(), getRandom);

	//Size 1000
	vector<int> _1000_best(1000, 0);
        vector<float> _1000_bestCase_time(5, 0);
        generate(_1000_best.begin(), _1000_best.end(), getRandom);

        vector<int> _1000_worse(1000, 0);
        vector<float> _1000_worseCase_time(5, 0);
        generate(_1000_worse.begin(), _1000_worse.end(), getRandom);

        vector<int> _1000_average(1000, 0);
        vector<float> _1000_averageCase_time(5, 0);
        generate(_1000_average.begin(), _1000_average.end(), getRandom);

	//Size 5000
	vector<int> _5000_best(5000, 0);
        vector<float> _5000_bestCase_time(5, 0);
        generate(_5000_best.begin(), _5000_best.end(), getRandom);

        vector<int> _5000_worse(5000, 0);
        vector<float> _5000_worseCase_time(5, 0);
        generate(_5000_worse.begin(), _5000_worse.end(), getRandom);

        vector<int> _5000_average(5000, 0);
        vector<float> _5000_averageCase_time(5, 0);
        generate(_5000_average.begin(), _5000_average.end(), getRandom);

	//Size 10000
	vector<int> _10000_best(10000, 0);
        vector<float> _10000_bestCase_time(5, 0);
        generate(_10000_best.begin(), _10000_best.end(), getRandom);

        vector<int> _10000_worse(10000, 0);
        vector<float> _10000_worseCase_time(5, 0);
        generate(_10000_worse.begin(), _10000_worse.end(), getRandom);

        vector<int> _10000_average(10000, 0);
        vector<float> _10000_averageCase_time(5, 0);
        generate(_10000_average.begin(), _10000_average.end(), getRandom);

	// Size 50000
	vector<int> _50000_best(50000, 0);
        vector<float> _50000_bestCase_time(5, 0);
        generate(_50000_best.begin(), _50000_best.end(), getRandom);

        vector<int> _50000_worse(50000, 0);
        vector<float> _50000_worseCase_time(5, 0);
        generate(_50000_worse.begin(), _50000_worse.end(), getRandom);

        vector<int> _50000_average(50000, 0);
        vector<float> _50000_averageCase_time(5, 0);
        generate(_50000_average.begin(), _50000_average.end(), getRandom);


	for(int i = 0; i < 5; i++)
	{
		// Size 10
		bestCase_time[i] = bestCase(best, 10);
		worseCase_time[i] = worseCase(worse, 10);
		averageCase_time[i] = averageCase(average, 10);

		 // Size 50
                _50_bestCase_time[i] = bestCase(_50_best, 50);
                _50_worseCase_time[i] = worseCase(_50_worse, 50);
                _50_averageCase_time[i] = averageCase(_50_average, 50);

		//Size 100
		_100_bestCase_time[i] = bestCase(_100_best, 100);
                _100_worseCase_time[i] = worseCase(_100_worse, 100);
                _100_averageCase_time[i] = averageCase(_100_average, 100);

		//Size 500
		_500_bestCase_time[i] = bestCase(_500_best, 500);
                _500_worseCase_time[i] = worseCase(_500_worse, 500);
                _500_averageCase_time[i] = averageCase(_500_average, 500);

		//Size 1000
		_1000_bestCase_time[i] = bestCase(_1000_best, 1000);
                _1000_worseCase_time[i] = worseCase(_1000_worse, 1000);
                _1000_averageCase_time[i] = averageCase(_1000_average, 1000);

		//Size 5000
		_5000_bestCase_time[i] = bestCase(_5000_best, 5000);
                _5000_worseCase_time[i] = worseCase(_5000_worse, 5000);
                _5000_averageCase_time[i] = averageCase(_5000_average, 5000);

		//Size 10000
		_10000_bestCase_time[i] = bestCase(_10000_best, 10000);
                _10000_worseCase_time[i] = worseCase(_10000_worse, 10000);
                _10000_averageCase_time[i] = averageCase(_10000_average, 10000);

		//Size 50000
		_50000_bestCase_time[i] = bestCase(_50000_best, 50000);
                _50000_worseCase_time[i] = worseCase(_50000_worse, 50000);
                _50000_averageCase_time[i] = averageCase(_50000_average, 50000);
	}


	// Size 10
	float sum_best = 0, sum_worst = 0, sum_average = 0;

	//Size 50
	float _50_sum_best = 0, _50_sum_worst = 0, _50_sum_average = 0;

	//Size 100
	float _100_sum_best = 0, _100_sum_worst = 0, _100_sum_average = 0;

	//Size 500
	float _500_sum_best = 0, _500_sum_worst = 0, _500_sum_average = 0;

	//Size 1000
	float _1000_sum_best = 0, _1000_sum_worst = 0, _1000_sum_average = 0;

	//Size 5000
	float _5000_sum_best = 0, _5000_sum_worst = 0, _5000_sum_average = 0;

	//Size 10000
	float _10000_sum_best = 0, _10000_sum_worst = 0, _10000_sum_average = 0;

	//Size 50000
	float _50000_sum_best = 0, _50000_sum_worst = 0, _50000_sum_average = 0;

	for(int i = 0; i < 5; i++)
	{
		// Size 10
		sum_best = sum_best + bestCase_time[i];
		sum_worst = sum_worst + worseCase_time[i];
		sum_average = sum_average + averageCase_time[i];

		//Size 50
                _50_sum_best = _50_sum_best + _50_bestCase_time[i];
                _50_sum_worst = _50_sum_worst + _50_worseCase_time[i];
                _50_sum_average = _50_sum_average + _50_averageCase_time[i];

		//Size 100
		_100_sum_best = _100_sum_best + _100_bestCase_time[i];
                _100_sum_worst = _100_sum_worst + _100_worseCase_time[i];
                _100_sum_average = _100_sum_average + _100_averageCase_time[i];

		//Size 500
		_500_sum_best = _500_sum_best + _500_bestCase_time[i];
                _500_sum_worst = _500_sum_worst + _500_worseCase_time[i];
                _500_sum_average = _500_sum_average + _500_averageCase_time[i];

		//Size 1000
		_1000_sum_best = _1000_sum_best + _1000_bestCase_time[i];
                _1000_sum_worst = _1000_sum_worst + _1000_worseCase_time[i];
                _1000_sum_average = _1000_sum_average + _1000_averageCase_time[i];

		//Size 5000
		_5000_sum_best = _5000_sum_best + _5000_bestCase_time[i];
                _5000_sum_worst = _5000_sum_worst + _5000_worseCase_time[i];
                _5000_sum_average = _5000_sum_average + _5000_averageCase_time[i];

		//Size 10000
		_10000_sum_best = _10000_sum_best + _10000_bestCase_time[i];
                _10000_sum_worst = _10000_sum_worst + _10000_worseCase_time[i];
                _10000_sum_average = _10000_sum_average + _10000_averageCase_time[i];

		//Size 50000
		_50000_sum_best = _50000_sum_best + _50000_bestCase_time[i];
                _50000_sum_worst = _50000_sum_worst + _50000_worseCase_time[i];
                _50000_sum_average = _50000_sum_average + _50000_averageCase_time[i];
	}

	//Size 10
	float ave_best = 0, ave_worst = 0, ave_average = 0;
	ave_best = sum_best / 5.0;
	ave_worst = sum_worst / 5.0;
	ave_average = sum_average / 5.0;

	//Size 50
	float _50_ave_best = 0, _50_ave_worst = 0, _50_ave_average = 0;
        _50_ave_best = _50_sum_best / 5.0;
        _50_ave_worst = _50_sum_worst / 5.0;
        _50_ave_average = _50_sum_average / 5.0;

	//Size 100
	float _100_ave_best = 0, _100_ave_worst = 0, _100_ave_average = 0;
        _100_ave_best = _100_sum_best / 5.0;
        _100_ave_worst = _100_sum_worst / 5.0;
        _100_ave_average = _100_sum_average / 5.0;

	//Size 500
	float _500_ave_best = 0, _500_ave_worst = 0, _500_ave_average = 0;
        _500_ave_best = _500_sum_best / 5.0;
        _500_ave_worst = _500_sum_worst / 5.0;
        _500_ave_average = _500_sum_average / 5.0;

	//Size 1000
	float _1000_ave_best = 0, _1000_ave_worst = 0, _1000_ave_average = 0;
        _1000_ave_best = _1000_sum_best / 5.0;
        _1000_ave_worst = _1000_sum_worst / 5.0;
        _1000_ave_average = _1000_sum_average / 5.0;

	//Size 5000
	float _5000_ave_best = 0, _5000_ave_worst = 0, _5000_ave_average = 0;
        _5000_ave_best = _5000_sum_best / 5.0;
        _5000_ave_worst = _5000_sum_worst / 5.0;
        _5000_ave_average = _5000_sum_average / 5.0;

	//Size 10000
	float _10000_ave_best = 0, _10000_ave_worst = 0, _10000_ave_average = 0;
        _10000_ave_best = _10000_sum_best / 5.0;
        _10000_ave_worst = _10000_sum_worst / 5.0;
        _10000_ave_average = _10000_sum_average / 5.0;

	//Size 50000
	float _50000_ave_best = 0, _50000_ave_worst = 0, _50000_ave_average = 0;
        _50000_ave_best = _50000_sum_best / 5.0;
        _50000_ave_worst = _50000_sum_worst / 5.0;
        _50000_ave_average = _50000_sum_average / 5.0;

	//print to a csv file
	ofstream file1;
	file1.open("BSStats.csv");

	file1 << "N Size, Optimal time, Worst case time, Average sort time, ";
	for (int i = 0; i < 5; i++)
	{
		file1 << "Run #" << i+1 << ",";
	}
	file1 << endl;

	// Size 10
	file1 << "10" << ",";
	file1 << ave_best << ",";
	file1 << ave_worst << ",";
	file1 << ave_average << ",";

	for(int i = 0; i < 5; i++)
	{
		file1 << averageCase_time[i] << ",";
	}
	file1 << endl;

	// Size 50
	file1 << "50" << ",";
        file1 << _50_ave_best << ",";
        file1 << _50_ave_worst << ",";
        file1 << _50_ave_average << ",";

        for(int i = 0; i < 5; i++)
        {
                file1 << _50_averageCase_time[i] << ",";
        }
	file1 << endl;

	// Size 100
	file1 << "100" << ",";
        file1 << _100_ave_best << ",";
        file1 << _100_ave_worst << ",";
        file1 << _100_ave_average << ",";

        for(int i = 0; i < 5; i++)
        {
                file1 << _100_averageCase_time[i] << ",";
        }
        file1 << endl;

	//Size 500
	file1 << "500" << ",";
        file1 << _500_ave_best << ",";
        file1 << _500_ave_worst << ",";
        file1 << _500_ave_average << ",";

        for(int i = 0; i < 5; i++)
        {
                file1 << _500_averageCase_time[i] << ",";
        }
        file1 << endl;

	//Size 1000
	file1 << "1000" << ",";
        file1 << _1000_ave_best << ",";
        file1 << _1000_ave_worst << ",";
        file1 << _1000_ave_average << ",";

        for(int i = 0; i < 5; i++)
        {
                file1 << _1000_averageCase_time[i] << ",";
        }
        file1 << endl;

	//Size 5000
	file1 << "5000" << ",";
        file1 << _5000_ave_best << ",";
        file1 << _5000_ave_worst << ",";
        file1 << _5000_ave_average << ",";

        for(int i = 0; i < 5; i++)
        {
                file1 << _5000_averageCase_time[i] << ",";
        }
        file1 << endl;

	//Size 10000
	file1 << "10000" << ",";
        file1 << _10000_ave_best << ",";
        file1 << _10000_ave_worst << ",";
        file1 << _10000_ave_average << ",";

        for(int i = 0; i < 5; i++)
        {
                file1 << _10000_averageCase_time[i] << ",";
        }
        file1 << endl;

	//Size 50000
	file1 << "50000" << ",";
        file1 << _50000_ave_best << ",";
        file1 << _50000_ave_worst << ",";
        file1 << _50000_ave_average << ",";

        for(int i = 0; i < 5; i++)
        {
                file1 << _50000_averageCase_time[i] << ",";
        }
        file1 << endl;

}

