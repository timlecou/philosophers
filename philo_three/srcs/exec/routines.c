/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:45:23 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/24 10:56:20 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

extern	t_data	g_data;

void	*start_routine(void *d)
{
	t_philo		*philo;

	philo = (t_philo*)d;
	while (!g_data.die)
	{
		take_forks(philo);
		sem_wait(philo->eat);
		philo->last_time_eat = get_time();
		sem_post(philo->eat);
		eat(philo);
		if (philo->eat_count == 0)
			break ;
		ft_print((int)(get_time() -
		g_data.start_time), philo->id + 1, SLEEPING);
		ft_usleep(g_data.time_to_sleep * 1000);
		ft_print((int)(get_time() -
		g_data.start_time), philo->id + 1, THINKING);
	}
	g_data.number--;
	return (NULL);
}

void	*death_routine(void *d)
{
	t_philo	*philo;
	long	time;

	philo = (t_philo*)d;
	while (!g_data.die)
		if (philo->has_eat == 1)
		{
			sem_wait(philo->eat);
			time = get_time() - philo->last_time_eat;
			if (time > g_data.time_to_die || philo->eat_count == 0)
			{
				if (!g_data.die && philo->eat_count != 0)
				{
					g_data.die = 1;
					ft_print((int)(get_time()
					- g_data.start_time), philo->id + 1, DIED);
				}
				sem_post(philo->eat);
				exit(ft_free_all(g_data.tmp) + 1);
			}
			sem_post(philo->eat);
			usleep(4000);
		}
	ft_free_all(g_data.tmp);
	exit(0);
}
