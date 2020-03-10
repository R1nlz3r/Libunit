/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   29_options_mixup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:35:45 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:32:03 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_options_mixup(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/general_tests/29");
	system("touch trace/general_tests/29/stdout00 trace/general_tests/29/stdout01 \
trace/general_tests/29/stderr00 trace/general_tests/29/stderr01");

	ret_val = system("cat resources/small_file | "FT_SSL_PATH "md5 -pscoucou \
-r -s coucou -qp -rrsqp -qprrs coucou \
1> trace/general_tests/29/stdout00 2> trace/general_tests/29/stderr00");

	ret_val2 = system("cat resources/small_file | md5 -pscoucou -r -s coucou \
-qp -rrsqp -qprrs coucou \
1> trace/general_tests/29/stdout01 2> trace/general_tests/29/stderr01");

	leaks_ret_val = system("cat resources/small_file | \
"FT_SSL_LEAK_REPORT_PATH "md5 -pscoucou -r -s coucou -qp -rrsqp -qprrs coucou");
	system("mv leak_report trace/general_tests/29/leak_report");

	if (system("diff trace/general_tests/29/stdout00 trace/general_tests/29/stdout01")
		|| system("diff trace/general_tests/29/stderr00 trace/general_tests/29/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
