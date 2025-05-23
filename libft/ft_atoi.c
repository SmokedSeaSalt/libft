/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:06:24 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/05/01 14:46:16 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
	{
		return (c);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		nflag;
	long	result;

	result = 0;
	i = 0;
	nflag = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		nflag = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i] != '\0')
	{
		result *= 10;
		result += (nptr[i] - '0');
		i++;
	}
	return ((int) result * nflag);
}
