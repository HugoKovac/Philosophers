/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:06:50 by hkovac            #+#    #+#             */
/*   Updated: 2022/02/10 18:33:20 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	init_mutex(t_data *global)
{
	int	i;

	i = -1;
	global->tab = malloc(sizeof (pthread_mutex_t) * global->nb_philo);
	if (!global->tab)
		return (error(ERR_MALL, 0));
	while (++i < global->nb_philo)
		if (pthread_mutex_init(&global->tab[i], NULL) != 0)
			return (error(ERR_MTX_INIT, 0));
	if (pthread_mutex_init(&global->print, NULL) != 0)
		return (error(ERR_MTX_INIT, 0));
	return (1);
}

void	init_norm(t_philo **philo, t_data *global, int i)
{
	t_philo	*tmp;

	tmp = *philo;
	while (tmp->next)
		tmp = tmp->next;
	tmp->n_philo = i;
	tmp->right = &global->tab[i - 1];
	if (i != global->nb_philo)
		tmp->left = &global->tab[i];
	else
		tmp->left = &global->tab[0];
	tmp->print = &global->print;
	tmp->global = global;
	tmp->nb_eat = 0;
	tmp->time_to_die = global->time_to_die;
}

int	init_params(t_philo **philo, t_data *global)
{
	int		i;

	if (!init_mutex(global))
		return (0);
	i = 0;
	global->stop = 0;
	while (++i <= global->nb_philo)
	{
		add_node_back(philo);
		if (!*philo)
			return (error(ERR_MALL, 0));
		init_norm(philo, global, i);
	}
	return (1);
}

int	init_thread(t_philo **philo)
{
	t_philo	*tmp;

	tmp = *philo;
	gettimeofday(&tmp->global->ref, NULL);
	if ((*philo)->global->nb_philo == 1)
	{
		usleep((*philo)->global->time_to_die);
		printf(RED "%.5d	%.3d %s\n",
			(*philo)->global->time_to_die, 1, "died");
		(*philo)->global->stop++;
		return (1);
	}
	while (tmp)
	{
		if (pthread_create(&tmp->actual_thread, NULL, start, tmp) != 0)
			return (error(ERR_PTH_CREA, 0));
		tmp = tmp->next;
	}
	return (1);
}
