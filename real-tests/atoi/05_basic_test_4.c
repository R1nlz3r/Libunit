/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_basic_test_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:27:51 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 15:27:53 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic_tests.h"

int		basic_test_4(void)
{
	if (atoi("-00076") == ft_atoi("-00076"))
		return (0);
	else
		return (-1);
}
