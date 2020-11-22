/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:24:45 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/22 12:30:03 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_free_all(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->ph_number)
	{
		pthread_mutex_destroy(&data->eat[i]);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->ph);
}
