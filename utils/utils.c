/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:33:57 by hkovac            #+#    #+#             */
/*   Updated: 2022/02/10 14:55:57 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	error(char *str, int rtn)
{
	printf(RED "%s\n", str);
	return (rtn);
}

long long	ft_atoi(const char *nptr)
{
	long long	result;
	long long	signe;

	if (!nptr)
		return (2147483650);
	result = 0;
	signe = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe = -signe;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + (*nptr++ - '0');
	return ((long long int)signe * result);
}

long long	mls(struct timeval time)
{
	return ((time.tv_sec) * 1000 + time.tv_usec / 1000);
}

long long	get_mls(struct timeval ref)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec) * 1000 + time.tv_usec / 1000) - mls(ref));
}

void	destroy_all(t_data *global)
{
	while (--global->nb_philo)
		pthread_mutex_destroy(&global->tab[global->nb_philo]);
	free(global->tab);
	del_list(global->list);
}
