#include "segment.h"
#include "triangle.h"

void trademark() {
	std::cout << "/--------------------------\\ \n"; Sleep(50);
	std::cout << "| New Bulgarian University | \n"; Sleep(50);
	std::cout << "|                          | \n"; Sleep(50);
	std::cout << "|      Vectors Project     | \n"; Sleep(50);
	std::cout << "|                          | \n"; Sleep(50);
	std::cout << "|        Zlatnite momcheta | \n"; Sleep(50);
	std::cout << "\\-------------------------/ \n"; Sleep(50);
	std::cout << "\n\n";

	Sleep(500);
}

void menu() {
	trademark();

	std::cout << "Choose input type \n\n"; Sleep(50);
	std::cout << "1. File input \n"; Sleep(50);
	std::cout << "2. Console input \n"; Sleep(50);
}


void fileMenu() {

}


void consoleMenu() {
	trademark();

	std::cout << "Please select a geometric object:\n"; Sleep(50);
	std::cout << "1. Point \n"; Sleep(50);
	std::cout << "2. Vector \n"; Sleep(50);
	std::cout << "3. Line \n"; Sleep(50);
	std::cout << "4. Segment \n"; Sleep(50);
	std::cout << "5. Triangle \n"; Sleep(50);
	std::cout << "6. Tethraedron \n"; Sleep(50);
}

void pointMenu() {
	trademark();

	std::cout << "Choose an operation: \n"; Sleep(50);
	std::cout << "1. Point comparsion \n"; Sleep(50);
}



void vectorMenu() {
	trademark();

	std::cout << "Please choose an operation: \n"; Sleep(50);
	std::cout << "1. Vector length \n"; Sleep(50);
	std::cout << "2. Vector direction \n"; Sleep(50);
	std::cout << "3. Null check \n"; Sleep(50);
	std::cout << "4. Paralellism check \n"; Sleep(50);
	std::cout << "5. Ortogonality check \n\n"; Sleep(50);

	std::cout << "6. Vector addition \n"; Sleep(50);
	std::cout << "7. Vector substraction \n"; Sleep(50);
	std::cout << "8. Vector-by-scalar multiplication \n"; Sleep(50);
	std::cout << "9. Dot product \n"; Sleep(50);
	std::cout << "10. Cross product \n"; Sleep(50);
	std::cout << "11. Mixed product \n"; Sleep(50);
}


void vectorInit() {
	trademark();

	std::cout << "Select initialization option\n"; Sleep(50);
	std::cout << "1. Three values \n"; Sleep(50);
	std::cout << "2. Two points \n"; Sleep(50);
}




void lineMenu() {
	trademark();

	std::cout << "Please choose an operation: \n"; Sleep(50);
	std::cout << "1. Find directional vector\n"; Sleep(50);
	std::cout << "2. Find normal vector \n"; Sleep(50);
	std::cout << "3. Find angle between two lines \n"; Sleep(50);

	std::cout << "4. Check if a line crosses a point (+)\n"; Sleep(50);
	std::cout << "5. Line paralellism check (||)\n"; Sleep(50);
	std::cout << "6. Lines coincide check (==)\n"; Sleep(50);
	std::cout << "7. Lines cross check (&&)\n"; Sleep(50);
	std::cout << "8. Skew lines check (!=)\n"; Sleep(50);
	std::cout << "9. Lines ortogonality check (|)\n"; Sleep(50);
}


void lineInit() {
	trademark();

	std::cout << "Select initalization option\n"; Sleep(50);
	std::cout << "1. Two points \n"; Sleep(50);
	std::cout << "2. Point and vector \n"; Sleep(50);
}




void segmentMenu() {
	trademark();

	std::cout << "1. Segment length\n"; Sleep(50);
	std::cout << "2. Segment middle\n"; Sleep(50);
	std::cout << "3. Check if a segment crosses a point\n"; Sleep(50);
}

void segmentInit() {
	trademark();
}



void triangleMenu() {
	trademark();
}

void triangleInit() {
	trademark();
}



void tethraedronMenu() {
	trademark();
}

void tethraedronInit() {
	trademark();
}