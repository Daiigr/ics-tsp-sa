/* file:   main.c */
/* authors: 
Daniel Grbac Bravo (d.grbac.bravo@student.rug.n) 
Kealan Barry (k.barry@student.rug.nl)
*/
/* date:   Thu Nov 02 2023 */

#include <stdio.h>
#include <stdlib.h>
#include "IOManager.h"
#include "coordinate.h"
#include "Path.h"
#include "Energy.h"
#include "Temperature.h"

int main(int argc, char *argv[]) {
int nCities = 0;
scanf("%d", &nCities);
coordinate *cityCoordinates = generateRandomCityCoordinates(nCities); // Generate random city coordinates.

printCityCoordinates(cityCoordinates, nCities); // Print city coordinates.  

coordinate *currentPath = generateRandomPath(cityCoordinates, nCities); // Generate random path.

printPath(currentPath, nCities); // Print path.
coordinate *generatedPath = (coordinate *) malloc( nCities * sizeof(coordinate)); // Allocate memory for generated path.
float temperature = initializeTemperature(); 
int currentEpochIteration = 0;
printf("Beginning simulated annealing...\n");
printf("Initial temperature: %f\n", temperature);
//termination condition: temperature is close to zero
while(!shouldTerminate(temperature, currentEpochIteration)){
  // replace current path with new path if new path is better
  generatedPath = generatePathPermuation( temperature, currentPath, nCities);
  // print epoch generation 
  printEpochGeneration(currentEpochIteration, temperature, calculatePathEnergy(currentPath, nCities), nCities);
  if (isEnergyImprovement(currentPath, generatedPath, nCities)){
    printf("Improvment: %f decrease\n", calculatePathEnergy(currentPath, nCities) - calculatePathEnergy(generatedPath, nCities));
    currentPath = generatedPath;
  }
  // apply cooling schedule
  temperature = updateTemperature(temperature);
  currentEpochIteration++;
}

return 0;
}
