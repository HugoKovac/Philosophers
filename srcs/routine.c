/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:18:05 by hkovac            #+#    #+#             */
/*   Updated: 2022/02/10 18:35:29 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	safe_print(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (philo->global->stop == 0)
		printf(WHT "%.5lld	%.3d %s\n",
			get_mls(philo->global->ref), philo->n_philo, str);
	pthread_mutex_unlock(philo->print);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	safe_print(YEL"has taken a fork", philo);
	pthread_mutex_lock(philo->left);
	safe_print(YEL"has taken a fork", philo);
	safe_print(GRN"is eating", philo);
	pthread_mutex_lock(philo->print);
	philo->nb_eat += 1;
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_unlock(philo->print);
	usleep(philo->global->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_lock(philo->print);
	if (philo->global->max_eating != -1
		&& philo->nb_eat >= philo->global->max_eating)
	{
		philo->global->finished += 1;
		pthread_mutex_unlock(philo->print);
		return (0);
	}
	pthread_mutex_unlock(philo->print);
	return (1);
}

void	*start(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	pthread_detach(philo->actual_thread);
	if (!philo->n_philo % 2 || philo->n_philo == philo->global->nb_philo)
		usleep(200);
	while (1)
	{
		if (!check_local(philo, philo->global->time_to_eat))
			return (NULL);
		if (!eat(philo))
			return (NULL);
		if (!check_local(philo, philo->global->time_to_sleep))
			return (NULL);
		safe_print(BLU"is sleeping", philo);
		usleep(philo->global->time_to_sleep);
		if (!check_local(philo, 0))
			return (NULL);
		safe_print(MAG"is thinnking", philo);
		usleep(2);
	}
	return (NULL);
}
