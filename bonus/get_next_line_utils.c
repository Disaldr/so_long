/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:55:05 by kmumm             #+#    #+#             */
/*   Updated: 2022/02/01 23:00:44 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *s)
{
	const char		*start;

	start = s;
	while (*s)
		++s;
	return ((size_t)(s - start));
}

int	ft_strip(char **str)
{
	int	len;

	len = ft_strlen(*str);
	if ((*str)[len - 1] == '\n')
	{
		(*str)[len - 1] = '\0';
		return (len - 1);
	}
	return (len);
}

char	*ft_strdup(const char *str)
{
	char	*copy;
	char	*copy_start;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	copy_start = copy;
	if (copy)
	{
		while (*str)
			*copy++ = *str++;
		*copy = '\0';
	}
	return (copy_start);
}

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	char	*res;
	char	*res_temp;
	char	*str1_temp;

	if (!str1)
		str1 = ft_strdup("");
	if (!str1 || !str2)
		return (NULL);
	res = malloc(sizeof(char) * ((ft_strlen(str1) + ft_strlen(str2)) + 1));
	if (res == NULL)
		return (NULL);
	res_temp = res;
	str1_temp = str1;
	while (*str1_temp)
		*(res_temp++) = *(str1_temp++);
	while (*str2)
		*(res_temp++) = *(str2++);
	*res_temp = '\0';
	free(str1);
	return (res);
}

int	ft_findn(char *str)
{
	char	*start;

	if (!str)
		return (0);
	start = str;
	while (*str++)
		if (*str == '\n')
			return ((int)(str - start));
	return (0);
}
