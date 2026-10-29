#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct info {
	int height;
	int weight;

	// don't change this
	bool operator<(const info& other) const {
		return height < other.height;
	}
};


typedef pair<string, info> _pair;


//TODO: implement three comparsion function 
//example: 
//bool functionName(const dataType& p1, const dataType& p2) {
//	return p1 > p2;
//}

//1.implement compare by height here
bool compare_H(const _pair & p1, const _pair & p2) {
	return p1.second.height < p2.second.height;
}

//2.implement compare by weight here
bool compare_W(const _pair& p1, const _pair& p2) {
	return p1.second.weight < p2.second.weight;
}
//3.implement compare by height and weight here
bool compare_HW(const _pair& p1, const _pair& p2) {
	if (p1.second.height == p2.second.height)
		return p1.second.weight < p2.second.weight;
	else return p1.second.height < p2.second.height;
}

class Map
{
public:
	Map()
	{
		people.clear();
	}

	void readFile() {
		fstream file;
		file.open("demo.txt", ios::in);
		int cmdNum;
		file >> cmdNum;

		while (cmdNum--) {
			char cmd;
			file >> cmd;
			switch (cmd) {
				case 'a':
				{
					string name;
					file >> name;
					info ii;
					file >> ii.height >> ii.weight;
					add(name, ii);
					break;
				}
				case 'f':
				{
					string name;
					file >> name;
					find(name);
					break;
				}
				case 'e':
				{
					string name;
					file >> name;
					erase(name);
					break;
				}
			}
		}

		file.close();
	}



	void add(string name, info& _info) {
		//TODO: implement add function add new data into the map(vector<pair<...>>)
		//If the name is already in the map, override his/her data
		_pair input(name, _info);
		vector <_pair> ::iterator i;
		for (i = people.begin(); i != people.end(); i++) {
			if (input.first == i->first) {
				cout << name << "'s h:" << i->second.height << " and w:" << i->second.weight << " is changed to h:";
				i->second = input.second;
				cout << i->second.height << " and w:" << i->second.weight << endl;
				break;
			}
		}
		if (i == people.end()) people.push_back(input);
	}

	void find(string name) {
		//TODO: implement find function to get the information of the given name if the name exist
		//otherwise, print "name is not found"
		//you must use iterator to implement
		vector <_pair> ::iterator i;
		for (i = people.begin(); i != people.end(); i++) {
			if (name == i->first) {
				cout << name << " is found h:";
				cout << i->second.height << " w:" << i->second.weight << endl;
				break;
			}
		}
		if (i == people.end()) 
			cout<<name<<" is not found!"<<endl;
	}

	void erase(string name) {
		//TODO: implement erase function to delete the element of the given name if the name exist
		//otherwise, print "name is not found"
		//you must use iterator to implement
		vector <_pair> ::iterator i;
		bool flg=false;
		for (i = people.begin(); i != people.end(); i++) {
			if (name == i->first){
				cout << name << " is erased!\n";
				people.erase(i);
				flg = true;
				break;
			}
		}
		if (flg != true) { cout << name << " is not found!" << endl; }
	}

	void sortByName() {
		//TODO: call sort() function (default one)
		sort(people.begin(), people.end());
	}

	void sortByInfo(const char* type) {

		if (type == "H") {
			//TODO: call sort() function and compare by height
			sort(people.begin(), people.end(), compare_H);
		}
		else if (type == "W") {
			//TODO: call sort() function and compare by weight
			sort(people.begin(), people.end(), compare_W);
		}
		else if (type == "HW") {
			//TODO: call sort() function and compare by height and weight
			sort(people.begin(), people.end(), compare_HW);
		}
	}

	void write(fstream& file) {
		//TODO: Write all elements in the map to the file
		//you must use iterator to implement
		vector <_pair> ::iterator i;
		for (i = people.begin(); i != people.end(); i++) {
			file << i->first << " " << i->second.height << " " << i->second.weight << endl;
		}
		file << endl;
	}

	void writeFile() {
		fstream file;
		file.open("sorted_people.txt", ios::out);

		file << "Sort By Name\n";
		sortByName();
		write(file);
		file << "Sort By Height\n";
		sortByInfo("H");
		write(file);
		file << "Sort By Weight\n";
		sortByInfo("W");
		write(file);
		file << "Sort By Height&Weight\n";
		sortByInfo("HW");
		write(file);

		cout << "File sorted_people.txt saved!\n";
		file.close();
	}

private:
	vector<pair<string, info>> people;
};

int main() {
	Map myMap;

	myMap.readFile();
	myMap.writeFile();

	system("pause");
	return 0;
}