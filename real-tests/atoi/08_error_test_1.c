/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_error_test_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:17:45 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 17:19:35 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../real_tests.h"

int		error_test_1(void)
{
	if (atoi("roses are red") == ft_atoi("roses are red"))
		return (0);
	else
		return (-1);
}
