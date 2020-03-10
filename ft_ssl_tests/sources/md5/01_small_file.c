/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_small_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:55:38 by mapandel          #+#    #+#             */
/*   Updated: 2020/02/24 23:46:52 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_small_file(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/md5/01");
	system("touch trace/md5/01/stdout00 trace/md5/01/stdout01 \
trace/md5/01/stderr00 trace/md5/01/stderr01");

	ret_val = system(FT_SSL_PATH "md5 resources/small_file \
1> trace/md5/01/stdout00 2> trace/md5/01/stderr00");

	ret_val2 = system("md5 resources/small_file \
1> trace/md5/01/stdout01 2> trace/md5/01/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH "md5 resources/small_file");
	system("mv leak_report trace/md5/01/leak_report");

	if (system("diff trace/md5/01/stdout00 trace/md5/01/stdout01")
		|| system("diff trace/md5/01/stderr00 trace/md5/01/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
