/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiqueir <tsiqueir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:58:03 by tsiqueir          #+#    #+#             */
/*   Updated: 2025/04/12 14:19:13 by tsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <ctype.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/inc/libft.h"

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"
# define INT_BASE "0123456789"

int	ft_printf(const char *format, ...);

#endif
