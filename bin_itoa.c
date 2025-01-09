/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:43:10 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 13:21:36 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin_malloc.h"

static char	*loop_logic(char *str, int copy, int minus, int cc)
{
	int	first;

	first = 0;
	if (minus == 1)
		str[0] = '-';
	while (copy != 0)
	{
		if (first == 0)
		{
			first++;
			str[cc] = '\0';
		}
		str[cc - 1] = copy % 10 + '0';
		copy = copy / 10;
		cc--;
	}
	return (str);
}

static int	memory_cc(int n, int cc)
{
	while (n != 0)
	{
		cc++;
		n = n / 10;
	}
	return (cc);
}

char	*bin_itoa(int n)
{
	int		cc;
	int		copy;
	int		minus;
	char	*str;

	cc = 0;
	minus = 0;
	copy = n;
	if (n == -2147483648)
		return (bin_strdup("-2147483648"));
	if (n == 0)
		return (bin_strdup("0"));
	if (n < 0)
	{
		minus = 1;
		copy *= -1;
		cc++;
	}
	cc = memory_cc(n, cc);
	str = bin_calloc(cc + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	return (loop_logic(str, copy, minus, cc));
}

// int main(void)
// {
// 	int i = -1234567;
// 	char *ptr = ft_itoa(i);
// 	printf("%s\n", ptr);
// 	free(ptr);
// }