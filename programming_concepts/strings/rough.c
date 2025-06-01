#include <ctype.h>
#include <math.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
/* enumber WeatherType {
    CLEAR, SUNNY, CLOUDY, RAINY, OVERCAST, WINDY, THUNDERSTORMS
};

void min_umbrellas (size_t length, const enumber WeatherType forecasts[length]) {
  size_t umbrella_count = 0;
  bool work = false, home = false;
  for(size_t day = 0; day < length; day++) {
    if(day % 2 == 0) {
      if(forecasts[day] == RAINY || forecasts[day] == THUNDERSTORMS) {
        if(home){ work = true; home = false; continue;}else{umbrella_count++; work = true; continue;}}
      if(forecasts[day] != RAINY || forecasts[day] != THUNDERSTORMS) { continue;}
    }
    if(day % 2 != 0) {
      if(forecasts[day] == RAINY || forecasts[day] == THUNDERSTORMS) {
        if(work){ home = true; work = false; continue;}else{umbrella_count++; home = true; continue;}}
      if(forecasts[day] != RAINY || forecasts[day] != THUNDERSTORMS) { continue;}   
    }
  }
  printf("Umbrella :: %zu\n", umbrella_count);
} */

void modify(char a[7]) {
  a[1] = 'a';
}

int main(void) {
/*   char *temp[3];
  for(int i = 0; i < 3; i++) {
    temp[i] = (char *)calloc(10, sizeof(char));
    printf("Enter the name:");
    scanf("%s", temp[i]);
  }
  printf("%s\n", temp[1]); */
  char *p = "string";
  modify(p);
  printf("%s\n", p);
  return 0;
}
