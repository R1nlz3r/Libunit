/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_s_option_medium_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:05:07 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:30:34 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_s_option_medium_string(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/general_tests/14");
	system("touch trace/general_tests/14/stdout00 trace/general_tests/14/stdout01 \
trace/general_tests/14/stderr00 trace/general_tests/14/stderr01");

	ret_val = system("string=`cat resources/medium_file`; \
" FT_SSL_PATH "md5 -s \"$string\" \
1> trace/general_tests/14/stdout00 2> trace/general_tests/14/stderr00");

	ret_val2 = system("string=`cat resources/medium_file`; \
md5 -s \"$string\" 1> trace/general_tests/14/stdout01 2> trace/general_tests/14/stderr01");

	leaks_ret_val = system("string=`cat resources/medium_file`; \
" FT_SSL_LEAK_REPORT_PATH "md5 -s \"$string\"");
	system("mv leak_report trace/general_tests/14/leak_report");

	if (system("diff trace/general_tests/14/stdout00 trace/general_tests/14/stdout01")
		|| system("diff trace/general_tests/14/stderr00 trace/general_tests/14/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
