// Task 2. Write a program that element-by-element sums two dynamic two-dimensional arrays 
// filled with random numbers and stores the result in the third array. 
// The sizes of the output arrays are set by the user
//

#include <iostream>
using namespace std;

int** ArrSum(int** arr1, int** arr2, int& size);
void PrintArray(int** arr, int& size);

int main()
{
	srand(time(NULL));

	printf("\n\n\tEnter strings number ");
	int size;
	cin >> size;

	int** arr1 = new int* [size];
	int** arr2 = new int* [size];
	
	int** arr_sum = ArrSum(arr1, arr2, size);

	printf("\n\n\tFirst array: \n");
	PrintArray(arr1, size);

	printf("\n\n\tSecond array: \n");
	PrintArray(arr2, size);

	printf("\n\n\tArray sum: \n");
	PrintArray(arr_sum, size);
}

int** ArrSum(int** arr1, int** arr2, int& size)//Generate and add arrays
{
	int** arr_sum = new int* [size];

	for (int i = 0; i < size; i++)
	{
		printf("\tEnter string %d size ", i + 1);
		int str_size = 0;
		cin >> str_size;

		str_size++;
		arr1[i] = new int[str_size];
		arr2[i] = new int[str_size];
		arr_sum[i] = new int[str_size];

		arr1[i][0] = str_size;
		arr2[i][0] = str_size;
		arr_sum[i][0] = str_size;

		for (int j = 1; j < str_size; j++)
		{
			arr1[i][j] = rand() % 10;
			arr2[i][j] = rand() % 10;

			arr_sum[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	return arr_sum;
}

void PrintArray(int** arr, int& size)//Print array
{
	for (int i = 0; i < size; i++)
	{
		cout << "\t";
		for (int j = 1; j < arr[i][0]; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}