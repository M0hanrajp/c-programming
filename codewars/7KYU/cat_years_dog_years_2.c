/* Kata Task
I have a cat and a dog which I got as kitten / puppy.
I forget when that was, but I do know their current ages as catYears and dogYears.
Find how long I have owned each of my pets and return as a list [ownedCat, ownedDog]

NOTES:

Results are truncated whole numbers of "human" years
Cat Years
15 cat years for first year
+9 cat years for second year
+4 cat years for each year after that
Dog Years
15 dog years for first year
+9 dog years for second year
+5 dog years for each year after that */
typedef struct Owned_Cat_Dog_Years {
    unsigned owned_cat;
    unsigned owned_dog;
} owned;

owned owned_cat_and_dog(unsigned cat_years, unsigned dog_years) {
  owned cd;
  if(cat_years < 15) {
    cd.owned_cat = 0; 
  } else {
    cd.owned_cat = 1; 
     cat_years -= 15;
  } 
  if(dog_years < 15) {
    cd.owned_dog = 0; 
  } else {
    cd.owned_dog = 1; 
     dog_years -= 15;
  }
  if(cd.owned_cat == 1 && cat_years > 8) {
    cd.owned_cat += 1; 
       cat_years -= 9;
  }
  if(cd.owned_dog == 1 && dog_years > 8) {
    cd.owned_dog += 1; 
       dog_years -= 9;
  }
  if(cd.owned_cat == 2 && cat_years > 3) {
    cd.owned_cat += (cat_years / 4); 
  }
  if(cd.owned_dog == 2 && dog_years > 4) {
    cd.owned_dog += (dog_years / 5); 
  } 
  return cd;
}
