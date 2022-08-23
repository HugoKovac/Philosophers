/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:20:05 by hkovac            #+#    #+#             */
/*   Updated: 2022/02/10 14:55:49 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int ac, char **av)
{
	t_data	global;
	t_philo	*philo;

	philo = NULL;
	global = (t_data){0};
	if (ac < 5 || ac > 6)
		return (error(ERR_ARG, 1));
	global.list = &philo;
	if (!parsing(av, &global))
		return (1);
	if (!init_params(&philo, &global))
		return (1);
	init_thread(&philo);
	pthread_create(&global.check, NULL, check, &global);
	pthread_join(global.check, NULL);
	destroy_all(&global);
	return (0);
}
