/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:16:51 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 15:52:24 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
	philo->name = ft_itoa_name("eat ", id);
	philo->eat = sem_open(philo->name, O_CREAT | O_EXCL, 0644, 1);
	philo->eat_count = g_data.time_must_eat;
}
