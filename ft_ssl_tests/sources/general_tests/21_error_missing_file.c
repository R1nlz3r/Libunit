/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_error_missing_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:27:17 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:31:19 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_error_missing_file(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/general_tests/21");
	system("touch trace/general_tests/21/stdout00 trace/general_tests/21/stdout01 \
trace/general_tests/21/stderr00 trace/general_tests/21/stderr01");

	ret_val = system(FT_SSL_PATH "md5 toto \
1> trace/general_tests/21/stdout00 2> trace/general_tests/21/stderr00");

	ret_val2 = system("md5 toto \
1> trace/general_tests/21/stdout01 2> trace/general_tests/21/stderr01");
	system("sed -i '' '1s/^/ft_ssl: /g' trace/general_tests/21/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH "md5 toto");
	system("mv leak_report trace/general_tests/21/leak_report");

	if (system("diff trace/general_tests/21/stdout00 trace/general_tests/21/stdout01")
		|| system("diff trace/general_tests/21/stderr00 trace/general_tests/21/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
