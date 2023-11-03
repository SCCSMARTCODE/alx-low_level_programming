#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table.
 * @key: The key (must not be an empty string).
 * @value: The value associated with the key (must be duplicated).
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int the_key_index;
	hash_node_t *new_node, *current;

	/* Check for valid input */
	if (!ht || !key || strlen(key) == 0)
	{
		/* Return failure if invalid input */
		return (0);
	}

	/* Calculate the index for the key */
	the_key_index = key_index((unsigned char *)key, ht->size);
	current = ht->array[the_key_index];

	while (current != NULL)
	{
		/* If the key already exists, update its value */
		if (strcmp(current->key, key) == 0)
		{
			free(current->value); /* Free the old value */
			current->value = strdup(value); /* Duplicate and set the new value */
			return (1);
		}
		current = current->next;
	}

	/* If the key doesn't exist, create a new node */
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		/* Return failure if memory allocation fails */
		return (0);
	}

	new_node->key = strdup(key); /* Duplicate and set the new key */
	new_node->value = strdup(value); /* Duplicate and set the new value */
	new_node->next = ht->array[the_key_index];
	ht->array[the_key_index] = new_node;

	return (1);
}
