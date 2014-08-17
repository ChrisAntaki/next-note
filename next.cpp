#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> loadNotes () {
	string note;
	vector<string> notes;
	ifstream file("notes.txt");
	do {
		if (!note.empty()) {
			notes.push_back(note);
		}
	} while (getline(file, note));

	return notes;
}

int main() {
	vector<string> notes = loadNotes();

	srand(time(NULL));
	int index = rand() % notes.size();

	cout << notes[index] << endl;

	return 0;
}
