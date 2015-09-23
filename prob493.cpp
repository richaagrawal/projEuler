#include "probs.h"
#include <iomanip>

void prob493()
{
	// Math here - http://stackoverflow.com/questions/27903590/statistics-optimizing-probability-calculations-within-python
	// And precision here - http://www.cplusplus.com/reference/iomanip/setprecision/
	double d60c20 = factorial(60) / (factorial(40) * factorial(20));
	double d70c20 = factorial(70) / (factorial(50) * factorial(20));

	double wayOfChoosing = 7.0 * (1.0 - d60c20 / d70c20);

	cout << setprecision(10) << "Ways to choose: " << fixed << wayOfChoosing << endl;
}