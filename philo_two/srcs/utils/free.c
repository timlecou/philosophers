/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:24:45 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 15:49:20 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

extern	t_data	g_data;

void	ft_free_all(t_philo *philo)
{
	unsigned int	i;
	t_philo			*tmp;

	i = 0;
	while (i < g_data.ph_number)
	{
		tmp = philo;
		sem_close(philo->eat);
		sem_unlink(philo->name);
		free(philo->name);
		philo = philo->next;
		free(tmp);
		i++;
	}
	sem_close(g_data.msg);
	sem_unlink("msg");
	sem_close(g_data.forks);
	sem_unlink("forks");
	sem_close(g_data.lunch);
	sem_unlink("lunch");
}
