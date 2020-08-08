/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:58:20 by mapandel          #+#    #+#             */
/*   Updated: 2020/08/08 19:37:56 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAL_TESTS_H
# define REAL_TESTS_H

# include "libunit.h"

# define FT_SSL_PATH "Ft_ssl/ft_ssl "
# define FT_SSL_LEAK_REPORT_PATH "Ft_ssl/ft_ssl_leak_report "

int		ft_unit_lst_len(t_unit_test *lst);

int		general_tests_launcher(void);
int		no_argument(void);
int		invalid_command(void);
int		md5_p_option_small_file(void);
int		md5_p_option_medium_file(void);
int		md5_p_option_large_file(void);
int		md5_p_option_small_binary_file(void);
int		md5_p_option_medium_binary_file(void);
int		md5_p_option_large_binary_file(void);
int		md5_p_option_dev_null(void);
int		md5_p_option_empty_file(void);
int		md5_q_option(void);
int		md5_r_option(void);
int		md5_s_option_small_string(void);
int		md5_s_option_medium_string(void);
int		md5_s_option_large_string(void);
int		md5_s_option_small_binary_string(void);
int		md5_s_option_medium_binary_string(void);
int		md5_s_option_large_binary_string(void);
int		md5_s_option_empty_string(void);
int		md5_s_option_no_argument(void);
int		md5_error_missing_file(void);
int		md5_error_directory(void);
int		md5_error_no_permission(void);
int		md5_end_of_options(void);
int		md5_options_multiple_p(void);
int		md5_options_p_and_s(void);
int		md5_options_q_and_r(void);
int		md5_options_s_into_end_of_options(void);
int		md5_options_mixup(void);

int		md5_launcher(void);
int		md5_small_file(void);
int		md5_medium_file(void);
int		md5_large_file(void);
int		md5_small_binary_file(void);
int		md5_medium_binary_file(void);
int		md5_large_binary_file(void);
int		md5_dev_null(void);
int		md5_empty_file(void);
int		md5_piped_small_file(void);
int		md5_piped_medium_file(void);
int		md5_piped_large_file(void);
int		md5_piped_small_binary_file(void);
int		md5_piped_medium_binary_file(void);
int		md5_piped_large_binary_file(void);
int		md5_piped_dev_null(void);
int		md5_piped_empty_file(void);
int		md5_no_argument_small_file(void);
int		md5_no_argument_medium_file(void);
int		md5_no_argument_large_file(void);
int		md5_no_argument_small_binary_file(void);
int		md5_no_argument_medium_binary_file(void);
int		md5_no_argument_large_binary_file(void);
int		md5_no_argument_dev_null(void);
int		md5_no_argument_empty_file(void);
int		md5_multiple_files(void);
int		md5_multiple_files_with_errors(void);
int		md5_multiple_binary_files(void);
int		md5_multiple_binary_files_with_errors(void);
int		md5_multiple_files_mixup(void);
int		md5_multiple_files_mixup_with_errors(void);

int		sha256_launcher(void);
int		sha256_small_file(void);
int		sha256_medium_file(void);
int		sha256_large_file(void);
int		sha256_small_binary_file(void);
int		sha256_medium_binary_file(void);
int		sha256_large_binary_file(void);
int		sha256_dev_null(void);
int		sha256_empty_file(void);
int		sha256_piped_small_file(void);
int		sha256_piped_medium_file(void);
int		sha256_piped_large_file(void);
int		sha256_piped_small_binary_file(void);
int		sha256_piped_medium_binary_file(void);
int		sha256_piped_large_binary_file(void);
int		sha256_piped_dev_null(void);
int		sha256_piped_empty_file(void);
int		sha256_no_argument_small_file(void);
int		sha256_no_argument_medium_file(void);
int		sha256_no_argument_large_file(void);
int		sha256_no_argument_small_binary_file(void);
int		sha256_no_argument_medium_binary_file(void);
int		sha256_no_argument_large_binary_file(void);
int		sha256_no_argument_dev_null(void);
int		sha256_no_argument_empty_file(void);
int		sha256_multiple_files(void);
int		sha256_multiple_binary_files(void);
int		sha256_multiple_files_mixup(void);

int		sha512_launcher(void);
int		sha512_small_file(void);
int		sha512_medium_file(void);
int		sha512_large_file(void);
int		sha512_small_binary_file(void);
int		sha512_medium_binary_file(void);
int		sha512_large_binary_file(void);
int		sha512_dev_null(void);
int		sha512_empty_file(void);
int		sha512_piped_small_file(void);
int		sha512_piped_medium_file(void);
int		sha512_piped_large_file(void);
int		sha512_piped_small_binary_file(void);
int		sha512_piped_medium_binary_file(void);
int		sha512_piped_large_binary_file(void);
int		sha512_piped_dev_null(void);
int		sha512_piped_empty_file(void);
int		sha512_no_argument_small_file(void);
int		sha512_no_argument_medium_file(void);
int		sha512_no_argument_large_file(void);
int		sha512_no_argument_small_binary_file(void);
int		sha512_no_argument_medium_binary_file(void);
int		sha512_no_argument_large_binary_file(void);
int		sha512_no_argument_dev_null(void);
int		sha512_no_argument_empty_file(void);
int		sha512_multiple_files(void);
int		sha512_multiple_binary_files(void);
int		sha512_multiple_files_mixup(void);

#endif
