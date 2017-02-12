/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 12:03:17 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 19:02:19 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		tests_launcher(void)
{
	t_unit_test	*testlist;
	int			valid_test;
	int			lst_len;

	testlist = NULL;
	ft_putendl("TESTS:");
	load_test(&testlist, "time_out_test", &timeout_test);
	load_test(&testlist, "floating_point_exception_test",
		&floating_point_exception_test);
	load_test(&testlist, "abort_test", &abort_test);
	load_test(&testlist, "bus_error_test", &bus_error_test);
	load_test(&testlist, "segfault_test", &segfault_test);
	load_test(&testlist, "ko_test", &ko_test);
	load_test(&testlist, "ok_test", &ok_test);
	valid_test = launch_tests(&testlist);
	ft_putnbr(valid_test);
	ft_putchar('/');
	lst_len = ft_unit_lst_len(testlist);
	ft_putnbr(lst_len);
	ft_putstr(" tests checked\n\n");
	return (lst_len == valid_test);
}
