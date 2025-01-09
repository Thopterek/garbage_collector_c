/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:44:56 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 13:04:59 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin_malloc.h"

char	*bin_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*first;
	char	*sec;
	size_t	cc;

	first = (char *)s1;
	sec = (char *)s2;
	cc = bin_strlen(first) + bin_strlen(sec);
	new = bin_calloc(cc + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	bin_strlcpy(new, first, bin_strlen(first) + 1);
	bin_strlcat(new, sec, cc + 1);
	return (new);
}

// cc -Wall -Werror -Wextra ft_strjoin.c ft_calloc.c 
// ft_strlen.c ft_bzero.c ft_strlcpy.c ft_strlcat.c
// #include <string.h>
// int main(void)
// {
// 	char *test_one = "John ";
// 	char *second_test = "short";
// 	char *string_two = "look 14 chars";
// 	char *tmp_join;
// 	char *sec_join;
// 	tmp_join = ft_strjoin(test_one, string_two);
// 	sec_join = ft_strjoin(second_test, string_two);
// 	printf("This is how string looks like:\n%s\n", tmp_join);
// 	printf("This is with test 2:\n%s\n\n", sec_join);
// 	free (tmp_join);
// 	free (sec_join);
// }