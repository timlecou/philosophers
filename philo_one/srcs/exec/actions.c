/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:47:24 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 10:50:50 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern	t_data	g_data;

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&g_data.forks[philo->id]);
	pthread_mutex_lock(&g_data.forks[philo->r_neigh]);
	philo->has_fork = 1;
	ft_print((int)(get_time() - g_data.start_time),
	philo->id + 1, FORK);
	ft_print((int)(get_time() - g_data.start_time),
	philo->id + 1, FORK);
}

int		eat(t_philo *philo)
{
	ft_print((int)(get_time() - g_data.start_time),
	philo->id + 1, EATING);
	ft_usleep(g_data.time_to_eat * 1000);
	philo->has_eat = 1;
	if (philo->eat_count > 0)
		philo->eat_count--;
	pthread_mutex_unlock(&g_data.forks[philo->id]);
	pthread_mutex_unlock(&g_data.forks[philo->r_neigh]);
	return (EXIT_SUCCESS);
}
