/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_s_option_no_argument.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 05:37:35 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:38:04 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_s_option_no_argument(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/general_tests/20");
	system("touch trace/general_tests/20/stdout00 trace/general_tests/20/stdout01 \
trace/general_tests/20/stderr00 trace/general_tests/20/stderr01");

	ret_val = system(FT_SSL_PATH "md5 -s \
1> trace/general_tests/20/stdout00 2> trace/general_tests/20/stderr00");

	ret_val2 = system("md5 -s 1> trace/general_tests/20/stdout01 2> trace/general_tests/20/stderr01");
	system("sed -i '' '1s/^/ft_ssl: /g' trace/general_tests/20/stderr01; \
sed -i '' '2s/md5/ft_ssl command/g' trace/general_tests/20/stderr01; \
sed -i '' 's/-pqrtx/-pqr/g' trace/general_tests/20/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH "md5 -s");
	system("mv leak_report trace/general_tests/20/leak_report");

	if (system("diff trace/general_tests/20/stdout00 trace/general_tests/20/stdout01")
		|| system("diff trace/general_tests/20/stderr00 trace/general_tests/20/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
