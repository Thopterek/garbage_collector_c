/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:56:05 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 13:14:27 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin_malloc.h"

char	*bin_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	cc;
	size_t	loop_c;

	if (s == NULL)
		return (NULL);
	if (start >= bin_strlen(s))
		return (bin_calloc(1, sizeof(char)));
	if (bin_strlen(s) - (start) < len)
		cc = bin_strlen(s) - (start);
	else
		cc = len;
	loop_c = 0;
	sub = bin_calloc(cc + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (s[start + loop_c] != '\0' && loop_c < len)
	{
		sub[loop_c] = s[start + loop_c];
		loop_c++;
	}
	sub[loop_c] = '\0';
	return (sub);
}

// int main(void)
// {
// 	size_t ten = 10;
// 	char *string = "i just want this part #############";
// 	char *test = ft_substr(string, 5, ten);
// 	printf("%s", test);
// 	free (test);
// 	return (0);
// }