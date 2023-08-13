/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:11:57 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/13 22:14:55 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		ft_putchar(str[i]);
	}
}

int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_atoi(char *a)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(a[i]))
		i++;
	while (a[i] == '-' || a[i] == '+')
	{
		if (a[i] == '-')
			sign = -1;
		i++;
	}
	while (a[i] >= '0' && a[i] <= '9')
	{
		res *= 10;
		res += a[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

inline void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}
