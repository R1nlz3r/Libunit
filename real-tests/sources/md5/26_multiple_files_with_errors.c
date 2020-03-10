/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   26_multiple_files_with_errors.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 06:34:50 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:32:52 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_multiple_files_with_errors(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/md5/26");
	system("touch trace/md5/26/stdout00 trace/md5/26/stdout01 \
trace/md5/26/stderr00 trace/md5/26/stderr01");

	ret_val = system(FT_SSL_PATH "md5 perm resources/small_file \
sources resources/medium_file resources/large_file resources/empty_file toto \
1> trace/md5/26/stdout00 2> trace/md5/26/stderr00");

	ret_val2 = system("md5 perm resources/small_file \
sources resources/medium_file resources/large_file resources/empty_file toto \
1> trace/md5/26/stdout01 2> trace/md5/26/stderr01");
	system("sed -i '' 's/^/ft_ssl: /g' trace/md5/26/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH "md5 perm \
resources/small_file sources resources/medium_file resources/large_file \
resources/empty_file toto");
	system("mv leak_report trace/md5/26/leak_report");

	if (system("diff trace/md5/26/stdout00 trace/md5/26/stdout01")
		|| system("diff trace/md5/26/stderr00 trace/md5/26/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}