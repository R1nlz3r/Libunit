/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_intmax_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:25:40 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/11 14:11:49 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic_tests.h"

int		intmin_test(void)
{
	if (atoi("2147483647") == ft_atoi("2147483647"))
		return (0);
	else
		return (-1);
}
