#include "huffman.h"

/**
* symbol_create - creates a symbol_t structure
* @data: the data to store
* @freq: the frequency of data
* Return: pointer to new symbol_t or NULL
*/
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *symbol = malloc(sizeof(symbol_t));

	if (!symbol)
		return (NULL);

	symbol->data = data;
	symbol->freq = freq;

	return (symbol);
}
