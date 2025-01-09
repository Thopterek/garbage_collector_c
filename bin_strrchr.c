/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_strrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:29:56 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 13:11:56 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin_malloc.h"

char	*bin_strrchr(const char *s, int c)
{
	int	n;

	n = bin_strlen(s);
	if ((char)c == '\0')
		return ((char *)(&s[n]));
	while (n > 0)
	{
		if (s[n - 1] == (char)c)
		{
			return ((char *)(&s[n - 1]));
		}
		n--;
	}
	if ((char)c == '\0')
		return ((char *)(&s[n]));
	return (NULL);
}

// #include <string.h>
// int main(void) 
// {
// 	char* five = "fivef";
// 	char* zero = "\0";
// 	char* no_w = "Those are letters";
// 	char s[] = "tripouille";
// 	printf("This is my FT\n");
// 	printf("%s\n", (ft_strrchr(five, 'f')));
// 	printf("%s\n", (ft_strrchr(zero, '\0')));
// 	printf("%s\n", (ft_strrchr(no_w, 'w')));
// 	printf("%s\n", ft_strrchr(s, 't'));
// 	printf("This is OriGinal\n");
// 	printf("%s\n", (strrchr(five, 'f')));
// 	printf("%s\n", (strrchr(zero, '\0')));
// 	printf("%s\n", (strrchr(no_w, 'w')));
// 	printf("%s\n", strrchr(s, 't'));
// }