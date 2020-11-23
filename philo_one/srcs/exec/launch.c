/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:43:27 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 14:16:01 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern	t_data	g_data;

int	start_odd(t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < g_data.ph_number)
	{
		if (pthread_create(&philo->thread, NULL, start_routine,
				(void*)philo) == -1)
			return (EXIT_FAILURE);
		pthread_detach(philo->thread);
		if (pthread_create(&philo->death_thread, NULL,
						death_routine, (void*)philo) == -1)
			return (EXIT_FAILURE);
		pthread_detach(philo->death_thread);
		i += 2;
		philo = philo->next;
		if (philo)
			philo = philo->next;
	}
	return (EXIT_SUCCESS);
}

int	start_even(t_philo *philo)
{
	unsigned int	i;

	i = 1;
	philo = philo->next;
	while (i < g_data.ph_number)
	{
		if (pthread_create(&philo->thread, NULL, start_routine,
			(void*)philo) == -1)
			return (EXIT_FAILURE);
		pthread_detach(philo->thread);
		if (pthread_create(&philo->death_thread, NULL,
						death_routine, (void*)philo) == -1)
			return (EXIT_FAILURE);
		pthread_detach(philo->death_thread);
		i += 2;
		philo = philo->next;
		if (philo)
			philo = philo->next;
	}
	return (EXIT_SUCCESS);
}

int	launch_philo(t_philo *philo)
{
	if (init_mutex() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (start_odd(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (start_even(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
