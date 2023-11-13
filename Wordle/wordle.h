/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:44:03 by mhuszar           #+#    #+#             */
/*   Updated: 2023/11/12 16:34:43 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>


# ifndef HASHTABLE_SIZE
#  define HASHTABLE_SIZE 3000
# endif

typedef struct s_keyvalue
{
	char				*key;
	char				*val;
	size_t				hash2;
	struct s_keyvalue	*next;
}				t_keyvalue;

size_t	get_hash(char *keyvalue);
size_t	get_hash2(char *keyvalue);
int		read_data(t_keyvalue **hashtable, int fd);
int		store_data(t_keyvalue **hashtable, char *key, char *val);
void	free_everything(t_keyvalue **hashtable);
char	*find_target(t_keyvalue **hashtable);
char	*ft_tolower(char *str);
int		search_input(t_keyvalue **hashtable, char *search_key);
void	free_input(char **arr, int i);


// GET_NEXT_LINE:
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 65
# endif
# define MAX_FDS 256

typedef struct s_buffer
{
	char	*cont;
	ssize_t	len;
	ssize_t	last_read;
}				t_buffer;

char	*get_next_line(int fd);
void	free_and_null(void **ptr);
void	*ft_memmove(void *dest, const void *src, size_t n);

// Helper functions (from libft):
// add prototypes...
size_t	ft_strlen(const char	*s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strdup_nonl(const char *s);

// Linked List functions:
void	ft_lstadd_front(t_keyvalue *lst, t_keyvalue new);
int		ft_lstsize(t_keyvalue *lst);

#endif
