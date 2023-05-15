/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:42:28 by yeomin            #+#    #+#             */
/*   Updated: 2023/05/14 14:44:57 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_lencheck(int num);
int		ft_putnbr(int nb);
void	ft_lln_len(unsigned long long ll_n, int *p_l, unsigned long long b_l);
int		ft_idu_check(va_list *ap, const char format);
int		ft_c_and_s_check(va_list *ap, const char format);
int		ft_p_check(va_list *ap, const char format);
int		ft_x_check(va_list *ap, const char format);
int		ft_dec_print(unsigned long long ll_num, const char format);
int		ft_hex_print(unsigned long long ll_n, const char format);
int		ft_format_check(va_list *ap, const char format);
int		ft_print_check(va_list *ap, const char *format, int i);
int		ft_error_check(va_list ap, int print_len, int count);

#endif