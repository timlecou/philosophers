/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:47:24 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 16:47:22 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

extern	t_data	g_data;

void	take_forks(t_philo *philo)
{
	sem_wait(g_data.lunch);
	sem_wait(g_data.forks);
	philo->has_fork = 1;
	ft_print((int)(get_time() - g_data.start_time),
	philo->id + 1, FORK);
	sem_wait(g_data.forks);
	ft_print((int)(get_time() - g_data.start_time),
	philo->id + 1, FORK);
	sem_post(g_data.lunch);
}

int		eat(t_philo *philo)
{
	ft_print((int)(get_time() - g_data.start_time),
	philo->id + 1, EATING);
	ft_usleep(g_data.time_to_eat * 1000);
	philo->has_eat = 1;
	if (philo->eat_count > 0)
		philo->eat_count--;
	sem_post(g_data.forks);
	sem_post(g_data.forks);
	return (EXIT_SUCCESS);
}
