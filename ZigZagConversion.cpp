#include "ZigZagConversion.h"
using namespace std;

string ZigZagConversion::convert(string s, int numRows) {
	string b = s;
	int bp = 0,counter =0,sp;
	int size = s.size();
	if (size == 1||numRows==1) return b;
	for (int n = 1; n <= numRows; n++) {
		switch (n % numRows) {
		case 1: case 0://first and last row
			counter = 0;
			while (true)
			{
				sp = counter++ * (numRows + numRows - 2) + (n - 1);
				if (sp > size - 1) break;
				b[bp++] = s[sp];
				//if (bp == size) break;
			}
			break;
		default://middle rows
			counter = 0;
			while (true)
			{
				if (counter % 2 == 0) {//verticle rows
					sp = (counter++ / 2) * (numRows + numRows - 2) + (n - 1);
					if (sp > size - 1) break;
				}
				else {//diagnal rows
					sp = (counter++ / 2 + 1) * (numRows + numRows - 2) - (n - 1);
					if (sp > size - 1) break;
				}

				b[bp++] = s[sp];
				//if (bp == size) break;
			}

		}
	}
	return b;
}