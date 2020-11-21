/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/21 14:30:16 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include "define.h"
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include "structures.h"

int     ft_atoi_philo(char *str);
void	ft_itoa_philo(unsigned int time, unsigned int n, char *txt, unsigned int i);
unsigned int	nb_chiffre(unsigned int nb);
void    ft_putstr(char *str);
t_data  init_data_struct(void);
void    init_t_philo(t_data *data, int id);
int     ft_parsing(t_data *data, int ac, char **av);
void    ft_putnbr(int nb);
void    init_neighs(t_data *data, unsigned int id);
void    ft_usleep(long value);
long    get_time(void);
void    message(long time, int id, char *str);
int     ft_error(char *str);
int		ft_strlen(char *str);
#endif
