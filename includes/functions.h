/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:17:27 by hkovac            #+#    #+#             */
/*   Updated: 2022/02/10 18:29:40 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "includes.h"

/*routine.c*/
void		*start(void *ptr);
/*check.c*/
void		*check(void *ptr);
/*utils.c*/
long long	get_mls(struct timeval ref);
long long	mls(struct timeval time);
int			error(char *str, int rtn);
long long	ft_atoi(const char *nptr);
/*parsing.c*/
int			parsing(char **av, t_data *input);
/*list.c*/
t_philo		*new_node(void);
void		add_node_back(t_philo **first);
int			del_list(t_philo **lst);
/*utils_thread.c*/
void		destroy_all(t_data *global);
int			init_mutex(t_data *global);
int			init_params(t_philo **philo, t_data *global);
int			init_thread(t_philo **philo);
/*check_local.c*/
int			check_local(t_philo *philo, int add);

#endif