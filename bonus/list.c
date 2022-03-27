/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:42:02 by eanastas          #+#    #+#             */
/*   Updated: 2022/01/31 02:49:00 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (result == NULL)
		return (NULL);
	result->content = content;
	if (!content)
		result->len = -1;
	else
		result->len = ft_strlen(content);
	result->index = 0;
	result->next = NULL;
	return (result);
}

void	ft_lst_push(t_list **lst, t_list *new)
{
	(*lst)->next = new;
	(*lst)->next->index = (*lst)->index + 1;
	*lst = new;
	if ((*lst)->content)
		(*lst)->len = ft_strlen((*lst)->content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

int	ft_lstsize(t_list *lst)
{
	int		n;

	n = 1;
	if (!lst)
		return (0);
	while (lst -> next != NULL)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
