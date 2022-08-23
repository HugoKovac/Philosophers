/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:35:34 by hkovac            #+#    #+#             */
/*   Updated: 2022/02/10 11:32:59 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_philo	*new_node(void)
{
	t_philo	*new;

	new = malloc(sizeof (t_philo));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	add_node_back(t_philo **first)
{
	t_philo	*tmp;

	if (!*first)
		*first = new_node();
	else
	{	
		tmp = *first;
		while (tmp->next != NULL)
			tmp = (tmp)->next;
		tmp->next = new_node();
	}
}

int	del_list(t_philo **lst)
{
	t_philo	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
	}
	return (0);
}
