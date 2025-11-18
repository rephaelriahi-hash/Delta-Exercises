/*------------------------------------------------------
* Filename: calc_price.c
* Description: The program gets the length, width,  weight of a package and prints
* the Package size, weight in kg, and the price
* Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>

#define CONST_DELIVERY_PRICE 5.5
#define MM_IN_CM 10
#define GR_IN_KG 1000

int main() {
    int length_mm = 0, width_mm = 0, weight_gr = 0;
    float package_size = 0.0, weight_kg = 0.0, price =0.0;

    printf("Enter the length, width, weight of the package\n");
    scanf("%d %d %d",&length_mm, &width_mm, &weight_gr);

    package_size = (double)length_mm * width_mm / (MM_IN_CM * MM_IN_CM);
    weight_kg = (double)weight_gr / GR_IN_KG;
    price = CONST_DELIVERY_PRICE + 11 * weight_kg + 0.03 * package_size + 0.01 * package_size / weight_kg;
    
    printf("Package size : %.2f scm\nPackage weight : %.3f kg\nPrice: %.2f Ils",package_size, weight_kg, price);
    return 0;
}
