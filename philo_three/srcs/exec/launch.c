/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:43:27 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 20:59:15 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

extern	t_data	g_data;

int	start_odd(t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < g_data.ph_number)
	{
		philo->pid = fork();
		if (philo->pid == 0)
		{
			if (pthread_create(&philo->death_thread, NULL,
							death_routine, (void*)philo) == -1)
				return (EXIT_FAILURE);
			pthread_detach(philo->death_thread);
			start_routine(philo);
			exit(EXIT_SUCCESS);
		}
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
		philo->pid = fork();
		if (philo->pid == 0)
		{
			if (pthread_create(&philo->death_thread, NULL,
							death_routine, (void*)philo) == -1)
				return (EXIT_FAILURE);
			pthread_detach(philo->death_thread);
			start_routine(philo);
			exit(EXIT_SUCCESS);
		}
		i += 2;
		philo = philo->next;
		if (philo)
			philo = philo->next;
	}
	return (EXIT_SUCCESS);
}

int	launch_philo(t_philo *philo)
{
	int				status;
	unsigned int	i;
	unsigned int	j;

	status = 0;
	j = 0;
	i = g_data.ph_number;
	if (start_odd(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (start_even(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (j < g_data.ph_number && waitpid(-1,
	&status, 0) && WEXITSTATUS(status) == 0)
		j++;
	while (i-- > 0 && j < g_data.ph_number)
	{
		kill(philo->pid, SIGINT);
		if (philo->next)
			philo = philo->next;
	}
	return (EXIT_SUCCESS);
}
