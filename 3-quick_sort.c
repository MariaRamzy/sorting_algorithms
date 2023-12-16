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
 * lomuto_partition - lomuto partition sorting scheme implementation
 * @array: array
 * @low: low array element
 * @high: high array element
 * @size: size array
 * Return: return the position of the element sorted
 */
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, ssize_t size)
{
	int pivot = array[high];
	ssize_t current = low, last;

	for (last = low; last < high; last++)
	{
		if (array[last] < pivot)
		{
			if (array[current] != array[last])
			{
				swap(array, current, last);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[high])
	{
		swap(array, current, high);
		print_array(array, size);
	}
	return (current);
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
		position_index = lomuto_partition(array, low, high, size);
		if (position_index > 0)
		{
			qs(array, low, position_index - 1, size);
		}
		qs(array, position_index + 1, high, size);
	}
}

/**
 * quick_sort - that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array
 * @size: size array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
