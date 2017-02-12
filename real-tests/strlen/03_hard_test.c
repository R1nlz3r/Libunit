/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_hard_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:12:41 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 07:46:59 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic_tests.h"

int		hard_test(void)
{
	char	test[200001];

	test[200000] = '\0';
	ft_strfill(test, 'a', 199999);
	if (strlen(test) == ft_strlen(test))
		return (0);
	else
		return (-1);
}
