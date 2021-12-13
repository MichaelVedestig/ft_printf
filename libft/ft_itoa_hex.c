/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvedesti <larsmtv@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:21:04 by mvedesti          #+#    #+#             */
/*   Updated: 2021/07/26 01:41:26 by mvedesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/ft_printf.h"
#include "../header_files/libft.h"

static int	ft_num_len_hex(unsigned long nl)
{
	int	i;

	i = 1;
	while (nl >= 16)
	{
		nl /= 16;
		i++;
	}
	return (i);
}

static char	*ft_convert(unsigned long nl, int len, char *str)
{
	char	*hex;

	hex = "0123456789abcdef";
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = hex[nl % 16];
		nl /= 16;
		len--;
	}
	return (str);
}

char	*ft_itoa_hex(unsigned int n)
{
	char			*str;
	int				len;

	len = ft_num_len_hex(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str = ft_convert(n, len, str);
	return (str);
}

char	*ft_itoa_hex_ulong(unsigned long n)
{
	char			*str;
	int				len;

	len = ft_num_len_hex(n);
	str = (char *)calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str = ft_convert(n, len, str);
	return (str);
}
