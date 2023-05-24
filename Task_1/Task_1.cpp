// Write a function to convert a one-dimensional int array to a two-dimensional array. 
// The number that is contained in the one-dimensional array should be replaced by a pointer, 
// and the array to which it will point will have the size of the number that was contained in the original array. 
// The two-dimensional array must be of char/string type and filled with stars.
// Input array: 1542
// Output:
// *
// *****
// ****
// **
//

#include <iostream>
using namespace std;

string* Star(int* arr, int& size);
void Print(string* m_str, int& size);

int main()
{

	int arr[] = { 1, 5, 4, 2 };
	int size = sizeof(arr) / 4;

	string* m_str = Star(arr, size);
	Print(m_str, size);
}

string* Star(int* arr, int& size) //Create string with stars, from input array
{
	string* m_str = new string[size];
	string star = "*";

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			m_str[i] += star;
		}
	}
	return m_str;
}

void Print(string* m_str, int& size)//Print func
{
	for (int i = 0; i < size; i++)
	{
		cout << m_str[i] << endl;
	}
}
