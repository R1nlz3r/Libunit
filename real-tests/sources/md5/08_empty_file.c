/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_empty_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:35:27 by mapandel          #+#    #+#             */
/*   Updated: 2020/02/24 23:48:58 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_empty_file(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/md5/08");
	system("touch trace/md5/08/stdout00 trace/md5/08/stdout01 \
trace/md5/08/stderr00 trace/md5/08/stderr01");

	ret_val = system(FT_SSL_PATH "md5 resources/empty_file \
1> trace/md5/08/stdout00 2> trace/md5/08/stderr00");

	ret_val2 = system("md5 resources/empty_file \
1> trace/md5/08/stdout01 2> trace/md5/08/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH "md5 resources/empty_file");
	system("mv leak_report trace/md5/08/leak_report");

	if (system("diff trace/md5/08/stdout00 trace/md5/08/stdout01")
		|| system("diff trace/md5/08/stderr00 trace/md5/08/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
