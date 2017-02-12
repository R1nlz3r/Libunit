/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:47:12 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 12:56:39 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic_tests.h"

int atoi_launcher(void)
{
	t_unit_test	*testlist;
	int			valid_test;
	int			lst_len;

	testlist = NULL;
	ft_putendl("ATOI:");
	load_test(&testlist, "intmax_test", &intmax_test);
	load_test(&testlist, "intmin_test", &intmin_test);
	load_test(&testlist, "tab_test", &tab_test);
	load_test(&testlist, "error_test_2", &error_test_2);
	load_test(&testlist, "error_test_1", &error_test_1);
	load_test(&testlist, "space_test_2", &space_test_2);
	load_test(&testlist, "space_test_1", &space_test_1);
	load_test(&testlist, "basic_test_4", &basic_test_4);
	load_test(&testlist, "basic_test_3", &basic_test_3);
	load_test(&testlist, "basic_test_2", &basic_test_2);
	load_test(&testlist, "basic_test_1", &basic_test_1);
	load_test(&testlist, "void_test", &void_test);
	valid_test = launch_tests(&testlist);
	ft_putnbr(valid_test);
	ft_putchar('/');
	lst_len = ft_unit_lst_len(testlist);
	ft_putnbr(lst_len);
	ft_putstr(" tests checked\n\n");
	return(lst_len == valid_test);
}
