/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_hashing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:42:56 by mhuszar           #+#    #+#             */
/*   Updated: 2023/11/12 19:06:13 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

size_t	get_hash(char *keyvalue)
{
	size_t	hash;
	size_t	counter;

	if (keyvalue == NULL)
		return (0);
	hash = 0;
	counter = 0;
	while (keyvalue[counter] != '\n')
	{
		hash = (hash * 31 + keyvalue[counter]) % HASHTABLE_SIZE;
		counter++;
	}
	return (hash);
}

size_t	get_hash2(char *keyvalue)
{
	size_t	hash;
	size_t	counter;

	if (keyvalue == NULL)
		return (0);
	hash = 0;
	counter = 0;
	while (keyvalue[counter] != '\n')
	{
		hash = (hash * 17 + counter + keyvalue[counter]);
		counter++;
	}
	return (hash);
}

void	free_list(t_keyvalue *list)
{
	t_keyvalue	*current;
	t_keyvalue	*next;

	current = list;
	while (current != NULL)
	{
		next = current->next;
		if (current->key)
			free(current->key);
		//if (current->val)
			//free(current->val);
		free(current);
		current = next;
	}
}

void	free_everything(t_keyvalue **hashtable)
{
	int	i;

	i = 0;
	while (i < HASHTABLE_SIZE)
	{
		if (hashtable[i] != NULL)
			free_list(hashtable[i]);
		i++;
	}
	free(hashtable);
}

void	free_input(char **arr, int i)
{
	int	counter;

	counter = 0;
	while (counter <= i)
	{
		free(arr[counter]);
		counter++;
	}
	free(arr);
}
