/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:43:27 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/22 10:47:47 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	launch_philo(t_data *data)
{
	unsigned int	 i;

	i = 0;
	if (init_mutex(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (i < data->ph_number)
	{
		data->index = i;
		if (pthread_create(&data->ph[i].thread, NULL, start_routine, (void*)data) == -1)
			return (EXIT_FAILURE);
		if (pthread_create(&data->ph[i].death_thread, NULL, death_routine, (void*)data) == -1)
			return (EXIT_FAILURE);
		usleep(20);
		pthread_detach(data->ph[i].thread);
		pthread_detach(data->ph[i].death_thread);
		i = i + 2;
	}
	i = 1;
	ft_usleep(5000);
	while (i < data->ph_number)
	{
		data->index = i;
		if (pthread_create(&data->ph[i].thread, NULL, start_routine, (void*)data) == -1)
			return (EXIT_FAILURE);
		if (pthread_create(&data->ph[i].death_thread, NULL, death_routine, (void*)data) == -1)
			return (EXIT_FAILURE);
		usleep(20);
		pthread_detach(data->ph[i].thread);
		pthread_detach(data->ph[i].death_thread);
		i = i + 2;
	}
	//death_routine(data);
	return (EXIT_SUCCESS);
}

