/* Kata Task
I have a cat and a dog.

I got them at the same time as kitten/puppy. That was humanYears years ago.

Return their respective ages now as [humanYears,catYears,dogYears]

NOTES:

humanYears >= 1
humanYears are whole numbers only
Cat Years
15 cat years for first year
+9 cat years for second year
+4 cat years for each year after that
Dog Years
15 dog years for first year
+9 dog years for second year
+5 dog years for each year after that */
typedef struct Human_Cat_Dog_Years {
    unsigned human_years, cat_years, dog_years;
} years;

years human_years_cat_years_dog_years(unsigned human) {
  years c;c.human_years = human;
  c.cat_years = 15; 
  c.dog_years = 15; 
  human -= 1;
  if(human > 0){
    c.cat_years += 9; 
    c.dog_years += 9;
    human -= 1;
  }
  if(human > 0){
    c.cat_years += (4 * human); 
    c.dog_years += (5 * human);
  }
  return c;
}
