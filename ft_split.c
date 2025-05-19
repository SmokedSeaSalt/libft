/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:59:08 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/05/01 15:17:46 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_nstr(char const *s, char c)
{
	int	nstr;
	int	instr;
	int	i;

	i = 0;
	nstr = 0;
	instr = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && instr == 0)
		{
			nstr++;
			instr = 1;
		}
		else if (s[i] == c)
		{
			instr = 0;
		}
		i++;
	}
	return (nstr);
}

static void	*ft_free(char **ret, int iret)
{
	while (iret >= 0)
	{
		free(ret[iret]);
		iret--;
	}
	free(ret);
	return (NULL);
}

static void	ft_init_vars(int *iret, size_t *i, int *startstr)
{
	*iret = 0;
	*i = 0;
	*startstr = -1;
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		iret;
	size_t	i;
	int		startstr;

	ft_init_vars(&iret, &i, &startstr);
	ret = ft_calloc((ft_nstr(s, c) + 1), sizeof(char *));
	if (ret == NULL)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && startstr < 0)
			startstr = i;
		else if ((s[i] == c || s[i] == '\0') && startstr >= 0)
		{
			ret[iret] = ft_substr(s, startstr, i - startstr);
			if (ret[iret] == NULL)
				return (ft_free(ret, iret));
			iret++;
			startstr = -1;
		}
		i++;
	}
	return (ret);
}
