/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:33:56 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/11 14:24:43 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic_tests.h"

int strlen_launcher(void)
{
	t_unit_test *testlist;

	testlist = NULL;
	ft_putendl("STRLEN:");
	load_test(&testlist, "test4", &null_test);
	load_test(&testlist, "test3", &hard_test);
	load_test(&testlist, "test2", &medium_test);
	load_test(&testlist, "test1", &basic_test);
	return(launch_tests(&testlist));
}
