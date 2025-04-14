/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiqueir <tsiqueir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:56:43 by tsiqueir          #+#    #+#             */
/*   Updated: 2024/12/09 20:27:41 by tsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int value)
{
	if (value >= '0' && value <= '9')
		return (1);
	return (0);
}

/* #include <stdio.h>
int main(void)
{
	printf("ft_isdigit('3'): %d\n", ft_isdigit('3'));
	printf("ft_isdigit('A'): %d\n", ft_isdigit('A'));
	printf("\n");
} */
