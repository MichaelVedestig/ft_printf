/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvedesti <larsmtv@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:25:05 by mvedesti          #+#    #+#             */
/*   Updated: 2021/07/27 03:49:54 by mvedesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_files/ft_printf.h"
#include "header_files/libft.h"

t_list	*ft_initialize_list(t_list *info)
{
	info->character_count = 0;
	info->min_width = 0;
	info->max_width = 0;
	info->precision = 0;
	return (info);
}

int	ft_check_flags(const char *s, int i, t_list *info)
{
	short int	flags;

	flags = 0;
	if (s[i] == '%')
	{
		info->character_count += write(1, "%", 1);
		return (i);
	}
	while (!(ft_isalpha(s[i])))
	{
		if (s[i] == '-')
			flags = flags | LEFT_JUSTIFY;
		if (s[i] == '0' && (flags & LEFT_JUSTIFY) == 0)
			flags = flags | ZERO_PAD;
		if (s[i] == '+')
			flags = flags | PLUS_SIGN;
		if (s[i] == ' ' && (flags & PLUS_SIGN) == 0)
			flags = flags | INVIS_PLUS;
		if ((ft_isdigit(s[i]) || s[i] == '.') && s[i] != '0')
			i = ft_get_width(s, i, info);
		if (s[i] == '#')
			flags = flags | HEX_PREFIX;
		i++;
	}
	ft_read_descriptor(s, i, flags, info);
	ft_reset_list(info);
	return (i);
}

void	ft_reset_list(t_list *info)
{
	info->min_width = 0;
	info->max_width = 0;
	info->precision = 0;
}

void	ft_read_descriptor(const char *s, int i, short int flags, t_list *info)
{
	if (s[i] == 'c')
		ft_print_char(flags, info);
	if (s[i] == 's')
		ft_print_string(flags, info);
	if (s[i] == 'd' || s[i] == 'i')
		ft_print_int(flags, info);
	if (s[i] == 'u')
		ft_print_unsigned_int(flags, info);
	if (s[i] == 'p')
		ft_print_pointer(flags, info);
	if (s[i] == 'x')
		ft_print_hex(flags, info);
	if (s[i] == 'X')
		ft_print_heX(flags, info);
}

int	ft_printf(const char *s, ...)
{
	int		characters_printed;
	int		i;
	t_list	*info;

	if (!s)
		return (0);
	info = (t_list *)malloc(sizeof(t_list));
	if (!info)
		return (-1);
	ft_initialize_list(info);
	characters_printed = 0;
	i = 0;
	va_start(info->ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			i = ft_check_flags(s, i + 1, info);
		else
			characters_printed += write(1, &s[i], 1);
		i++;
	}
	characters_printed += info->character_count;
	va_end(info->ap);
	free(info);
	return (characters_printed);
}
