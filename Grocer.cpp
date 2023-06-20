/* Corner Grocer Application
Corey Sampson
June 16th, 2023
Professor Marcello
CS210 */

#include "Grocer.h"	// Including Grocer class
#include <iostream>
using namespace std;

int main() {

	// Creates object of Grocer as "g"
	Grocer g;
	g.openFile();
	g.grocerMenu();

	return 0;
}
