#include "sort.h"

/**
 * swap - swap two integers in an array.
 * @a: first int.
 * @b: second int.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array.
 * @size: array size.
 * Return: void.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;
	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0, i < j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + 1, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		j--;
	}
}
