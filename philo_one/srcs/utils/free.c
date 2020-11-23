/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:24:45 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 14:19:20 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern	t_data	g_data;

void	ft_free_all(t_philo *philo)
{
	unsigned int	i;
	t_philo			*tmp;

	i = 0;
	while (i < g_data.ph_number)
	{
		tmp = philo;
		pthread_mutex_destroy(&philo->eat);
		pthread_mutex_destroy(&g_data.forks[i]);
		philo = philo->next;
		free(tmp);
		i++;
	}
	free(g_data.forks);
}
