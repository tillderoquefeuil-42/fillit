/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:17:00 by nflores           #+#    #+#             */
/*   Updated: 2015/12/01 14:27:38 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_nbchar(int n)
{
	int ret;
	int nb;

	nb = n;
	ret = 1;
	if (nb < 0)
	{
		ret++;
		nb = -nb;
	}
	while (nb > 9)
	{
		ret += 1;
		nb /= 10;
	}
	return (ret);
}

static int	ft_pow(int n, int p)
{
	int i;
	int nb;

	i = 1;
	nb = n;
	while (i < p)
	{
		nb *= n;
		i++;
	}
	return (nb);
}

static char	*ft_itoa_m(void)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * 12);
	if (!ret)
		return (NULL);
	ret[0] = '-';
	ret[1] = '2';
	ret[2] = '1';
	ret[3] = '4';
	ret[4] = '7';
	ret[5] = '4';
	ret[6] = '8';
	ret[7] = '3';
	ret[8] = '6';
	ret[9] = '4';
	ret[10] = '8';
	ret[11] = '\0';
	return (ret);
}

static char	*ft_itoa_o(int n)
{
	char	*ret;
	int		i;
	int		nb;

	i = 0;
	nb = n;
	ret = (char *)malloc(sizeof(char) * ft_nbchar(n) + 1);
	if (!ret)
		return (NULL);
	if (n < 0)
	{
		ret[0] = '-';
		i++;
		n = -n;
	}
	while (i < ft_nbchar(nb))
	{
		ret[i] = 48 + (n / ft_pow(10, ft_nbchar(nb) - i - 1));
		n %= ft_pow(10, ft_nbchar(nb) - i - 1);
		i++;
	}
	ret[i - 1] = 48 + n % 10;
	ret[i] = '\0';
	return (ret);
}

char		*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_itoa_m());
	return (ft_itoa_o(n));
}
