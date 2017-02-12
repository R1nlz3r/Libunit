/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_medium_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:03:51 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 17:18:40 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../real_tests.h"

int		medium_test(void)
{
	char	test[50001];

	test[50000] = '\0';
	ft_strfill(test, 'a', 49999);
	if (strlen(test) == ft_strlen(test))
		return (0);
	else
		return (-1);
}
