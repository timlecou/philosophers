/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:39:24 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/23 17:03:30 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

char			*ft_strdup(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char			*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

static int		get_nb_size(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	if (nb == 0)
		return (1);
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char			*ft_itoa(int nb)
{
	int		i;
	char	*res;

	i = get_nb_size(nb);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb == 0)
		return (ft_strdup("0"));
	if (!(res = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	i--;
	res[i + 1] = '\0';
	while (nb)
	{
		res[i] = ((nb % 10) + '0');
		i--;
		nb /= 10;
	}
	return (res);
}

char			*ft_itoa_name(char *str, int id)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_itoa(id);
	tmp2 = tmp;
	tmp = ft_strjoin(str, tmp);
	free(tmp2);
	return (tmp);
}
