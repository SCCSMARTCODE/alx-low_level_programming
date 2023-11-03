#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table
 *
 * @size: is the size of the array
 * Return: Returns a pointer to the newly created hash table or NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;

	if (size == 0)
		return (NULL);

	new_table = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (new_table == NULL)
		return (NULL);
	new_table->size = size;
	new_table->array = calloc(sizeof(hash_node_t *), size);
	if (new_table->array == NULL)
		return (NULL);
	return (new_table);
}
