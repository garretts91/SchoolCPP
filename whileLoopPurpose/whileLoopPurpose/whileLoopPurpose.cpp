// Given the following code, explain the purpose of the while loop
// and it's contents in insertionSort

#include <iostream>

void insertionSort(int arr[], int size)
{
	int i, j, key;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		//The while loop is sorting the numbers in the numbers array to determine if the number is positive (greater than zero) AND
		//If the element of the array is greater than the index at the "key" value, 
		//If the element is greater at position 'j' than the "key", then position 'j' is inserted into that position. 
		//If the current index is compared with the elements adjacent to it, 
		//it decides whether or not to insert that specific value at that index in order to sort the integers in ascending order.
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << '\n';
}

int main()
{
	int numbers[] = { 9, 0, 5, 3, 8, 1, 4, 6, 7, 10, 2, 11, 12, 15, 14, 13 };
	int size = sizeof(numbers) / sizeof(numbers[0]);
	insertionSort(numbers, size);
	print(numbers, size);
}