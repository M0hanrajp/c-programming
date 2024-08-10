/* A c program that describes the use of logical && expresion plus if-else statement
 * March 6, 2024, Mohanraj */
#include <stdio.h>
int main(void)
{
	int locationOfPerson = 0, WeatherCondition = 0;
	printf("Where are you ?\nare you outside ? enter 1\nare you inside ? enter 0\nEnter your choice as 1 or 0 based on above info: ");
	scanf("%d", &locationOfPerson); // this will give me if a person is outside or inside
	printf("Enter the condition of the weather:\nIs it sunny/clear ? enter 0\nIs it overcast/rainy ? enter 1\nEnter your choice as 1 or 0 based on above info: ");
	scanf("%d", &WeatherCondition); // this wil give condition of the weather
	// control statement for carrying umbrella:
	if( locationOfPerson && WeatherCondition ){
		printf("you need to carry an umbrella\n");
	}
	else {
		printf("you don't need an umbrella\n");
	}
	return 0;
}

