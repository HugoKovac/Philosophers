/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:27:06 by hkovac            #+#    #+#             */
/*   Updated: 2022/02/10 14:55:17 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	is_num(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	parsing(char **av, t_data *input)
{
	if (!is_num(av[1]) || ft_atoi(av[1]) < 1)
		return (error(ERR_ARG_PB, 0));
	input->nb_philo = ft_atoi(av[1]);
	if (!is_num(av[2]))
		return (0);
	input->time_to_die = ft_atoi(av[2]);
	if (!is_num(av[3]))
		return (0);
	input->time_to_eat = ft_atoi(av[3]);
	if (!is_num(av[4]))
		return (0);
	input->time_to_sleep = ft_atoi(av[4]);
	if (ft_atoi(av[5]) <= 2147483647)
	{
		if (!is_num(av[5]) || ft_atoi(av[5]) < 1)
			return (0);
		input->max_eating = ft_atoi(av[5]);
	}
	else
		input->max_eating = -1;
	return (1);
}
