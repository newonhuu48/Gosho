#include "menus.h"

using namespace std;

int main() {
	unsigned short command;
	double x, y, z;
	double scalar;
	bool yn = 1;

	menu();


	//Input choice
	std::cin >> command;

	while (command < 1 || command > 2 || std::cin.fail()) {
		cin.clear();
		cin.ignore();

		std::cout << "Please enter a valid option:\n\n";
		std::cin >> command;
	}
	
	switch (command) {
	case 1:
		//===============
		//===============
		//  File stream
		//===============
		//===============
		system("cls");
		fileMenu();
		break;
	case 2:
	{
		//===============
		//===============
		// Console stream
		//===============
		//===============
		system("cls");
		consoleMenu();

		//===============
		//===============
		//Geometric object
		//===============
		//===============
		std::cin >> command;

		switch (command) {
		//===============
		//===============
		//     Point
		//===============
		//===============
		case 1:
		{
			Point p1, p2;


			std::cout << "Enter x value\n";
			std::cin >> x;
			p1.setX(x);

			std::cout << "Enter y value\n";
			std::cin >> y;
			p1.setY(y);

			std::cout << "Enter z value\n";
			std::cin >> z;
			p1.setZ(z);

			

			while (yn) {
				system("cls");
				pointMenu();

				std::cin >> command;

				switch (command) {
				case 1:
					std::cout << "Enter x value\n";
					std::cin >> x;
					p2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p2.setZ(z);


					if (p1 == p2) {
						std::cout << "\nPoints are equal.\n\n";
					}
					else {
						std::cout << "\nPoints are not equal.\n\n";
					}

					std::cout << "Do you want to continue operations with this object? 0/1 \n\n";
					std::cin >> yn;
				}
			}

			break;
		}
		case 2:
			//==================
			//==================
			//      Vector
			//==================
			//==================
		{
			system("cls");
			vectorInit();

			Point p1, p2;
			Vector v1, v2, v3;

			std::cin >> command;

			//Vector initialization
			switch (command) {
			case 1:
			{
				//==================
				//==================
				// Three values init
				//==================
				//==================
				std::cout << "Enter x value\n";
				std::cin >> x;
				v1.setX(x);

				std::cout << "Enter y value\n";
				std::cin >> y;
				v1.setY(y);

				std::cout << "Enter z value\n";
				std::cin >> z;
				v1.setZ(z);

				break;
			}
			case 2:
			{
				//==================
				//==================
				// Two points init
				//==================
				//==================
				std::cout << "Enter x value\n";
				std::cin >> x;
				p1.setX(x);

				std::cout << "Enter y value\n";
				std::cin >> y;
				p1.setY(y);

				std::cout << "Enter z value\n";
				std::cin >> z;
				p1.setZ(z);


				std::cout << "\n\n";


				std::cout << "Enter x value\n";
				std::cin >> x;
				p2.setX(x);

				std::cout << "Enter y value\n";
				std::cin >> y;
				p2.setY(y);

				std::cout << "Enter z value\n";
				std::cin >> z;
				p2.setX(z);


				v1.setX(p2.getX() - p1.getX());
				v1.setY(p2.getY() - p1.getY());
				v1.setZ(p2.getZ() - p1.getZ());

				break;
			}
			}

			while (yn) {
				system("cls");
				vectorMenu();
				std::cin >> command;

				//Vector operations
				switch (command) {
				case 1:
					std::cout << "Vector length is " << (v1.length()) << "\n\n";

					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 2:
					std::cout << "Directional vector is " << v1.getDirection() << "\n\n";

					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 3:
					if (v1.isNull()) {
						std::cout << "Vector is null\n\n";
					}
					else {
						std::cout << "Vector is not null\n\n";
					}

					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 4:
					//==================
					//==================
					// Paralellism check
					//==================
					//==================
					std::cout << "Enter x value\n";
					std::cin >> x;
					v2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					v2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					v2.setZ(z);


					if (v1.paralellismCheck(v2)) {
						std::cout << "Vectors are parallel\n\n";
					}
					else {
						std::cout << "Vectors are not parallel\n\n";
					}


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 5:
					//==================
					//==================
					//Ortogonality check
					//==================
					//==================

					std::cout << "Enter x value\n";
					std::cin >> x;
					v2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					v2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					v2.setZ(z);


					if (v1.ortogonalityCheck(v2)) {
						std::cout << "Vectors are ortogonal\n\n";
					}
					else {
						std::cout << "Vectors are not ortogonal\n\n";
					}


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 6:
					//==================
					//==================
					// Vector addition
					//==================
					//==================
					std::cout << "Enter x value\n";
					std::cin >> x;
					v2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					v2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					v2.setZ(z);

					std::cout << "Result is " << v1 + v2 << "\n\n";


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 7:
					//==================
					//==================
					//Vector substraction
					//==================
					//==================
					std::cout << "Enter x value\n";
					std::cin >> x;
					v2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					v2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					v2.setZ(z);


					std::cout << "Result is " << v1 - v2 << "\n\n";


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 8:
					//==================
					//==================
					//Vector-by-scalar mult.
					//==================
					//==================

					std::cout << "Enter scalar \n";
					std::cin >> scalar;


					std::cout << "Result is " << v1 * scalar << "\n\n";


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 9:
					//==================
					//==================
					//   Dot product
					//==================
					//==================
					std::cin >> x;
					v2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					v2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					v2.setZ(z);


					std::cout << "Dot product is " << v1 * v2 << "\n\n";


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 10:
					//==================
					//==================
					//   Cross product
					//==================
					//==================
					std::cin >> x;
					v2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					v2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					v2.setZ(z);


					std::cout << "Cross product result is " << (v1 ^ v2) << "\n\n";


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 11:
					//==================
					//==================
					//  Mixed product
					//==================
					//==================
					std::cout << "Enter x value\n";
					std::cin >> x;
					v2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					v2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					v2.setZ(z);


					std::cout << "\n\n";


					std::cin >> x;
					v3.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					v3.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					v3.setZ(z);


					std::cout << "Cross product is " << v1(v2, v3);

					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				}
			}
			break;
		}
		case 3:
		{
			//==================
			//==================
			//       Line
			//==================
			//==================

			system("cls");
			lineInit();

			Line l1, l2;
			Point p1, p2;
			Vector v1;

			std::cin >> command;

			//Line initializatopn
			switch (command) {
			case 1:
				//==================
				//==================
				//    Two points
				//==================
				//==================
				std::cout << "Enter x value\n";
				std::cin >> x;
				p1.setX(x);

				std::cout << "Enter y value\n";
				std::cin >> y;
				p1.setY(y);

				std::cout << "Enter z value\n";
				std::cin >> z;
				p1.setZ(z);


				std::cout << "\n\n";


				std::cout << "Enter x value\n";
				std::cin >> x;
				p2.setX(x);

				std::cout << "Enter y value\n";
				std::cin >> y;
				p2.setY(y);

				std::cout << "Enter z value\n";
				std::cin >> z;
				p2.setZ(z);


				v1.setX(p2.getX() - p1.getX());
				v1.setY(p2.getY() - p1.getY());
				v1.setZ(p2.getZ() - p1.getZ());


				l1.setP1(p1);
				l1.setP2(p2);

				l1.setV1(v1);
				break;
			case 2:
				//==================
				//==================
				// Point and vector
				//==================
				//==================
				std::cout << "Enter x value\n";
				std::cin >> x;
				p1.setX(x);

				std::cout << "Enter y value\n";
				std::cin >> y;
				p1.setY(y);

				std::cout << "Enter z value\n";
				std::cin >> z;
				p1.setZ(z);


				std::cout << "\n\n";


				std::cout << "Enter x value\n";
				std::cin >> x;
				v1.setX(x);

				std::cout << "Enter y value\n";
				std::cin >> y;
				v1.setY(y);

				std::cout << "Enter z value\n";
				std::cin >> z;
				v1.setZ(z);

				p2.setX(p1.getX() + v1.getX());
				p2.setY(p1.getY() + v1.getY());
				p2.setZ(p1.getZ() + v1.getZ());

				l1.setP1(p1);
				l1.setP2(p2);
				l1.setV1(v1);

				break;
			}

			while (yn) {
				system("cls");
				lineMenu();

				std::cin >> command;

				switch (command) {
				case 1:
					//==================
					//==================
					//Directional vector
					//==================
					//==================

					std::cout << "Directional vector is " << l1.getV1().getDirection() << "\n\n";

					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 2:
					//==================
					//==================
					//   Normal vector
					//==================
					//==================


					std::cout << "Normal vector is " << l1.normalVector() << "\n\n";


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 3:
					//==================
					//==================
					//    Lines angle
					//==================
					//==================
					std::cout << "Enter x value\n";
					std::cin >> x;
					p1.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p1.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p1.setZ(z);


					std::cout << "\n\n";


					std::cout << "Enter x value\n";
					std::cin >> x;
					p2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p2.setZ(z);

					v1.setX(p2.getX() - p1.getX());
					v1.setY(p2.getY() - p1.getY());
					v1.setZ(p2.getZ() - p1.getZ());

					l2.setV1(v1);


					std::cout << "Angle is " << l1.angle(l2) << "\n\n";


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 4:
					//==================
					//==================
					// Line cross point
					//==================
					//==================
					std::cout << "Enter x value\n";
					std::cin >> x;
					p1.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p1.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p1.setZ(z);


					if (l1 + p1) {
						std::cout << "The line and the point intersect\n\n";
					}
					else {
						std::cout << "The line and the point don't intersect\n\n";
					}


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 5:
					//==================
					//==================
					//  Lines parallel
					//==================
					//==================

					std::cout << "Enter x value\n";
					std::cin >> x;
					p1.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p1.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p1.setZ(z);


					std::cout << "\n\n";


					std::cout << "Enter x value\n";
					std::cin >> x;
					p2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p2.setZ(z);


					l1.setP1(p1);
					l1.setP2(p2);

					if (l1 || l2) {
						std::cout << "The two lines are parallel \n\n";
					}
					else {
						std::cout << "The two lines are not parallel \n\n";
					}


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 6:
					//==================
					//==================
					//  Lines coincide
					//==================
					//==================

					std::cout << "Enter x value\n";
					std::cin >> x;
					p1.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p1.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p1.setZ(z);


					std::cout << "\n\n";


					std::cout << "Enter x value\n";
					std::cin >> x;
					p2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p2.setZ(z);


					l1.setP1(p1);
					l1.setP2(p2);

					if (l1 == l2) {
						std::cout << "The lines coincide\n\n";
					}
					else {
						std::cout << "The lines don't coincide\n\n";
					}


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 7:
					//==================
					//==================
					//   Lines cross
					//==================
					//==================

					std::cout << "Enter x value\n";
					std::cin >> x;
					p1.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p1.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p1.setZ(z);


					std::cout << "\n\n";


					std::cout << "Enter x value\n";
					std::cin >> x;
					p2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p2.setZ(z);


					l1.setP1(p1);
					l1.setP2(p2);
					

					if (l1 && l2) {
						std::cout << "The lines cross\n\n";
					}
					else {
						std::cout << "The lines don't cross\n\n";
					}


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 8:
					//==================
					//==================
					//   Lines skew
					//==================
					//==================

					std::cout << "Enter x value\n";
					std::cin >> x;
					p1.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p1.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p1.setZ(z);


					std::cout << "\n\n";


					std::cout << "Enter x value\n";
					std::cin >> x;
					p2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p2.setZ(z);


					l1.setP1(p1);
					l1.setP2(p2);

					if (l1 != l2) {
						std::cout << "The lines are skew \n\n";
					}
					else {
						std::cout << "The lines are not skew\n\n";
					}


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				case 9:
					//==================
					//==================
					// Lines ortogonal
					//==================
					//==================

					std::cout << "Enter x value\n";
					std::cin >> x;
					p1.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p1.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p1.setZ(z);


					std::cout << "\n\n";


					std::cout << "Enter x value\n";
					std::cin >> x;
					p2.setX(x);

					std::cout << "Enter y value\n";
					std::cin >> y;
					p2.setY(y);

					std::cout << "Enter z value\n";
					std::cin >> z;
					p2.setZ(z);


					l1.setP1(p1);
					l1.setP2(p2);


					if (l1 | l2) {
						std::cout << "The lines are ortogonal\n\n";
					}
					else {
						std::cout << "The lines are not ortogonal\n\n";
					}


					std::cout << "Do you want to continue operations with this object? 0/1 \n";
					std::cin >> yn;
					break;
				}
			}
			break;
		}
		case 4:
		{
			Vector v1;
			Segment s1;
			Point p1, p2;
			double t1, t2;


			std::cout << "Enter p1.x value\n";
			std::cin >> x;
			p1.setX(x);

			std::cout << "Enter p1.y value\n";
			std::cin >> y;
			p1.setY(y);

			std::cout << "Enter p1.z value\n";
			std::cin >> z;
			p1.setZ(z);


			std::cout << "\n\n";


			std::cout << "Enter p2.x value\n";
			std::cin >> x;
			p2.setX(x);

			std::cout << "Enter p2.y value\n";
			std::cin >> y;
			p2.setY(y);

			std::cout << "Enter p2.z value\n";
			std::cin >> z;
			p2.setZ(z);


			std::cout << "\n\n";

			
			std::cout << "Enter t1 value\n";
			std::cin >> t1;

			std::cout << "Enter t2 value\n";
			std::cin >> t2;


			v1.setX(p2.getX() - p1.getX());
			v1.setY(p2.getY() - p1.getY());
			v1.setZ(p2.getZ() - p1.getZ());


			segmentMenu();
			break;
		}
		case 5:
		{
			system("cls");
			triangleMenu();
			break;
		}
		}
		break;
	}
	}


	
}