#include <iostream>
#include "structures.h"
#include <fstream>
#include <string>

#define FILENAME "list.txt"

/*
 -reads a file and builds a list
 -display list
 -may use any data structure
 -have a key filed and data
 -a linked list implementation
 examples: a list of your favorite CDs or your friend’s telephone numbers. 
*/

class album {
private:
	std::string artist;
	std::string name;
	struct t {
		int min;
		int sec;
	};
	struct song {
		std::string name;
		t time;
	};
	song* songs;
	int songSize;
public:
	//artist name, album name, number of songs
	album(const std::string &a, const std::string &n, const int &size) {
		artist = a;
		name = n;
		songs = new song[size];
		for (int i = 0; i < size; i++) {
			songs[i].name = "";
			songs[i].time.min = NULL;
			songs[i].time.sec = NULL;
		}
		songSize = size;
	}
	//default constructor
	album() {}

	void addSong(const std::string &s, const int &m, const int &se) {
		int i = 0;
		while (songs[i].name != "") {
			i++;
		}
		songs[i].name = s;
		songs[i].time.min = m;
		songs[i].time.sec = se;
	}
	void addSong(const std::string &s) {
		int i = 0;
		while (songs[i].name != "") {
			i++;
		}
		songs[i].name = s;
	}
	std::string getName() {
		return name;
	}
	std::ostream& print(std::ostream& os) const {
		os << "Artist: " << artist << "\n";
		os << "Album Name: " << name << "\n";
		for (int i = 0; i < songSize; i++) {
			if (songs[i].time.min != NULL) {
				os << "[" << songs[i].time.min << ":" << songs[i].time.sec << "]\t" << songs[i].name << "\n";
			}
			else {
				os << "\t" << songs[i].name << "\n";
			}
		}
		return os;
	}

};

std::ostream& operator<<(std::ostream& os, album& obj) {
	return obj.print(os);
}

int main() {
	album a("billy joel", "myalbum", 4);
	a.addSong("mysong", 3, 23);
	a.addSong("mysong1", 4, 0);
	a.addSong("mysong2", 2, 1);
	a.addSong("as");

	album b("billy joel", "myalbum2", 2);
	b.addSong("mysongrem", 1, 12);
	b.addSong("thesong");
	
	linkedMap<std::string, album> m;
	m.pushBack(a.getName(), a);
	m.pushBack(b.getName(), b);
	m.display("print");
	std::cout << m.at(a.getName());
	
	
	//read 
	/*
	std::string s;

	std::ifstream fin(FILENAME);
	for (int i = 0; i < 1056; i++) {
		getline(fin, s);
		std::cout << s << "\n";
	}
	fin.close();
	*/
	


	std::cin.get();
}