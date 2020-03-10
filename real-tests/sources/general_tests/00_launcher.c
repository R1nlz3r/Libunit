/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:47:12 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:06:56 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		general_tests_launcher(void)
{
	t_unit_test	*testlist;
	int			valid_test;
	int			lst_len;

	testlist = NULL;
	ft_putendl("GENERAL TESTS:");

	// MULTIPLE OPTIONS
	load_test(&testlist, "options_mixup", &md5_options_mixup);
	load_test(&testlist, "options_s_into_end_of_options", &md5_options_s_into_end_of_options);
	load_test(&testlist, "options_q_and_r", &md5_options_q_and_r);
	load_test(&testlist, "options_p_and_s", &md5_options_p_and_s);
	load_test(&testlist, "options_double_p", &md5_options_multiple_p);
	load_test(&testlist, "end_of_options", &md5_end_of_options);

	// ERRORS
	load_test(&testlist, "error_no_permission", &md5_error_no_permission);
	load_test(&testlist, "error_directory", &md5_error_directory);
	load_test(&testlist, "error_missing_file", &md5_error_missing_file);

	// S OPTION
	// s option string following the option
	load_test(&testlist, "s_option_no_argument", &md5_s_option_no_argument);
	load_test(&testlist, "s_option_empty_string", &md5_s_option_empty_string);
	load_test(&testlist, "s_option_large_binary_string", &md5_s_option_large_binary_string);
	load_test(&testlist, "s_option_medium_binary_string", &md5_s_option_medium_binary_string);
	load_test(&testlist, "s_option_small_binary_string", &md5_s_option_small_binary_string);
	load_test(&testlist, "s_option_large_string", &md5_s_option_large_string);
	load_test(&testlist, "s_option_medium_string", &md5_s_option_medium_string);
	load_test(&testlist, "s_option_small_string", &md5_s_option_small_string);

	// DISPLAY OPTIONS
	load_test(&testlist, "r_option", &md5_r_option);
	load_test(&testlist, "q_option", &md5_q_option);

	// P OPTION
	load_test(&testlist, "p_option_empty_file", &md5_p_option_empty_file);
	load_test(&testlist, "p_option_dev_null", &md5_p_option_dev_null);
	load_test(&testlist, "p_option_large_binary_file", &md5_p_option_large_binary_file);
	load_test(&testlist, "p_option_medium_binary_file", &md5_p_option_medium_binary_file);
	load_test(&testlist, "p_option_small_binary_file", &md5_p_option_small_binary_file);
	load_test(&testlist, "p_option_large_file", &md5_p_option_large_file);
	load_test(&testlist, "p_option_medium_file", &md5_p_option_medium_file);
	load_test(&testlist, "p_option_small_file", &md5_p_option_small_file);

	// BASIC TESTS
	load_test(&testlist, "invalid_command", &invalid_command);
	load_test(&testlist, "no_argument", &no_argument);

	valid_test = launch_tests(&testlist);
	ft_putnbr(valid_test);
	ft_putchar('/');
	lst_len = ft_unit_lst_len(testlist);
	ft_putnbr(lst_len);
	ft_putstr(" tests checked\n\n");
	return (lst_len == valid_test);
}
