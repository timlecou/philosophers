/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/01/11 15:06:38 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include "structures.h"

int     ft_atoi_philo(char *str);
void    ft_putstr(char *str);
t_data  init_data_struct(void);
void    init_t_philo(t_data *data, int id);
int     ft_parsing(t_data *data, int ac, char **av);
void    ft_putnbr(int nb);
#endif