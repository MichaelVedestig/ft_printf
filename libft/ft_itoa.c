/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvedesti <larsmtv@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:21:04 by mvedesti          #+#    #+#             */
/*   Updated: 2021/07/26 01:12:32 by mvedesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/ft_printf.h"
#include "../header_files/libft.h"

int	ft_num_len(long long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	char	*ft_convert(long long int n, int len, char *str)
{
	str[len] = '\0';
	while (n > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(long long n)
{
	char			*str;
	int				len;
	
	if (n < 0)
		n *= -1;
	len = ft_num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str = ft_convert(n, len, str);
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				len;
	long long	num;

	num = (long long)n;
	len = ft_num_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	str = ft_convert(num, len, str);
	return (str);
}
