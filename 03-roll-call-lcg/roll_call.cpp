#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Roll_Call_System {

private:
	vector<string> studentNames{};
	vector<string> pickedStudentNames{};
	int seed;
	int a;
	int c;
	int m;
	int pick_student_num;

public:
	fstream fin;

	void OpenFile() {
		//TODO: open the file
		string filename;
		cout << "Filename: ";
		cin >> filename;
		fin.open(filename,ios::in);
	}

	void AddNames() {
		//TODO : add name to studentName vector
		int time;
		fin >> time;
		for (int i = 0; i < time; i++)
		{
			string input;
			fin >> input;
			studentNames.push_back(input);
		}
	}

	int GenerateRandomNumber() {
		//TODO: implement linear random number generator
		return seed = ((a * seed + c) % m);
	}

	void PickNames() {
		//TODO: randomly pick name form studentName vector
		//		and add them to pickedStudentName vector
		
		fin >> seed >> a >> c >> m >> pick_student_num;
		for (int i = 0; i < pick_student_num; i++) {
			pickedStudentNames.push_back(studentNames[GenerateRandomNumber()]);
		}
	}

	void PrintPickedStudentNames() {
		//TODO: print all picked name form studentName vector
		cout << "Picked Name:" << endl;
		for (int i = 0; i < pick_student_num; i++) 
		{
			cout<<pickedStudentNames[i]<<endl;
		}
	}

	void CaculateAlphabets() {
		//TODO: calculate how many diffetent alphabets are used and print it
		bool flag[26] = { };
		int count=0;
		for (int j = 0; j < pick_student_num; j++) {
			for (int i = 0; i < pickedStudentNames[j].length(); i++) {
				if(isupper(pickedStudentNames[j][i]))
					flag[pickedStudentNames[j][i] - 'A'] = 1;
				else
					flag[pickedStudentNames[j][i] - 'a'] = 1;
				
			}
		}
		for (int k = 0; k < 26; k++) {
			if (flag[k] == 1)
				count++;
		}
		cout <<"Total alphabets: "<<count<< "\n\n";		
		pickedStudentNames.clear();

	}
	
};

int main() {

	Roll_Call_System rcs;
	rcs.OpenFile();
	rcs.AddNames();

	int times;
	rcs.fin >> times;
	while (times--) {
		rcs.PickNames();
		rcs.PrintPickedStudentNames();
		rcs.CaculateAlphabets();
	}

	system("PAUSE");
	return 0;

}