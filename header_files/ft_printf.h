/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvedesti <larsmtv@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:33:06 by mvedesti          #+#    #+#             */
/*   Updated: 2021/08/16 22:58:19 by mvedesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

# define LEFT_JUSTIFY		0b1
# define ZERO_PAD			0b10
# define PLUS_SIGN			0b100
# define INVIS_PLUS			0b1000
# define HEX_PREFIX			0b10000
# define MAX_WIDTH			0B100000

typedef struct s_list
{
	va_list			ap;
	int				character_count;
	int				min_width;
	int				max_width;
	int				precision;
}					t_list;

int			ft_printf(const char *format, ...);
t_list		*ft_initialize_list(t_list *info);
int			ft_get_width(const char *s, int i, t_list *info);
int			ft_check_flags(const char *format, int i, t_list *info);
void		ft_read_descriptor(const char *s, int i, short int flags, t_list *info);
char		*ft_negative_ulong(char *str);
void		ft_reset_list(t_list *info);
char		*ft_prepend_zero(t_list *info, short int flags, char *str);
void		ft_print_string(short int flags, t_list *info);
char		*ft_attach_sign(short int flags, char *str, long long num);
void		ft_print_char(short int flags, t_list *info);
void		ft_print_hex(short int flags, t_list *info);
void		ft_print_heX(short int flags, t_list *info);
void		ft_print_pointer(short int flags, t_list *info);
void		ft_print_int(short int flags, t_list *info);
void		ft_print_unsigned_int(short int flags, t_list *info);
void		ft_pad(t_list *info, short int flags);
void		ft_pad_space(t_list *info, char *str);

#endif