// AD Task. Write a program that removes empty rows from a two-dimensional array
//

#include <iostream>
using namespace std;

void GenerateArray(int** arr, int& size);
void PrintArray(int** arr, int& size);
int** EmptyRowsRemover(int** arr, int* size)
{
	int size2 = *size;
	int** arr_new = new int* [size2];
	int k = 0;

	for (int i = 0; i < size2 - 1; i++)
	{
		for (int j = 0; j < arr[i][0]; j++)
		{
			if (arr[i][0] == 0)
			{
				k++;
				size2--;
			}
			else
			{
				arr_new[i] = new int[arr[i + k][0]];
				arr_new[i][0] = arr[i + k][0];
				arr_new[i][j] == arr[i + k][j];
			}

		}
	}
	delete arr;
	*size = size2;
	return arr_new;
}


int main()
{
	srand(time(NULL));

	printf("\n\n\tEnter strings number ");
	int size;
	cin >> size;

	int** arr = new int* [size];

	GenerateArray(arr, size);

	printf("\n\n\tArray: \n");
	PrintArray(arr, size);

	int** arr_new = EmptyRowsRemover(arr, &size);

	printf("\n\n\tArray: \n");
	PrintArray(arr_new, size);
}

void GenerateArray(int** arr, int& size)//Generate array
{

	for (int i = 0; i < size; i++)
	{
		printf("\tEnter string %d size ", i + 1);
		int str_size = 0;
		cin >> str_size;

		str_size++;
		arr[i] = new int[str_size];
		arr[i][0] = str_size;

		for (int j = 1; j < str_size; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
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
