#include <iostream>
using namespace std;
int main() {
double length, width, room_height = 2.5;
double area, paint_needed;
const double coverage_per_liter = 10.0;
cout << "Enter the length of the room in meters: ";
cin >> length;
cout << "Enter the width of the room in meters: ";
cin >> width;
area = 2 * (length + width) * room_height;
paint_needed = area / coverage_per_liter;
cout << "You will need " << paint_needed << " liters of paint." << endl;
return 0;
}
