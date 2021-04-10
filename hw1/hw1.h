/* calculates how many bags of food needed based on cats, intake, and days */
unsigned int bags_of_cat_food(unsigned int num_cats, 
                              unsigned int grams_per_cat,
                              unsigned int num_days);

/* calculates the fration part of first num divided by the second */
double fractional_part(unsigned int numerator, unsigned int denominator); 

/* determines if the object is bouyant or not based on weight and radius */
int is_buoyant(double weight, double radius);
