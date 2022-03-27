/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:55:17 by kmumm             #+#    #+#             */
/*   Updated: 2022/01/31 22:08:50 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_substr_n(char *str)
{
	int		i;
	char	*result;
	char	*temp;

	if (!str[0])
		return (NULL);
	i = ft_findn(str);
	if (!i)
		i = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	temp = result;
	while (*str && *str != '\n')
		*result++ = *str++;
	if (*str == '\n')
		*result++ = *str++;
	*result = '\0';
	return (temp);
}

char	*ft_new_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(remainder) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (remainder[i])
		str[j++] = remainder[i++];
	str[j] = '\0';
	free(remainder);
	return (str);
}

char	*ft_str_read(int fd, char *remainder)
{
	char	*buffer;
	int		ret;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ret = 1;
	while (!ft_findn(remainder) && ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		remainder = ft_strjoin_gnl(remainder, buffer);
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (0);
	remainder = ft_str_read(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_substr_n(remainder);
	remainder = ft_new_remainder(remainder);
	return (line);
}
