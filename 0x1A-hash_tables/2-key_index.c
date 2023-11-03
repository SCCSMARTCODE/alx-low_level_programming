#include "hash_tables.h"

/**
 * key_index - gives you the index of a key
 * @key: the key
 * @size: array size of the hash tabls
 *
 * Return:  index at which the key/value pair
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_val, hash_val_size;

	hash_val = hash_djb2(key);
	hash_val_size = hash_val % size;

	return (hash_val_size);
}
