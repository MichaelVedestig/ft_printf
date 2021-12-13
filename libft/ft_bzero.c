/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvedesti <larsmtv@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:39:38 by mvedesti          #+#    #+#             */
/*   Updated: 2021/07/19 14:02:54 by mvedesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/ft_printf.h"
#include "../header_files/libft.h"

void	ft_bzero(char *str, size_t n)
{
	char	*c;
	size_t	i;

	c = str;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
