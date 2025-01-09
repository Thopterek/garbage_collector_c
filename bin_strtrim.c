/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_strtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:47:55 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 14:57:10 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin_malloc.h"

char	*bin_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	front;
	size_t	back;
	size_t	cc;

	if (s1 == NULL || set == NULL)
		return (NULL);
	front = 0;
	back = 0;
	while (s1[front] != '\0' && bin_strchr(set, s1[front]) != NULL)
		front++;
	while (back < bin_strlen(s1) - front
		&& bin_strchr(set, s1[bin_strlen(s1) - back - 1]) != NULL)
		back++;
	cc = (bin_strlen(s1) - front - back);
	if (cc == 0)
		return (bin_calloc(1, sizeof(char)));
	trim = bin_calloc(cc + 1, sizeof(char));
	if (trim == NULL)
		return (NULL);
	bin_strlcpy(trim, &s1[front], (bin_strlen(s1) - front - back) + 1);
	return (trim);
}

// int main(void)
// {
// 	char *s1 = "ababc John Arnold cba";
// 	char *set = "abc";
// 	char *empty = "";
// 	char *trim_one = ft_strtrim(s1, set);
// 	char *trim_two = ft_strtrim(empty, set);
// 	printf("Original string: '%s'\n", s1);
// 	printf("My FT trimmed set abc: '%s'\n", trim_one);
// 	printf("My FT trimmed empty string: '%s'\n", trim_two);
// 	free(trim_one);
// 	free(trim_two);
// }
