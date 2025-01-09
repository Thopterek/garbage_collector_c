/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:44:37 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 11:43:55 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin_malloc.h"

void	bin_bzero(void *s, size_t n)
{
	size_t			cc;
	unsigned char	*tmp;

	cc = 0;
	tmp = (unsigned char *)(s);
	while (cc < n)
	{
		tmp[cc] = '\0';
		cc++;
	}
}

// #include <string.h>
// int main(void)
// {
//   char str[] = "almost every bank account";
//   char copy[] = "almost every bank account";
//   bzero (str, 6);
//   printf("this is how OG bzero works:\n %s\n",str);
//   ft_bzero(copy, 6);
//   printf("this is how my ft works:\n%s\n",copy);
// }