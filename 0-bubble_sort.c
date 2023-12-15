#include "sort.h"

/**
 * swap_ints - swap two integers in an array.
 * @a: first int.
 * @b: second int.
 */
void swap_ints(int *a, int *b)
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
	size_t i, j;
	int tmp;

	for (i = 0; i < size; i++)
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(&array[j], &array[j + 1]);
				tm = 1;
				print_array(array, size);
			}
		}
		if (tmp == 0)
		{
			break;
		}
}
