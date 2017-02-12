/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_floating_point_exception_test.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:02:08 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 17:09:51 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		floating_point_exception_test(void)
{
	int		n;

	n = 0;
	if ((1 / n))
		return (0);
	else
		return (-1);
}
