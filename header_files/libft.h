/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvedesti <larsmtv@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:31:01 by mvedesti          #+#    #+#             */
/*   Updated: 2021/07/24 19:04:53 by mvedesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(char *str, size_t n);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
char	*ft_uitoa(unsigned int n);
char	*ft_itoa(long long n);
char	*ft_itoa_hex(unsigned int n);
char	*ft_itoa_hex_ulong(unsigned long n);
char	*ft_strdup(const char *s);
char	*ft_strncpy(char *dest, const char *src, int n);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_str_toupper(char *str);
int		ft_strlen(const char *s);
int		ft_num_len(long long nl);
int		ft_putstr(const char *s);
void	ft_putnbr(int n);

#endif