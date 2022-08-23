/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:38:09 by hkovac            #+#    #+#             */
/*   Updated: 2022/02/10 18:34:09 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "includes.h"

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eating;
	int				dead;
	int				finished;
	int				stop;
	struct timeval	ref;
	pthread_mutex_t	print;
	pthread_t		check;
	struct s_philo	**list;
	pthread_mutex_t	*tab;
}	t_data;

typedef struct s_philo
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*print;
	int				n_philo;
	pthread_t		actual_thread;
	int				nb_eat;
	int				time_to_die;
	struct timeval	last_eat;
	struct s_data	*global;
	struct s_philo	*next;
}	t_philo;

#endif