#include <stdlib.h>
#include <stdio.h>

/**
 * custom_print_array - Display an integer array
 *
 * @arr: The array to be displayed
 * @len: Number of elements in @arr
 */
void print_array(const int *arr, size_t len)
{
	size_t index;

	index = 0;
	while (arr && index < len)
	{
		if (index > 0)
		printf(", ");
		printf("%d", arr[index]);
		++index;
	}
	printf("\n");
}

