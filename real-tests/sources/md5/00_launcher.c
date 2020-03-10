/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:47:12 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:06:29 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_launcher(void)
{
	t_unit_test	*testlist;
	int			valid_test;
	int			lst_len;

	testlist = NULL;
	ft_putendl("MD5 TESTS:");

	// MULTIPLE FILES
	load_test(&testlist, "multiple_files_mixup_with_errors", &md5_multiple_files_mixup_with_errors);
	load_test(&testlist, "multiple_files_mixup", &md5_multiple_files_mixup);
	load_test(&testlist, "multiple_binary_files_with_errors", &md5_multiple_binary_files_with_errors);
	load_test(&testlist, "multiple_binary_files", &md5_multiple_binary_files);
	load_test(&testlist, "multiple_files_with_errors", &md5_multiple_files_with_errors);
	load_test(&testlist, "multiple_files", &md5_multiple_files);

	// NO ARGUMENT
	load_test(&testlist, "no_argument_empty_file", &md5_no_argument_empty_file);
	load_test(&testlist, "no_argument_dev_null", &md5_no_argument_dev_null);
	load_test(&testlist, "no_argument_large_binary_file", &md5_no_argument_large_binary_file);
	load_test(&testlist, "no_argument_medium_binary_file", &md5_no_argument_medium_binary_file);
	load_test(&testlist, "no_argument_small_binary_file", &md5_no_argument_small_binary_file);
	load_test(&testlist, "no_argument_large_file", &md5_no_argument_large_file);
	load_test(&testlist, "no_argument_medium_file", &md5_no_argument_medium_file);
	load_test(&testlist, "no_argument_small_file", &md5_no_argument_small_file);

	// PIPED FILES
	load_test(&testlist, "piped_empty_file", &md5_piped_empty_file);
	load_test(&testlist, "piped_dev_null", &md5_piped_dev_null);
	load_test(&testlist, "piped_large_binary_file", &md5_piped_large_binary_file);
	load_test(&testlist, "piped_medium_binary_file", &md5_piped_medium_binary_file);
	load_test(&testlist, "piped_small_binary_file", &md5_piped_small_binary_file);
	load_test(&testlist, "piped_large_file", &md5_piped_large_file);
	load_test(&testlist, "piped_medium_file", &md5_piped_medium_file);
	load_test(&testlist, "piped_small_file", &md5_piped_small_file);

	// REGULAR TESTS
	load_test(&testlist, "empty_file", &md5_empty_file);
	load_test(&testlist, "dev_null", &md5_dev_null);
	load_test(&testlist, "large_binary_file", &md5_large_binary_file);
	load_test(&testlist, "medium_binary_file", &md5_medium_binary_file);
	load_test(&testlist, "small_binary_file", &md5_small_binary_file);
	load_test(&testlist, "large_file", &md5_large_file);
	load_test(&testlist, "medium_file", &md5_medium_file);
	load_test(&testlist, "small_file", &md5_small_file);

	valid_test = launch_tests(&testlist);
	ft_putnbr(valid_test);
	ft_putchar('/');
	lst_len = ft_unit_lst_len(testlist);
	ft_putnbr(lst_len);
	ft_putstr(" tests checked\n\n");

	return (lst_len == valid_test);
}
