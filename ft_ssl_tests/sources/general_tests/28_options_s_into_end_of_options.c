/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   28_options_s_into_end_of_options.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:34:28 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:32:00 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_options_s_into_end_of_options(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/general_tests/28");
	system("touch trace/general_tests/28/stdout00 trace/general_tests/28/stdout01 \
trace/general_tests/28/stderr00 trace/general_tests/28/stderr01");

	ret_val = system(FT_SSL_PATH "md5 -s -- \
1> trace/general_tests/28/stdout00 2> trace/general_tests/28/stderr00");

	ret_val2 = system("md5 -s -- \
1> trace/general_tests/28/stdout01 2> trace/general_tests/28/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH "md5 -s --");
	system("mv leak_report trace/general_tests/28/leak_report");

	if (system("diff trace/general_tests/28/stdout00 trace/general_tests/28/stdout01")
		|| system("diff trace/general_tests/28/stderr00 trace/general_tests/28/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
