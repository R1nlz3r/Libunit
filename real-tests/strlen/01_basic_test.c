/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:45:18 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/11 14:53:42 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic_tests.h"

int		basic_test(void)
{
	char	test[20];
	size_t	my_res;
	size_t	strlen_res;

	ft_strfill(test, 'a', 20);
	strlen_res = strlen(test);
	my_res = ft_strlen(test);
	ft_putnbr(strlen_res);
	ft_putnbr(my_res);
	if (my_res == strlen_res)
		return (0);
	else
		return (-1);
}
