/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:43:27 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/22 16:07:03 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	start_odd(t_data *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < data->ph_number / 2 + data->ph_number % 2)
	{
		data->index = j;
		if (pthread_create(&data->ph[j].thread, NULL, start_routine, (void*)data) == -1)
			return (EXIT_FAILURE);
		if (pthread_create(&data->ph[j].death_thread, NULL, death_routine, (void*)data) == -1)
			return (EXIT_FAILURE);
		usleep(20);
		pthread_detach(data->ph[j].thread);
		pthread_detach(data->ph[j].death_thread);
		++i;
		j = j + 2;
	}
	return (EXIT_SUCCESS);
}

int	start_even(t_data *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 1;
	while (i < data->ph_number / 2)
	{
		data->index = j;
		if (pthread_create(&data->ph[j].thread, NULL, start_routine, (void*)data) == -1)
			return (EXIT_FAILURE);
		if (pthread_create(&data->ph[j].death_thread, NULL, death_routine, (void*)data) == -1)
			return (EXIT_FAILURE);
		usleep(20);
		pthread_detach(data->ph[j].thread);
		pthread_detach(data->ph[j].death_thread);
		++i;
		j = j + 2;
	}
	return (EXIT_SUCCESS);
}

int	launch_philo(t_data *data)
{
	if (init_mutex(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (start_odd(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//ft_usleep(5000);
	if (start_even(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

