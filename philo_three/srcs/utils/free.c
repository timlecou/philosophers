/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:24:45 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/24 10:24:57 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

extern	t_data	g_data;

int		ft_free_all(t_philo *philo)
{
	unsigned int	i;
	t_philo			*tmp;

	i = 0;
	sem_close(g_data.msg);
	sem_close(g_data.forks);
	sem_close(g_data.lunch);
	sem_unlink("msg");
	sem_unlink("forks");
	sem_unlink("lunch");
	while (philo)
	{
		tmp = philo;
		sem_close(philo->eat);
		sem_unlink(philo->name);
		free(philo->name);
		philo = philo->next;
		free(tmp);
		tmp = NULL;
		i++;
	}
	free(philo);
	return (0);
}
