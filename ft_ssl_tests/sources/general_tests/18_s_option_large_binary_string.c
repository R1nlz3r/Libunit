/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_s_option_large_binary_string.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:05:12 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:31:06 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_s_option_large_binary_string(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/general_tests/18");
	system("touch trace/general_tests/18/stdout00 trace/general_tests/18/stdout01 \
trace/general_tests/18/stderr00 trace/general_tests/18/stderr01");

	ret_val = system("string=`head -c 100000 resources/large_binary_file`; \
" FT_SSL_PATH "md5 -s \"$string\" \
1> trace/general_tests/18/stdout00 2> trace/general_tests/18/stderr00");

	ret_val2 = system("string=`head -c 100000 resources/large_binary_file`; \
md5 -s \"$string\" 1> trace/general_tests/18/stdout01 2> trace/general_tests/18/stderr01");

	leaks_ret_val = system("\
string=`head -c 100000 \resources/large_binary_file`; \
" FT_SSL_LEAK_REPORT_PATH "md5 -s \"$string\"");
	system("mv leak_report trace/general_tests/18/leak_report");

	if (system("diff trace/general_tests/18/stdout00 trace/general_tests/18/stdout01")
		|| system("diff trace/general_tests/18/stderr00 trace/general_tests/18/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
