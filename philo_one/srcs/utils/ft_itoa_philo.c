/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:01:32 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/21 14:11:27 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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

void	ft_itoa_philo(unsigned int time,
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
	nb[--i] =  ' ';
	if (time == 0)
		nb[--i] = '0';
	while (time > 0)
	{
		nb[--i] = (time % 10) + '0';
		time = time / 10;
	}
	write(1, nb, ft_strlen(nb));
}

