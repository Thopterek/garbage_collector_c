/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:40:06 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 11:43:27 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin_malloc.h"

void	*bin_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = bin_malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	bin_bzero(ptr, count * size);
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("Original function:\n");
//     int* og1 = calloc(4, sizeof(int));
//     int* og2 = calloc(1, sizeof(int[4]));
//     int* og3 = calloc(4, sizeof *og3);
//  	if (og2)
//     {
//         for (int n = 0; n < 4; ++n) // print the array
//             printf("og2[%d] == %d\n", n, og2[n]);
//     }
//     free(og1);
//     free(og2);
//     free(og3);

// 	printf("My own FT:\n");
// 	int* my1 = ft_calloc(4, sizeof(int));
//     int* my2 = ft_calloc(1, sizeof(int[4]));
//     int* my3 = ft_calloc(4, sizeof *my3);
//     if (my2)
//     {
//         for (int n = 0; n < 4; ++n) // print the array
//             printf("my2[%d] == %d\n", n, my2[n]);
//     }
//     free(my1);
//     free(my2);
//     free(my3);
// }