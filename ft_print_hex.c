/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvedesti <larsmtv@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 07:49:52 by mvedesti          #+#    #+#             */
/*   Updated: 2021/08/17 11:45:31 by mvedesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_files/ft_printf.h"
#include "header_files/libft.h"

char	*ft_prepend_zero(t_list *info, short int flags, char *str)
{
	int a;
	
	a = 0;
	if (flags & HEX_PREFIX)
		a = 2;
	if (info->precision == 1)
	{
		while (ft_strlen(str) < info->max_width)
			str = ft_strjoin(ft_strdup("0"), str);
	}
	else if (info->min_width > 0)
	{
		while (ft_strlen(str) < info->min_width - a)
			str = ft_strjoin(ft_strdup("0"), str);
	}
	return (str);
}

void	ft_pad_space(t_list *info, char *str)
{
	while (ft_strlen(str) < info->min_width)
	{
		info->character_count += write(1, " ", 1);
		info->min_width--;
	}
}

void	ft_print_hex(short int flags, t_list *info)
{
	unsigned int	n;
	char			*str;

	n = va_arg(info->ap, unsigned int);
	if ((n == 0) && (flags & HEX_PREFIX))
	{
		info->character_count += write(1, "0", 1);
		return ;
	}
	str = ft_itoa_hex(n);
	if ((flags & LEFT_JUSTIFY) == 0)
		str = ft_prepend_zero(info, flags, str);
	if (flags & HEX_PREFIX)
		str = ft_strjoin(ft_strdup("0x"), str);
	if (flags & LEFT_JUSTIFY)
		info->character_count += ft_putstr(str);
	ft_pad_space(info, str);
	if ((flags & LEFT_JUSTIFY) == 0)
		info->character_count += ft_putstr(str);
	free(str);
}

void	ft_print_heX(short int flags, t_list *info)
{
	unsigned int	n;
	char			*str;

	n = va_arg(info->ap, unsigned int);
	if ((n == 0) && (flags & HEX_PREFIX))
	{
		info->character_count += write(1, "0", 1);
		return ;
	}
	str = ft_str_toupper(ft_itoa_hex(n));
	if ((flags & LEFT_JUSTIFY) == 0)
		str = ft_prepend_zero(info, flags, str);
	if (flags & HEX_PREFIX)
		str = ft_strjoin(ft_strdup("0X"), str);
	if (flags & LEFT_JUSTIFY)
		info->character_count += ft_putstr(str);
	ft_pad_space(info, str);
	if ((flags & LEFT_JUSTIFY) == 0)
		info->character_count += ft_putstr(str);
	free(str);
}

void	ft_print_pointer(short int flags, t_list *info)
{
	unsigned long	n;
	char			*str;

	n = (unsigned long)va_arg(info->ap, void *);
	if (!n)
		n = 0;
	str = ft_itoa_hex_ulong(n);
	flags = flags | HEX_PREFIX;
	if ((flags & LEFT_JUSTIFY) == 0)
		str = ft_prepend_zero(info, flags, str);
	str = ft_strjoin(ft_strdup("0x"), str);
	if (flags & LEFT_JUSTIFY)
		info->character_count += ft_putstr(str);
	ft_pad_space(info, str);
	if ((flags & LEFT_JUSTIFY) == 0)
		info->character_count += ft_putstr(str);
	free(str);
}
