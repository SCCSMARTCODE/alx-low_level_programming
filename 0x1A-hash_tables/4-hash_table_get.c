#include "hash_tables.h"

/**
 * hash_table_get - gets an element in the hash table.
 * @ht: The hash table.
 * @key: The key
 * Return:  the value associated with the element, or NULL if key is not found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int key_index_val;
	hash_node_t *locate;

	if (ht == NULL)
		return (NULL);

	key_index_val = key_index((unsigned char *)key, ht->size);
	locate = ht->array[key_index_val];

	while (locate != NULL)
	{
		if (strcmp(locate->key, key) == 0)
		{
			return (locate->value);
		}
		locate = locate->next;
	}
	return (NULL);

}
