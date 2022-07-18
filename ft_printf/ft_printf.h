/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:02:50 by ggobert           #+#    #+#             */
/*   Updated: 2021/12/24 12:46:02 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int					ft_printf(const char *command, ...);
int					putchar_len(const char *command, int i, int len);
int					ft_intlen(int nbr);
int					ft_unsignedlen(unsigned int nbr);
int					print_function(const char *command, int i, va_list *arg);
int					print(const char *command, va_list *arg, int len, int pair);
int					print_c(va_list *arg);
int					print_s(va_list *arg);
int					print_p(va_list *arg);
int					print_d_i(va_list *arg);
int					print_u(va_list *arg);
int					print_x(va_list *arg);
int					print_gx(va_list *arg);
int					ft_intbase_len(unsigned long long nbr, char *base);
int					ft_intbase_len_u(unsigned int nbr, char *base);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nbr);
void				ft_putnbr_base(unsigned long long nbr, char *base);
void				ft_putnbr_base_u(unsigned int nbr, char *base);
void				ft_putnbr_u(unsigned int nbr);
unsigned int		ft_strlen_u(char *str);
unsigned long long	ft_strlen(char *str);

#endif
