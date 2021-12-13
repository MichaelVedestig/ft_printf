/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvedesti <larsmtv@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:58:32 by mvedesti          #+#    #+#             */
/*   Updated: 2021/08/16 23:26:55 by mvedesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_files/ft_printf.h"
#include "header_files/libft.h"

int	ft_get_width(const char *s, int i, t_list *info)
{
	if (ft_isdigit(s[i]))
		info->min_width = ft_atoi(&s[i]);
	while (ft_isalpha(s[i]) == 0 && s[i] != '.')
		i++;
	if (s[i] == '.')
	{
		info->precision = 1;
		i++;
		if (ft_isdigit(s[i]))
			info->max_width = ft_atoi(&s[i]);
	}
	while (ft_isalpha(s[i]) == 0)
		i++;
	return (i - 1);
}

void	ft_print_char(short int flags, t_list *info)
{
	char	c;

	c = (va_arg(info->ap, int));
	if (flags & LEFT_JUSTIFY)
	{
		info->character_count += write(1, &c, 1);
		info->min_width -= 1;
		while (info->min_width > 0)
		{
			info->character_count += write(1, " ", 1);
			info->min_width--;
		}
	}
	else
	{
		while (info->min_width > 1)
		{
			info->character_count += write(1, " ", 1);
			info->min_width--;
		}
		info->character_count += write(1, &c, 1);
	}
}

void	ft_print_string(short int flags, t_list *info)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	str = va_arg(info->ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (info->precision == 1 && info->max_width < len)
		len = info->max_width;
	while (len < info->min_width && (flags & LEFT_JUSTIFY) == 0)
		ft_pad_space(info, str);
	while (info->precision == 1 && i < info->max_width && i < len)
	{
		info->character_count += write(1, &str[i], 1);
		i++;
	}
	if (info->precision == 0)
		info->character_count += ft_putstr(str);
	while (len < info->min_width)
		ft_pad(info, flags);
}

void	ft_pad(t_list *info, short int flags)
{
	char	space;

	space = ' ';
	if (flags & ZERO_PAD && (flags & LEFT_JUSTIFY) == 0)
		space = '0';
	info->character_count += write(1, &space, 1);
	info->min_width--;
	info->max_width--;
}
