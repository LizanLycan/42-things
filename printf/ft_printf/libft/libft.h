/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:40:28 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/22 13:45:16 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

int		ft_putnbr_fd(int n, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_putulongnbr_hex_fd(unsigned long int n, int fd);
int		ft_putnbr_hex_lower_fd(unsigned int nbr, int fd);
int		ft_putnbr_hex_upper_fd(unsigned int nbr, int fd);

#endif