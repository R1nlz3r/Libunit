/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_hard_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:12:41 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/11 14:10:50 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic_tests.h"

int		hard_test(void)
{
	char	*test[200000000];

	test = ft_strfill(test, 'a', 200000000);
	if (strlen(test) == ft_strlen(test))
		return (0);
	else
		return (-1);
}
