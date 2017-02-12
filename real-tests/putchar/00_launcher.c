/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:33:56 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/12 21:13:23 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../real_tests.h"

int		putchar_launcher(void)
{
	t_unit_test	*testlist;
	int			valid_test;
	int			lst_len;

	testlist = NULL;
	ft_putendl("PUTCHAR");
	load_test(&testlist, "backslash_test", &backslash_test_putchar);
	load_test(&testlist, "basic_test", &basic_test_putchar);
	valid_test = launch_tests(&testlist);
	ft_putnbr(valid_test);
	ft_putchar('/');
	lst_len = ft_unit_lst_len(testlist);
	ft_putnbr(lst_len);
	ft_putstr(" tests checked\n\n");
	return (lst_len == valid_test);
}
