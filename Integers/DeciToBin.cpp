// Name: Brandan Tyler Lasley
// Date: 5/12/2014 14:03
// Desc: Does everything in assignment 1 + edianness. 
#include "DeciToBin.h"

void main()
{
	long long decimal = 0;
	while (true) { // Endless loop, except when the right answer is given.
		cout << "Enter a INT64: "; // Print to screen
		if (cin >> decimal) { // Test if cin is valid (and the type)
			if (decimal == 0) {
				break; // Exit the loop once a valid answer was given. 
			}
			else {
				string edianess;
				string bin = ToBinary(decimal);
				cout << "Big Edian?: "; // Print to screen
				if (cin >> edianess) {
					if (edianess == "yes") {
						cout << Edian_Swap(bin, false);
					}
					else {
						cout << "Bin: " << Edian_Swap(bin, true);
						cout << endl;
						cout << "Hex: " << "0x" << std::hex << stoi(Edian_Swap(bin, true));
						cout << endl;
					}
				}
				else {
					cout << "Invalid!" << endl;
					cin.clear(); // Clear Invalid flags
					cin.sync();  // Resyncs buffer 
				}
			}
		}
		else { // Oh noes it wasn't valid :/
			cerr << "Input was not an INT64!" << endl; // Crap something went wrong :(
			cin.clear(); // Clear Invalid flags
			cin.sync();  // Resyncs buffer 
		}
	}
}

string ToBinary(long long decimal = 0) {
	stringstream binary(stringstream::in | stringstream::out);
	bool negitive = false; // Negitive Hoxfix,not how I would have programmed it but I didn't have enough time to impliment them properly. 

	if (decimal < 0) {
		decimal = abs(decimal); // Absolute ftw. 
		negitive = true;
	}

	if (decimal == 0) {
		return 0;
	}
	else if (decimal == 1) {
		if (negitive = '-1') {
			return "-1";
		}
		else {
			return "1";
		}
	}

	while (decimal >= 1) {
		binary << (decimal % 2);
		decimal = (decimal >> 1);
	}

	if (negitive) {
		binary << ("-"); // Another hotfix.
	}
	string output = binary.str(); // output is the answer, but heres a problem, its reversed!
	std::reverse(output.begin(), output.end()); // reverse output, to see the issue that made me use a stringstream
	// instead of a normal long long comment out this line and run it.
	return output.c_str(); // Return the correct output. 
}

bool SystemEdianness() {
	unsigned int i = 1;
	char *c = (char*)&i;
	if (*c){
		return true; // Little Endian
	}
	else {
	  return false; // Big Endian
	}
}

string Edian_Swap(string bin, bool edianness) {
	char const *pchar = bin.c_str(); 
	char *binchar = new char[bin.length()];
	string result; 
	if (SystemEdianness() != edianness) {
		// Swap Bytes
		for (int i = 0; i <= bin.length(); i++) {
			if (pchar[i] != '-') {
				char tmp = pchar[i];
				binchar[i] = pchar[i + 1];
				binchar[i + 1] = tmp;

				if (i == bin.length()) {
					binchar[i] = pchar[i];;
				}
				i++;
			}
		}
		result = (binchar);
	}
	else {
		result = bin;
	}
	return result;
}