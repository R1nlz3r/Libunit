/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30_multiple_files_mixup_with_errors.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:21:34 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:33:12 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		md5_multiple_files_mixup_with_errors(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/md5/30");
	system("touch trace/md5/30/stdout00 trace/md5/30/stdout01 \
trace/md5/30/stderr00 trace/md5/30/stderr01");

	ret_val = system(FT_SSL_PATH "md5 perm resources/small_file sources \
resources/small_binary_file resources/medium_file toto resources/medium_binary_file \
resources/large_file resources/large_binary_file resources/empty_file \
1> trace/md5/30/stdout00 2> trace/md5/30/stderr00");

	ret_val2 = system("md5 perm resources/small_file sources \
resources/small_binary_file resources/medium_file toto resources/medium_binary_file \
resources/large_file resources/large_binary_file resources/empty_file \
1> trace/md5/30/stdout01 2> trace/md5/30/stderr01");
	system("sed -i '' 's/^/ft_ssl: /g' trace/md5/30/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH "md5 perm resources/small_file \
sources resources/small_binary_file resources/medium_file toto resources/medium_binary_file \
resources/large_file resources/large_binary_file resources/empty_file");
	system("mv leak_report trace/md5/30/leak_report");

	if (system("diff trace/md5/30/stdout00 trace/md5/30/stdout01")
		|| system("diff trace/md5/30/stderr00 trace/md5/30/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
