#include "sort.h"

/**
 * swap - The positions of two elements
 * @array: array
 * @a: input1
 * @b: input2
 * Return: void
 */
void swap(int *array, ssize_t a, ssize_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

/**
 * hoare_partition - hoare partition sorting scheme implementation
 * @array: array
 * @low: low array element
 * @high: high array element
 * @size: size array element
 * Return: return the position of the element sorted
 */
int hoare_partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int current = low - 1, first = high + 1;

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);
		do {
			first--;
		} while (array[first] > pivot);
		if (current >= first)
			return (current);
		swap(array, current, first);
		print_array(array, size);
	}
}

/**
 * qs - quick sort algorithm implementation
 * @array: array
 * @low: low array element
 * @high: high array element
 * @size: size array
 * Return: void
 */
void qs(int *array, ssize_t low, ssize_t high, ssize_t size)
{
	ssize_t position_index = 0;

	if (low < high)
	{
		position_index = hoare_partition(array, low, high, size);
		if (position_index > 0)
		{
			qs(array, low, position_index - 1, size);
		}
		qs(array, position_index, high, size);
	}
}

/**
 * quick_sort_hoare - that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array
 * @size: size array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
