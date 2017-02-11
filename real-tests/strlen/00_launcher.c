/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:33:56 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/11 18:17:45 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic_tests.h"

int strlen_launcher(void)
{
	t_unit_test	*testlist;
	int			valid_test;

	testlist = NULL;
	ft_putendl("STRLEN:");
	load_test(&testlist, "test4", &null_test);
	load_test(&testlist, "test3", &hard_test);
	load_test(&testlist, "test2", &medium_test);
	load_test(&testlist, "test1", &basic_test);
	valid_test = launch_tests(&testlist);
	ft_putnbr(valid_test);
	ft_putchar('/');
	ft_putnbr(ft_unit_lst_len(testlist));
	ft_putstr(" tests checked\n\n");
	return(valid_test);
}
