//Bisignano Michele
#include <iostream>

using namespace std;

void immagineimp(int errori) {
	char bs = 92; //contiene il carattere backslash
	switch (errori) {
	case 1:
		cout << "   ----------" << endl;
		break;
	case 2:
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "   ----------" << endl;
		break;
	case 3:
		cout << "   ----------" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "   ----------" << endl;
		break;
	case 4:
		cout << "   ----------" << endl;
		cout << "   |        |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "   ----------" << endl;
		break;
	case 5:
		cout << "   ----------" << endl;
		cout << "   |        |" << endl;
		cout << "   O        |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "   ----------" << endl;
		break;
	case 6:
		cout << "   ----------" << endl;
		cout << "   |        |" << endl;
		cout << "   O        |" << endl;
		cout << "   |        |" << endl;
		cout << "            |" << endl;
		cout << "            |" << endl;
		cout << "   ----------" << endl;
		break;
	case 7:
		cout << "    ----------" << endl;
		cout << "    |        |" << endl;
		cout << "    O        |" << endl;
		cout << "   /|        |" << endl;
		cout << "             |" << endl;
		cout << "             |" << endl;
		cout << "    ----------" << endl;
		break;
	case 8:
		cout << "    ----------" << endl;
		cout << "    |        |" << endl;
		cout << "    O        |" << endl;
		cout << "   /|" << bs<<"       | " << endl;
		cout << "             |" << endl;
		cout << "             |" << endl;
		cout << "    ----------" << endl;
		break;
	case 9:
		cout << "    ----------" << endl;
		cout << "    |        |" << endl;
		cout << "    O        |" << endl;
		cout << "   /|" << bs << "       | " << endl;
		cout << "   /         |" << endl;
		cout << "             |" << endl;
		cout << "    ----------" << endl;
		break;
	case 10:
		cout << "    ----------" << endl;
		cout << "    |        |" << endl;
		cout << "    O        |" << endl;
		cout << "   /|" << bs << "       | " << endl;
		cout << "   / " << bs << "       | " << endl;
		cout << "             |" << endl;
		cout << "    ----------" << endl;
		break;
	default:
		break;
	}
}