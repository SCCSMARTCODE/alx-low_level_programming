#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a 2D grid created by alloc_grid
 * @grid: Pointer to the 2D grid
 * @height: The height of the grid
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
	return;

	for (i = 0; i < height; i++)
	{
	free(grid[i]);
	}

	free(grid);
}
