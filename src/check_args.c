/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:36:41 by svillalv          #+#    #+#             */
/*   Updated: 2023/06/28 19:37:22 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	if (!str)
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' && str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

int	check_args(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	if (ac < 6 || ac > 7)
		return (1);
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 0)
			return (1);
		j = -1;
		while (av[i][++j] != '\0')
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
		}
		i++;
	}
	return (0);
}
