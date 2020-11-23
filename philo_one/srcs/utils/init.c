/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:16:51 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 14:17:54 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern	t_data	g_data;

t_philo	*init_philo_list(int i, int nb)
{
	t_philo	*philo;

	if (i > nb || !(philo = (t_philo*)malloc(sizeof(t_philo))))
		return (NULL);
	init_t_philo(philo, i);
	philo->next = init_philo_list(i + 1, nb);
	return (philo);
}

void	init_data_struct(void)
{
	g_data.ph_number = 0;
	g_data.number = 0;
	g_data.all_fed = 0;
	g_data.time_must_eat = 0;
	g_data.time_to_die = 0;
	g_data.time_to_eat = 0;
	g_data.time_to_sleep = 0;
	g_data.start_time = 0;
	g_data.die = 0;
}

void	init_t_philo(t_philo *philo, int id)
{
	philo->id = id - 1;
	philo->thread = 0;
	philo->fed = 0;
	philo->death_thread = 0;
	philo->has_fork = 0;
	philo->last_time_eat = 0;
	philo->has_eat = 0;
	philo->r_neigh = 0;
	philo->l_neigh = 0;
	pthread_mutex_init(&philo->eat, NULL);
	pthread_mutex_unlock(&philo->eat);
	philo->eat_count = g_data.time_must_eat;
}

void	init_neighs(t_philo *philo)
{
	if (philo->id == 0)
		philo->r_neigh = g_data.ph_number - 1;
	else
		philo->r_neigh = philo->id - 1;
	if (philo->id == g_data.ph_number - 1)
		philo->l_neigh = 0;
	else
		philo->l_neigh = philo->id + 1;
}

int		init_mutex(void)
{
	unsigned int i;

	i = 0;
	if (!(g_data.forks = malloc(sizeof(pthread_mutex_t) * g_data.ph_number)))
		return (EXIT_FAILURE);
	pthread_mutex_init(&g_data.msg, NULL);
	while (i < g_data.ph_number)
	{
		pthread_mutex_init(&g_data.forks[i], NULL);
		++i;
	}
	return (EXIT_SUCCESS);
}
