/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:41:50 by mhuszar           #+#    #+#             */
/*   Updated: 2023/11/12 14:15:20 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wordle.h"

int	read_data(t_keyvalue **hashtable, int fd)
{
	char	*line;
	char	*key;
	char	*value;

	line = get_next_line(fd);
	while (line)
	{
		key = line;
		value = line;
		if (line)
		{
			if (!store_data(hashtable, key, value))
				return (0);
			line = get_next_line(fd);
		}
	}
	return (1);
}

int	store_data(t_keyvalue **hashtable, char *key, char *val)
{
	t_keyvalue	*newkeyval;
	size_t		index;

	newkeyval = (t_keyvalue *)malloc(sizeof(t_keyvalue));
	if (newkeyval == NULL)
		return (0);
	newkeyval->key = key;
	newkeyval->val = val;
	newkeyval->hash2 = get_hash2(key);
	index = get_hash(key);
	newkeyval->next = hashtable[index];
	hashtable[index] = newkeyval;
	return (1);
}

int	search_input(t_keyvalue **hashtable, char *search_key)
{
	size_t		index;
	t_keyvalue	*current;

	index = get_hash(search_key);
	current = hashtable[index];
	while (current != NULL)
	{
		if (current->hash2 == get_hash2(search_key))
		{
			return (1);
		}
		current = current->next;
	}
	return (0);
}

char	*ft_tolower(char *str)
{
	int counter = 0;
	while (str[counter])
	{
		if (str[counter] >= 'A' && str[counter] <= 'Z')
			str[counter] = str[counter] + 32;
		counter++;
	}
	return (str);
}

int random_number(int x)
{
    srand(time(NULL));
    return (rand() % x);
}

char	*find_target(t_keyvalue **hashtable)
{
	int			index; 
	t_keyvalue	*current = NULL;
	int			list_size;
	int			target_index;
	char		*target;

	while (!current)
	{
		index = random_number(HASHTABLE_SIZE);
		current = hashtable[index];
	}
	list_size = ft_lstsize(current);
	target_index = random_number(list_size);
	while (target_index)
	{
		current = current->next;
		target_index--;
	}
	target = current->key;
	return (target);
}
