#ifndef TEMPERATURE_H 
#define TEMPERATURE_H
float *initializeTemperature();
float *updateTemperature(float currentTemperature, int nCities, int nIterations);
int IsDecreasing(float *temperature1 , float *temperature2, int nIterations);
#endif