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
struct t {
	std::string min;
	std::string sec;
};
struct song {
	std::string name;
	t time;
};
class album {
private:
	std::string artist;
	std::string name;
	
	
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
			songs[i].time.min = "";
			songs[i].time.sec = "";
		}
		songSize = size;
	}
	//default constructor
	album() {}

	void addSong(const std::string &s, const std::string &m, const std::string &se) {
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
			if (songs[i].time.min != "") {
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

	linkedMap<std::string, album> m;
	//read 
	
	queue<song> q;
	std::string s;
	std::string ar;
	std::string na;
	std::string min;
	std::string sec;
	std::string st;
	int counter = 0;
	song son;

	std::ifstream fin(FILENAME);
	while(getline(fin, s)) {
		if (s.find("-") != -1) {
			ar = s.substr(0, s.find_first_of("-") - 1);
			na = s.substr(s.find_first_of("-") + 2);
			while (getline(fin, s) && s != "") {
				counter++;
				if (s.find(":") != -1 && s.find("\t") != -1) {
					min = s.substr(s.find_first_of("\t") + 1, (s.find_first_of("\t") + 2 == s.find_first_of(":") ? 1 : 2));
					sec = s.substr(s.find_first_of(":") + 1);
					st = s.substr(0, s.find_first_of(":") - 2);
					son.name = st;
					son.time.min = min;
					son.time.sec = sec;
					q.enqueue(son);
				}
				else {
					son.name = s;
					son.time.min = "";
					son.time.min = "";
					q.enqueue(son);
				}
				
			}
			album al(ar, na, counter);
			for (int i = 0; i < counter; i++) {
				son = q.dequeue();
				if (son.time.min == "") {
					al.addSong(son.name);
				}
				else {
					al.addSong(son.name, son.time.min, son.time.sec);
				}
			}
			counter = 0;
			m.pushBack(al.getName(), al);
		}
		
	}
	fin.close();
	
	m.display("Best Albums of All Time");


	std::cin.get();
}