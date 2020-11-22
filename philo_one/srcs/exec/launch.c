/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:43:27 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/22 17:33:42 by timlecou         ###   ########.fr       */
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
		pthread_detach(data->ph[j].thread);
		//if (pthread_create(&data->ph[j].death_thread, NULL, death_routine, (void*)data) == -1)
		//	return (EXIT_FAILURE);
		//pthread_detach(data->ph[j].death_thread);
		usleep(200);
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
		pthread_detach(data->ph[j].thread);
		//if (pthread_create(&data->ph[j].death_thread, NULL, death_routine, (void*)data) == -1)
		//	return (EXIT_FAILURE);
		//pthread_detach(data->ph[j].death_thread);
		usleep(200);
		++i;
		j = j + 2;
	}
	return (EXIT_SUCCESS);
}

int	launch_philo(t_data *data)
{
	unsigned int	i;

	i = 0;
	if (init_mutex(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (start_odd(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_usleep(5000);
	if (start_even(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (i < data->ph_number)
	{
		pthread_create(&data->ph[i].death_thread, NULL, death_routine, (void*)data);
		pthread_detach(data->ph[i].death_thread);
		i++;
	}
	return (EXIT_SUCCESS);
}

