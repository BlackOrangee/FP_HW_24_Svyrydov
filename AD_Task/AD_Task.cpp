// AD Task. Write a program that removes empty rows from a two-dimensional array
//

#include <iostream>
using namespace std;

char** GenerateArray(int& size);
void PrintArray(char** arr, int& size);
char** EmptyRowsRemover(char** str, int& size);

int main()
{
	printf("\n\n\tEnter strings number ");
	int size;
	cin >> size;

	char** str = GenerateArray(size);

	printf("\n\n\tEntered string: \n");
	PrintArray(str, size);

	char** str_new = EmptyRowsRemover(str, size);

	printf("\n\n\tCorrected string: \n");
	PrintArray(str_new, size);
}

char** GenerateArray(int& size)//Generate array
{
	char** str = new char* [size];
	for (int i = 0; i < size; i++)
	{
		int str_size = 10;
		str[i] = new char[str_size];
		
		cout << "\n\tEnter string, use '0' to skip\n\t";	cin >> str[i];
	}
	return str;
}

void PrintArray(char** arr, int& size)//Print array
{
	for (int i = 0; i < size; i++)
	{
		cout << "\t" << arr[i] << "\n";
	}
}

char** EmptyRowsRemover(char** str, int& size)
{
	int size_new = 0;

	for (int i = 0; i < size; i++)
	{
		if (str[i][0] != '0')
		{
			size_new++;
		}
	}
	char** str_new = new char* [size_new];

	for (int i = 0; i < size - 1; i++)
	{
		if (str[i][0] == '0')
		{
			swap(str[i], str[i + 1]);
		}
	}
	for (int i = 0; i < size_new; i++)
	{
		str_new[i] = str[i];
	}
	size = size_new;
	delete[] str;
	return str_new;
}