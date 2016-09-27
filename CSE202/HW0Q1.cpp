#include<iostream>
#include<time.h>
#include<windows.h>
auto const n = 10000;
int A[n];

/* function main generates the A array */
auto generate(int max_value) 
{
	srand(time(0));
	for (auto i = 0; i < n; i++) 
	{
		/* pick random number from 1 to max and put it on A[] */
		A[i] = 1 + (rand() % max_value);
		//A[i] = n-i;
		//printf("%d\n", A[i]);
	} /* end for */
	return 0; /* indicates successful termination */
}

auto methode1()
{
	auto max = 0;

	for (auto i = 0; i < n; i++)
		for (auto j = i + 1; j < n; j++)
			max = (A[i] - A[j]) > max ? A[i] - A[j] : max;
	return max;
}

int methode2()
{
	auto dif = 0;
	auto max = 0;
	int mins[n]; // to contain minimum values throughout the array
	mins[n - 1] = A[n - 1];
// find the minimum at each point of the array moving from element n to 1
	for (auto j = n - 2; j >= 0; j--)
		mins[j] = mins[j + 1] > A[j] ? A[j] : mins[j + 1];
//
	for (auto i = 0; i < n; i++)
		max = (A[i] - mins[i]) > max ? A[i] - mins[i] : max;
	return max;
}

int main()
{
	auto max_value = 100000;
	auto range_limit = 0;
	srand(time(0));
	
	for (auto i = 1; i < 100; i++)
	{
		range_limit = rand() % max_value;
		Sleep(500);
		srand(time(NULL));
		generate(range_limit);
		printf("%d\t%d\t%d\n", i,methode1(),methode2());
	}
	system("PAUSE");
	return 0;
}