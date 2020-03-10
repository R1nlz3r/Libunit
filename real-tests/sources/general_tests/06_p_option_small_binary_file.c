/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_p_option_small_binary_file.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:53:32 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:30:07 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_p_option_small_binary_file(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/general_tests/06");
	system("touch trace/general_tests/06/stdout00 trace/general_tests/06/stdout01 \
trace/general_tests/06/stderr00 trace/general_tests/06/stderr01");

	ret_val = system("cat resources/small_binary_file | "FT_SSL_PATH "md5 -p \
1> trace/general_tests/06/stdout00 2> trace/general_tests/06/stderr00");

	ret_val2 = system("cat resources/small_binary_file | md5 -p \
1> trace/general_tests/06/stdout01 2> trace/general_tests/06/stderr01");

	leaks_ret_val = system("cat resources/small_binary_file | \
"FT_SSL_LEAK_REPORT_PATH "md5 -p");
	system("mv leak_report trace/general_tests/06/leak_report");

	if (system("diff trace/general_tests/06/stdout00 trace/general_tests/06/stdout01")
		|| system("diff trace/general_tests/06/stderr00 trace/general_tests/06/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
