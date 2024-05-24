#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(void)
{
	time_t seconds_from_epoch;

	seconds_from_epoch = time(NULL);
	printf("Seconds from epoch: %ld\n", seconds_from_epoch);
	// struct tm *time_info = localtime(&seconds_from_epoch);
	struct tm *time_info = gmtime(&seconds_from_epoch);

	// gmtime_r is the same as gmtime but it is thread safe
	// struct tm date;
	// if (gmtime_r(&seconds_from_epoch, date) == NULL)
	// {
	// 	printf("gmtime_r failed\n");
	// 	return (1);
	// }

	printf("Current time: %s", asctime(time_info));
	printf("Current date: %d-%d-%d\n", time_info->tm_year + 1900,
		time_info->tm_mon + 1, time_info->tm_mday);
	printf("Current date and time: %d-%02d-%02d %02d:%02d\n", time_info->tm_year
		+ 1900, time_info->tm_mon + 1, time_info->tm_mday, time_info->tm_hour,
		time_info->tm_min);
	printf("time sone is %s (%ld)\n", time_info->tm_zone, time_info->tm_gmtoff);
	return (0);
}