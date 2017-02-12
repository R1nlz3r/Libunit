/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:45:18 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 21:08:45 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../real_tests.h"

int		basic_test_putchar(void)
{
	char	test;
	char	test2;
	int		p[2];
	int		out;
	char	c;

	test = 0;
	test2 = 1;
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putchar('c');
	read(p[0], &test, 1);
	c = 'c';
	write(1, &c, 1);
	read(p[0], &test2, 1);
	dup2(1, out);
	if (test == test2)
		return (0);
	else
		return (-1);
}
