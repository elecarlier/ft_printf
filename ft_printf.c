/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:17:39 by ecarlier          #+#    #+#             */
/*   Updated: 2023/11/22 23:14:02 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "ft_printf.h"
#include <stdio.h>
int main() {
    int i = 0, j = 0;

    printf("\n### Test pour le format (char) ###\n");
    char char_value = 'A';
    i = ft_printf("Character: %c\n", char_value);
    j = printf("Character: %c\n", char_value);
    printf("Ma fonction : %i \noriginale   : %i\n", i, j);

    printf("\n### Test pour le format (string) ###\n");
    char *string_value = "Hello, World!";
    i = ft_printf("String: %s\n", string_value);
    j = printf("String: %s\n", string_value);
    printf("Ma fonction : %i \noriginale   : %i\n", i, j);

    printf("\n### Test pour le format (integer) ###\n");
    int int_value = 0;
    i = ft_printf("Integer: %i\n", int_value);
    j = printf("Decimal: %d\n", int_value);
    printf("Ma fonction : %i \noriginale   : %i\n", i, j);
    i = ft_printf("Integer: %i\n", int_value);
    j = printf("Decimal: %d\n", int_value);
    printf("Ma fonction : %i \noriginale   : %i\n", i, j);

    printf("\n### Test pour le format (hexadecimal lowercase) ###\n");
    unsigned int hex_value = 255;
    i = ft_printf("Hexadecimal (lowercase): %x\n", hex_value);
    j = printf("Hexadecimal (lowercase): %x\n", hex_value);
    printf("Ma fonction : %i \noriginale   : %i\n", i, j);

    printf("\n### Test pour le format (hexadecimal uppercase) ###\n");
    i = ft_printf("Hexadecimal (uppercase): %X\n", hex_value);
    j = printf("Hexadecimal (uppercase): %X\n", hex_value);
    printf("Ma fonction : %i \noriginale   : %i\n", i, j);

    // Test pour le signe %
    printf("\n### Test pour le signe %% ###\n");
    i = ft_printf("Percentage: %%\n");
    j = printf("Percentage: %%\n");
    printf("Ma fonction : %i \noriginale   : %i\n", i, j);

    return 0;
}



int	check_type(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 's')
		i = print_string(args);
	else if (c == 'i' || c == 'd')
		i = print_int(args);
	else if (c == 'u')
		i = print_unsigned(args);
	else if (c == 'c')
		i = print_char(args);
	else if (c == 'x' || c == 'X')
		i = print_hexa(args, c);
	else if (c == '%')
	{
		i = 1;
		ft_putchar_fd('%', 1);
	}
	return (i);

}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total_count;
	va_list	args;

	total_count = 0;
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			total_count += 1;
		}
		else
		{
			i++;
			total_count += check_type(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (total_count);
}
