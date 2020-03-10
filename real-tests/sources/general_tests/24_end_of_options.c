/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24_end_of_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:21:01 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:31:30 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_end_of_options(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/general_tests/24");
	system("touch trace/general_tests/24/stdout00 trace/general_tests/24/stdout01 \
trace/general_tests/24/stderr00 trace/general_tests/24/stderr01");

	ret_val = system("cat resources/small_file | "FT_SSL_PATH "md5 -- \
1> trace/general_tests/24/stdout00 2> trace/general_tests/24/stderr00");

	ret_val2 = system("cat resources/small_file | md5 -- \
1> trace/general_tests/24/stdout01 2> trace/general_tests/24/stderr01");

	leaks_ret_val = system("cat resources/small_file | \
"FT_SSL_LEAK_REPORT_PATH "md5 --");
	system("mv leak_report trace/general_tests/24/leak_report");

	if (system("diff trace/general_tests/24/stdout00 trace/general_tests/24/stdout01")
		|| system("diff trace/general_tests/24/stderr00 trace/general_tests/24/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
