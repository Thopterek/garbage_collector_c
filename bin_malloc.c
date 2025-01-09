/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:59:00 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 15:48:50 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin_malloc.h"

/*
	Actual pointer needed by the caller
	we save the return in saving_point
*/
static void	*alloc_ptr(ssize_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

/*
	We reset the values so we can free everything and reuse it once again
	depending on the scope we want to use the garabage collector in.
	To be modified later on for specific flags.
*/
static void	*clean_reset(void ***saving_point, int *alloc_c, int *capacity)
{
	if ((*saving_point) == NULL)
		return ((*capacity) = 1, (*alloc_c) = 0, NULL);
	while ((*alloc_c) > 0)
	{
		(*alloc_c)--;
		if ((*saving_point)[(*alloc_c)] != NULL)
		{
			free((*saving_point)[(*alloc_c)]);
			(*saving_point)[(*alloc_c)] = NULL;
		}
	}
	free(*saving_point);
	(*saving_point) = NULL;
	(*alloc_c) = 0;
	(*capacity) = 1;
	return (NULL);
}

/*
	We are resizing only if the previous saving_point is too small
	because we start from 1 we call resize the most at the beginning
*/
static void	resize(void ***saving_point, int alloc_c, int *capacity)
{
	void	**tmp;
	int		i;

	i = 0;
	if ((*saving_point) != NULL && (*capacity) == alloc_c)
	{
		tmp = (void **)malloc(sizeof(void *) * (alloc_c * 2));
		(*capacity) = alloc_c * 2;
		if (tmp == NULL)
			return ;
		while (i < alloc_c)
		{
			tmp[i] = (*saving_point)[i];
			i++;
		}
		free(*saving_point);
		(*saving_point) = tmp;
	}
}

/*
	Main function, tracking the allocations with saving_point
	alloc_c is counter to track how many times bin was called
	capacity lets us control when to use the resize function
*/
void	*bin_malloc(ssize_t size)
{
	static int	alloc_c = 0;
	static int	capacity = 1;
	static void	**saving_point = NULL;

	if (size > 0 && saving_point == NULL)
	{
		saving_point = (void **)malloc(sizeof(void *) * 1);
		if (saving_point == NULL)
			return (NULL);
	}
	if (size > 0)
	{
		if (alloc_c != 0)
			resize(&saving_point, alloc_c, &capacity);
		saving_point[alloc_c] = alloc_ptr(size);
		if (saving_point[alloc_c] == NULL)
			return (clean_reset(&saving_point, &alloc_c, &capacity));
		alloc_c++;
		return (saving_point[alloc_c - 1]);
	}
	return (clean_reset(&saving_point, &alloc_c, &capacity));
}

/* 
This is just for testing
	valgrind --leak-check=full --show-leak-kinds=all 
	--track-origins=yes ./executable <exampleParam1>
*/
// #include <stdio.h>
// int main(void)
// {
// 	char *str = bin_strdup("This is a test");
// 	printf("%s\n", str);
// 	char **split = bin_split(str, ' ');
// 	printf("Oh look\n%s\n", split[0]);
// 	printf("%s\n", split[1]);
// 	printf("%s\n", split[2]);
// 	printf("%s\n", split[3]);
// 	int *numbers = bin_malloc(sizeof(int) * 1);
// 	numbers[0] = 5;
// 	printf("Grade %d out of %d\n", numbers[0], numbers[0]);
// 	bin_malloc(-1);
// }