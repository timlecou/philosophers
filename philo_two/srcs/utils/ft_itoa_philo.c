/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:01:32 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 15:41:50 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

extern	t_data	g_data;

long			get_time(void)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

unsigned int	nb_chiffre(unsigned int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

void			ft_itoa_philo(unsigned int time,
	unsigned int n, char *txt, unsigned int i)
{
	unsigned int			j;
	char					nb[i + 1];

	j = ft_strlen(txt);
	nb[i] = 0;
	while (j > 0)
		nb[--i] = txt[--j];
	if (n == 0)
		nb[--i] = '0';
	while (n > 0)
	{
		nb[--i] = (n % 10) + '0';
		n = n / 10;
	}
	nb[--i] = ' ';
	if (time == 0)
		nb[--i] = '0';
	while (time > 0)
	{
		nb[--i] = (time % 10) + '0';
		time = time / 10;
	}
	write(1, nb, ft_strlen(nb));
}

void			ft_print(int n, int id, char *state)
{
	int		size;

	size = nb_chiffre(n) + nb_chiffre(id) + ft_strlen(state) + 1;
	sem_wait(g_data.msg);
	if (g_data.die == 1 && ft_strcmp(state, DIED) != 0)
	{
		sem_post(g_data.msg);
		return ;
	}
	ft_itoa_philo(n, id, state, size);
	sem_post(g_data.msg);
}
