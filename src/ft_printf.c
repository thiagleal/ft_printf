/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiqueir <tsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:56:07 by tsiqueir          #+#    #+#             */
/*   Updated: 2025/04/07 20:17:26 by tsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char c, char *str)
{
	if (c != 1)
		return (write(1, &c, 1));
	else if (str)
		return (write(1, str, ft_strlen(str)));
	else
		return (write(1, "(null)", 6));
	return (0);
}

static int	ft_printbase(const char *c, int base, size_t nbr)
{
	int	cont;

	cont = 0;
	if ((c[0] == 'd' || c[0] == 'i') && (long long)nbr < 0)
	{
		cont += ft_print('-', NULL);
		nbr = -((long long)nbr);
	}
	if (nbr == 0)
		return (ft_print('0', NULL));
	if (nbr >= (size_t)base)
		cont += ft_printbase(c, base, (nbr / base));
	cont += ft_print(c[nbr % base + 1], NULL);
	return (cont);
}

static int	ft_printptr(const char *hex, size_t ptr)
{
	if (!ptr)
		return (ft_print(1, "(nil)"));
	return (ft_print(1, "0x") + ft_printbase(hex, 16, ptr));
}

static int	ft_fillprintf(va_list args, const char format)
{
	if (format == 'c')
		return ((ft_print(va_arg(args, int), NULL)));
	else if (format == 's')
		return (ft_print(1, va_arg(args, char *)));
	else if (format == 'd')
		return (ft_printbase("d"INT_BASE, 10, va_arg(args, int)));
	else if (format == 'i')
		return (ft_printbase("i"INT_BASE, 10, va_arg(args, int)));
	else if (format == 'u')
		return (ft_printbase("u"INT_BASE, 10, va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_printbase("x"HEX_LOW_BASE, 16, va_arg(args, unsigned int)));
	else if (format == 'X')
		return (ft_printbase("x"HEX_UPP_BASE, 16, va_arg(args, unsigned int)));
	else if (format == 'p')
		return (ft_printptr("p"HEX_LOW_BASE, va_arg(args, size_t)));
	else if (format == '%')
		return (ft_print(format, NULL));
	else
	{
		ft_print('%', NULL);
		return (ft_print(format, NULL) + 1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		cont;
	int		str_cont;

	cont = 0;
	str_cont = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[str_cont])
	{
		if (str[str_cont] == '%')
		{
			cont += ft_fillprintf(args, str[str_cont + 1]);
			str_cont++;
		}
		else
			cont += ft_print(str[str_cont], NULL);
		str_cont++;
	}
	va_end(args);
	return (cont);
}
