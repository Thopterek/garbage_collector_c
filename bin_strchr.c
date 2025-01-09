/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:10:48 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 14:58:06 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin_malloc.h"

char	*bin_strchr(const char *s, int c)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
	{
		if (s[n] == (char)c)
		{
			return ((char *)(&s[n]));
		}
		n++;
	}
	if ((char)c == '\0')
		return ((char *)(&s[n]));
	return (NULL);
}

// #include <string.h>
// int main(void)
// {
// 	char* skrr = "five5";
// 	char* zero = "";
// 	char s[] = "tripouille";
// 	printf("This is my FT\n%s\n", (ft_strchr(skrr, 'i')));
// 	printf("This is OriGinal\n%s\n", (strchr(skrr, 'i')));
// 	printf("This is my FT\n%s\n", (ft_strchr(zero, 'a')));
// 	printf("This is OriGinal\n%s\n", (strchr(zero, 'a')));
// 	printf("This is my FT\n%s\n", ft_strchr(s, 't' + 256));
// 	printf("This is OriGinal\n%s\n", strchr(s, 't' + 256));
// 	printf("This is my FT\n%s\n", ft_strchr("teste",'\0'));
// 	printf("This is OriGinal\n%s\n", strchr("teste",'\0'));
// }