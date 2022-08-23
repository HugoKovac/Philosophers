/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:34:54 by hkovac            #+#    #+#             */
/*   Updated: 2022/02/10 14:48:56 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	check_max(t_data *global)
{
	pthread_mutex_lock(&global->print);
	if (global->finished == global->nb_philo)
	{
		pthread_mutex_unlock(&global->print);
		return (0);
	}
	pthread_mutex_unlock(&global->print);
	return (1);
}

void	*check(void *ptr)
{
	t_data	*global;

	global = ptr;
	while (1)
	{
		if (!check_max(global))
			return (NULL);
		pthread_mutex_lock(&global->print);
		if (global->stop == global->nb_philo)
		{
			pthread_mutex_unlock(&global->print);
			return (NULL);
		}
		pthread_mutex_unlock(&global->print);
	}
	return (NULL);
}
