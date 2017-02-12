/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_void_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 20:56:19 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 21:11:17 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../real_tests.h"

int		backslash_test_putchar(void)
{
	char	test;
	char	test2;
	int		p[2];
	int		out;
	char	backslash;

	test = 0;
	test2 = 1;
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	backslash = '\0';
	ft_putchar(backslash);
	read(p[0], &test, 1);
	write(1, &backslash, 1);
	read(p[0], &test2, 1);
	dup2(1, out);
	if (test == test2)
		return (0);
	else
		return (-1);
}
