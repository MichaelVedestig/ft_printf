/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvedesti <larsmtv@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 07:53:40 by mvedesti          #+#    #+#             */
/*   Updated: 2021/07/16 02:51:57 by mvedesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/ft_printf.h"
#include "../header_files/libft.h"

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
