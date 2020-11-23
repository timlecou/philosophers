/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:06:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 11:41:20 by timlecou         ###   ########.fr       */
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

t_philo			*init_philo_list(int i, int nb);
int     		ft_atoi_philo(char *str);
void			ft_itoa_philo(unsigned int time, unsigned int n,
				char *txt, unsigned int i);
unsigned int	nb_chiffre(unsigned int nb);
void    		ft_putstr(char *str);
void			init_data_struct(void);
void    		init_t_philo(t_philo *philo, int id);
int     		ft_parsing(int ac, char **av);
void    		ft_putnbr(int nb);
void    		init_neighs(t_philo *philo);
void    		ft_usleep(long value);
int				launch_philo(t_philo *philo);
long    		get_time(void);
void    		message(long time, int id, char *str);
int     		ft_error(char *str);
int				ft_strlen(char *str);
int				init_mutex(void);
void			*start_routine(void *d);
void			*death_routine(void *d);
int				eat(t_philo *philo);
void			ft_print(int time, int id, char *state);
void			take_forks(t_philo *philo);
void			ft_free_all(t_philo *philo);
#endif
