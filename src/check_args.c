/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:36:41 by svillalv          #+#    #+#             */
/*   Updated: 2023/06/29 18:24:10 by svillalv         ###   ########.fr       */
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

int	ft_check_args(int ac, char **av, t_philo_args *args)
{
	int i;
	int j;

	i = 1;
	if (ac < 5 || ac > 6)
		return (1);
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (1);
		if (ft_atoi(av[i]) < 0)
			return (1);
		j = -1;
		while (av[i][++j] != '\0')
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
		}
		ft_fill_struct(i, av[i], args);
		i++;
	}
	return (0);
}

void	ft_fill_struct(int ac, char *av, t_philo_args *args)
{
	if (ac == 1)
		args->num_of_philos = ft_atoi(av);
	else if (ac == 2)
		args->time_to_die = ft_atoi(av);
	else if (ac == 3)
		args->time_to_eat = ft_atoi(av);
	else if (ac == 4)
		args->time_to_sleep = ft_atoi(av);
	args->num_of_eats = -1;
	if (ac == 5)
		args->num_of_eats = ft_atoi(av);
}
