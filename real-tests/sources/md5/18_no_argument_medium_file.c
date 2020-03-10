/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_no_argument_medium_file.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:39:56 by mapandel          #+#    #+#             */
/*   Updated: 2020/02/24 23:49:22 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_no_argument_medium_file(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/md5/18");
	system("touch trace/md5/18/stdout00 trace/md5/18/stdout01 \
trace/md5/18/stderr00 trace/md5/18/stderr01");

	ret_val = system("cat resources/medium_file | "FT_SSL_PATH "md5 \
1> trace/md5/18/stdout00 2> trace/md5/18/stderr00");

	ret_val2 = system("cat resources/medium_file | md5 \
1> trace/md5/18/stdout01 2> trace/md5/18/stderr01");

	leaks_ret_val = system("cat resources/medium_file | \
"FT_SSL_LEAK_REPORT_PATH "md5");
	system("mv leak_report trace/md5/18/leak_report");

	if (system("diff trace/md5/18/stdout00 trace/md5/18/stdout01")
		|| system("diff trace/md5/18/stderr00 trace/md5/18/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
