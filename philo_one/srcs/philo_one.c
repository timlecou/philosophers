/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 10:45:07 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/22 11:25:15 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	wait_all_philo_to_finish(t_data *data)
{
	while (data->number > 1 || data->d_number > 1)
		;
}

int		main(int ac, char **av)
{
	t_data  data;

	data = init_data_struct();
	data.start_time = get_time();
	if (ac != 5 && ac != 6)
		return (ft_error(WRONG_NB_ARG));
	if (ft_parsing(&data, ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (launch_philo(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	wait_all_philo_to_finish(&data);
	if (everyone_fed(&data) == 1)
		write(1, FED, ft_strlen(FED));
	return (EXIT_SUCCESS);
}
