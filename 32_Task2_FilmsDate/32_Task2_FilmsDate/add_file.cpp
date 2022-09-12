#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann_json/include/nlohmann/json.hpp"
using namespace std;

int main()
{
	ofstream file("../../../films.json");
	nlohmann::json dictFilm[5];
	nlohmann::json dict;

	//The Dark Knight
	dictFilm[0] = {
	{"Country", "USA"},
	{"Data", "14.08.2008"},
	{"Director", "Christopher Nolan"},
	{"Bruce Wayne", "Christian Bale"},
	{"Joker", "Heath Ledger"},
	{"Harvey Dent", "Aaron Eckhart"},
	{"Studio", "DC Comics"},
	{"Screenwriter", "Jonathan Nolan"},
	{"Producer", "Christopher Nolan"}
	};

	//Ford v Ferrari
	dictFilm[1] = {
	{"Country", "USA"},
	{"Data", "30.08.2019"},
	{"Director", "James Mangold"},
	{"Ken Miles", "Christian Bale"},
	{"Carroll Shelby", "Matt Damon"},
	{"Noah Jupe", "Peter Miles"},
	{"Studio", "20th Century Fox Film Corporation"},
	{"Screenwriter", "Jez Butterworth"},
	{"Producer", "John Bernard"}
	};

	//The Imaginarium of Doctor Parnassus
	dictFilm[2] = {
	{"Country", "United Kingdom"},
	{"Data", "22.05.2009"},
	{"Director", "Terry Gilliam"},
	{"Tony", "Heath Ledger"},
	{"Doctor Parnassus", "Christopher Plummer"},
	{"Valentina", "Lily Cole"},
	{"Studio", "Davis-Films"},
	{"Screenwriter", "Terry Gilliam"},
	{"Producer", "Amy Gilliam"}
	};

	//The Prestige
	dictFilm[3] = {
	{"Country", "United Kingdom"},
	{"Data", "17.10.2006"},
	{"Director", "Christopher Nolan"},
	{"Robert Angier", "Hugh Jackman"},
	{"Alfred Borden", "Christian Bale"},
	{"Sarah", "Rebecca Hall"},
	{"Studio", "Newmarket Productions"},
	{"Screenwriter", "Jonathan Nolan"},
	{"Producer", "Christopher Nolan"}
	};

	//The Brothers Grimm
	dictFilm[4] = {
	{"Country", "USA"},
	{"Data", "26.08.2005"},
	{"Director", "Terry Gilliam"},
	{"Wilhelm Grimm", "Matt Damon"},
	{"Jacob Grimm", "Heath Ledger"},
	{"Angelika", "Lena Headey"},
	{"Studio", "Dimension Films"},
	{"Screenwriter", "Ehren Kruger"},
	{"Producer", "Daniel Bobker"}
	};

	dict = {
		{"The Dark Knight", dictFilm[0]},
		{"Ford v Ferrari", dictFilm[1]},
		{"The Imaginarium of Doctor Parnassus", dictFilm[2]},
		{"The Prestige", dictFilm[3]},
		{"The Brothers Grimm", dictFilm[4]}
	};
	file << dict;
	if (file.bad() != true) {
		cout << "File is full\n";
	}
	return 0;
}
