/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_local.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:21:25 by hkovac            #+#    #+#             */
/*   Updated: 2022/02/10 18:58:23 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	norm1(t_philo *philo)
{
	if (philo->global->stop > 0)
	{
		philo->global->stop++;
		pthread_mutex_unlock(philo->print);
		return (0);
	}
	return (1);
}

int	norm2(t_philo *philo, int add)
{
	if (philo->nb_eat == 0)
	{
		if (add >= philo->time_to_die)
		{
			pthread_mutex_lock(philo->print);
			philo->global->stop++;
			pthread_mutex_unlock(philo->print);
			printf(RED "%.5lld	%.3d %s\n",
				mls(philo->last_eat) + philo->global->time_to_die
				- mls(philo->global->ref), philo->n_philo, "died");
			return (0);
		}
	}
	return (1);
}

int	norm3(t_philo *philo, int add, struct timeval actual)
{
	if ((mls(actual) + add) - mls(philo->last_eat) >= philo->time_to_die)
	{
		pthread_mutex_lock(philo->print);
		philo->global->stop++;
		if (add)
			usleep(philo->global->time_to_die);
		pthread_mutex_unlock(philo->print);
		printf(RED "%.5lld	%.3d %s\n",
			mls(philo->last_eat) + philo->global->time_to_die
			- mls(philo->global->ref), philo->n_philo, "died");
		return (0);
	}
	return (1);
}

int	check_local(t_philo *philo, int add)
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	pthread_mutex_lock(philo->print);
	if (!norm1(philo))
		return (0);
	pthread_mutex_unlock(philo->print);
	if (philo->nb_eat == 0)
	{
		if (!norm2(philo, add))
			return (0);
	}
	else
		if (!norm3(philo, add, actual))
			return (0);
	return (1);
}
