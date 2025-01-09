/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_malloc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 07:09:48 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/01/09 15:08:44 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIN_MALLOC_H 
# define BIN_MALLOC_H

# include <stdlib.h>
# include <stddef.h>
# include <sys/types.h>

/*
	Main garbage collector function:
	- base usage like your standard malloc
	- to free the memory pass in value <= 0
*/
void	*bin_malloc(ssize_t size);

/*
	Functions that utilize the garbage collector internally
*/
void	bin_bzero(void *s, size_t n);
void	*bin_calloc(size_t count, size_t size);
char	*bin_itoa(int n);
char	**bin_split(char const *s, char c);
char	*bin_strdup(const char *s1);
char	*bin_strjoin(char const *s1, char const *s2);
size_t	bin_strlcat(char *dst, const char *src, size_t dstsize);
size_t	bin_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	bin_strlen(const char	*s);
char	*bin_strmapi(char const *s, char (*f)(unsigned int, char));
char	*bin_strrchr(const char *s, int c);
char	*bin_strtrim(char const *s1, char const *set);
char	*bin_substr(char const *s, unsigned int start, size_t len);
char	*bin_strchr(const char *s, int c);

#endif