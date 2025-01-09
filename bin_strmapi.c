/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_strmapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 07:45:38 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 13:07:30 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin_malloc.h"

char	*bin_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	cc;
	char	*new;

	cc = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	new = bin_calloc(bin_strlen(s) + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	while (cc < bin_strlen(s))
	{
		new[cc] = f(cc, s[cc]);
		cc++;
	}
	new[cc] = '\0';
	return (new);
}

// char shift_char(unsigned int i, char c) {
//     return (c + 1);
// }
// void run_tests() {
//     char *result;
//  // gcc ft_strmapi.c ft_strlen.c ft_calloc.c ft_bzero.c
//     result = ft_strmapi("abcdefghijklmnopqrstuvwxy", shift_char);
//     printf("Test: %s\n", 
// 	strcmp(result, "bcdefghijklmnopqrstuvwxyz") == 0 ? "Passed" : "Failed");
//     free(result);
// }
// int main() {
//     run_tests();
//     return 0;
// }
