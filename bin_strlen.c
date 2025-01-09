/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:59:13 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 13:06:34 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin_malloc.h"

size_t	bin_strlen(const char	*s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

// #include <string.h>
// #include <stdlib.h>
// int main(void)
// {
// 	char* skrr = "five5";
// 	char* zero = "";
// 	printf("This is my FT\n%zu\n", ft_strlen(skrr));
// 	printf("This is my FT\n%zu\n", ft_strlen(zero));
// 	printf("This is OriGinal\n%lu\n", strlen(skrr));
// 	printf("This is OriGinal\n%lu\n", strlen(zero));
// }