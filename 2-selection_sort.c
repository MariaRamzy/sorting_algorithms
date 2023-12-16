#include "sort.h"

/**
 * selection_sort - that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: list with number
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int index, tmp, swap = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		index = i;
		swap = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[index] > array[j])
			{
				index = j;
				swap += 1;
			}
		}
		tmp = array[i];
		array[i] = array[index];
		array[index] = tmp;
		if (swap != 0)
			print_array(array, size);
	}
}
