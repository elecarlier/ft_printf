/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:37:32 by ecarlier          #+#    #+#             */
/*   Updated: 2023/11/22 22:20:33 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *, ...);
int		print_string(va_list str);
int		print_hexa(va_list args, char c);
int		print_char(va_list args);
int		print_int(va_list args);
int		print_unsigned(va_list args);
int		check_type(char c, va_list args);

#endif
