/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:58:11 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 17:23:03 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		ft_unit_lst_len(t_unit_test *lst)
{
	return ((lst == NULL) ? 0 : 1 + ft_unit_lst_len(lst->next));
}

int		main(void)
{
	int count;

	count = 0;
	system("touch resources/perm; chmod 000 resources/perm;");
	ft_putstr("---\n\n");
	ft_putendl("************************************");
	ft_putendl("**     42 - Ft_ssl Unit Tests     **");
	ft_putendl("************************************\n");
	count += general_tests_launcher();
	count += md5_launcher();
	count += sha256_launcher();
	ft_putnbr(count);
	ft_putendl("/3 suite tests passed\n");
	system("rm -rf resources/perm");
	return (count == 3? 0 : -1);
}