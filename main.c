#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <tchar.h>
#include <stdlib.h>

void delay(int miliseconds);

int main()
{
	char str[] = "$GPRMC,102333.00,A,4636.75405,N,01604.58355,E,0.253,,180420,,,A*72";
	
#define FIND_AND_NUL(s, p, c) ( \
   (p) = strchr(s, c), \
   *(p) = '\0', \
   ++(p), \
   (p))

	char* message_id = str;

	char* time = FIND_AND_NUL(message_id, time, ',');
	char* data_valid = FIND_AND_NUL(time, data_valid, ',');
	char* raw_latitude = FIND_AND_NUL(data_valid, raw_latitude, ',');
	char* latitude_direction = FIND_AND_NUL(raw_latitude, latitude_direction, ',');
	char* raw_longitude = FIND_AND_NUL(latitude_direction, raw_longitude, ',');
	char* longitude_direction = FIND_AND_NUL(raw_longitude, longitude_direction, ',');
	char* speed_over_ground = FIND_AND_NUL(longitude_direction, speed_over_ground, ',');
	char* course_made_good = FIND_AND_NUL(speed_over_ground, course_made_good, ',');
	char* date = FIND_AND_NUL(course_made_good, date, ',');
	char* magnetic_variation = FIND_AND_NUL(date, magnetic_variation, ',');
	char* magnetic_var_direction = FIND_AND_NUL(magnetic_variation, magnetic_var_direction, ',');
	char* checksum = FIND_AND_NUL(magnetic_var_direction, checksum, ',');

	/*
	char timeHours[] = time[ ];
	char timeMinutes[] = ;
	char timeSeconds[] = ;
	*/


	if (strcmp(data_valid, "A") == 0) {
		printf("InvalidData. %s\n", data_valid);
		delay(5000);
	}
	else {
		printf("The Message ID is : %s\n", message_id);
		printf("The Time is : %s\n", time);
		printf("DataIsValid! : %s\n", data_valid);
		printf("Latitude : %s\n", raw_latitude);
		printf("LatitudeDIrection : %s\n", latitude_direction);
		printf("Longitude : %s\n", raw_longitude);
		printf("LongitudeDirection : %s\n", longitude_direction);
		printf("SpeedOverGround : %s\n", speed_over_ground);
		printf("Course : %s\n", course_made_good);
		printf("Date : %s\n", date);
		printf("Magnetic_Var. : %s\n", magnetic_variation);
		printf("Magnetic_Var_Dir. : %s\n", magnetic_var_direction);
		printf("Checksum : %s\n", checksum);


		delay(30000);
		return 0;
	}
}


void delay(int milliseconds)
{
	long pause;
	clock_t now, then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	now = then = clock();
	while ((now - then) < pause)
		now = clock();
}

