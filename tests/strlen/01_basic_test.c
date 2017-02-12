/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:45:18 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 07:45:11 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic_tests.h"

int		basic_test(void)
{
	char	test[21];
	size_t	my_res;
	size_t	strlen_res;

	test[20] = '\0';
	ft_strfill(test, 'a', 19);
	strlen_res = strlen(test);
	my_res = ft_strlen(test);
	if (my_res == strlen_res)
		return (0);
	else
		return (-1);
}
