#include <cstdlib>
#include <ctime>
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

vector<string> loadChords () {
	string chord;
	vector<string> chords;
	ifstream file("chords.txt");
	do {
		if (!chord.empty()) {
			chords.push_back(chord);
		}
	} while (getline(file, chord));

	return chords;
}

int main (int argc, char const *argv[]) {
	// Seed random number generator
	srand(time(NULL));

	// Pick a note
	vector<string> notes = loadNotes();
	int index = rand() % notes.size();
	string note = notes[index];
	cout << note << endl;

	if (argc == 2 && string(argv[1]) == "-c") {
		// Pick a chord
		vector<string> chords = loadChords();
		index = rand() % chords.size();
		string chord = chords[index];
		cout << chord << endl;
	}

	return 0;
}
