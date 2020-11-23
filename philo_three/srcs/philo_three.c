/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 10:45:07 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 18:21:18 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_data	g_data;

void	wait_all_philo_to_finish(void)
{
	while (g_data.number != 0)
		;
}

int		main(int ac, char **av)
{
	t_philo	*philo;

	init_data_struct();
	g_data.start_time = get_time();
	if (ac != 5 && ac != 6)
		return (ft_error(WRONG_NB_ARG));
	if (ft_parsing(ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philo = init_philo_list(1, g_data.ph_number);
	if (launch_philo(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	wait_all_philo_to_finish();
	if (!g_data.die && ac == 6)
		write(1, FED, ft_strlen(FED));
	ft_free_all(philo);
	return (EXIT_SUCCESS);
}
