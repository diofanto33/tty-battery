#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BATTERY_PATH "/sys/class/power_supply/BAT0/capacity"
#define BATTERY_STATUS_PATH "/sys/class/power_supply/BAT0/status"

int 
main()
{  
	FILE *fp;
	int battery;
	while(1)
	{
		fp = fopen(BATTERY_PATH, "r");
		fscanf(fp, "%d", &battery);
		fclose(fp);

		fp = fopen(BATTERY_STATUS_PATH, "r");
		char status[12];
		fscanf(fp, "%s", status);
		fclose(fp);

		printf("%d%% %s\n", battery, status);
		sleep(2);
	}
	return 0;
}
