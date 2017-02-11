/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:26:12 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/11 14:10:53 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic_tests.h"

int		null_test(void)
{
	char	*test;

	test = NULL;
	if (strlen(test) == ft_strlen(test))
		return (0);
	else
		return (-1);
}
