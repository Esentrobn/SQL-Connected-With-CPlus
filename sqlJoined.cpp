#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <iomanip>

using namespace std;

struct Dogs
{
	int did;
	int age;
};

struct Examine 
{
	int vid;
	int did;
	int fee;
};

struct Join
{
	int vid;
	int did;
	int age;
	int fee;
};

bool Compare_dog_did(const Dogs &a, const Dogs &b) 
{
	return a.did < b.did;
}

bool Compare_examine_did(const Examine &a, const Examine &b)
{
	return a.did < b.did;
}

bool Compare_age_join(const Join &a, const Join &b)
{
	return a.age < b.age;
}


int main()
{
	clock_t tStart = clock();

	ifstream DFile;
	ifstream EFile;
	ifstream read_sorted_DFile;
	ifstream read_sorted_EFile;
	ofstream sorted_DFile;
	ofstream sorted_EFile;
	vector<Examine> examine_list;
	vector<Dogs> dogs_list;
	vector<Join> join_list;


	DFile.open("C:/Users/User/Desktop/SQLCPLUSPROJ/DFile.txt");
	cout << "Opening DFile.txt" << endl;

	while (!DFile.eof()) 
         {
		int did, age;
		DFile >> did >> age;
		Dogs d;

		d.did = did;
		d.age = age;

		dogs_list.push_back(d);
         }

	DFile.close();

	
	sort(dogs_list.begin(), dogs_list.end(), Compare_dog_did);
	cout << "Commence in DFile.txt" << endl;

	cout << "Size or Total Number in Dog file: " << dogs_list.size() << endl;

	cout << endl;

	sorted_DFile.open("sorted_DFile.txt");

	cout << "Data saving in sorted_DFile.txt" << endl;

	for (int i = 0; i < dogs_list.size(); i++) 
        {
		sorted_DFile << dogs_list[i].did << " " << dogs_list[i].age << endl;
	}

	sorted_DFile.close();

	dogs_list.clear();

	EFile.open("C:/Users/User/Desktop/SQLCPLUSPROJ/EFile.txt");
	cout << "Opening EFile.txt" << endl;

	while (!EFile.eof()) 
        {
		int vid, did, fee;
		EFile >> vid >> did >> fee;
		Examine e;

		e.vid = vid;
		e.did = did;
		e.fee = fee;

		examine_list.push_back(e);
	}

	EFile.close();

	
	sort(examine_list.begin(), examine_list.end(), Compare_examine_did);
	cout << "Commence Sorted EFile.txt" << endl;

	cout << "Size or Total Number in Examine file: " << examine_list.size() << endl;

	cout << endl;

	sorted_EFile.open("sorted_EFile.txt");
	cout << "Data saving in sorted_EFile.txt" << endl;

	for (int i = 0; i < examine_list.size(); i++) 
        {
		sorted_EFile << examine_list[i].vid << " " << examine_list[i].did << " " << examine_list[i].fee << endl;
	}

	sorted_EFile.close();

	examine_list.clear();

	read_sorted_DFile.open("sorted_DFile.txt");
	read_sorted_EFile.open("sorted_EFile.txt");

	int examine_vid, examine_did, dogs_did, dogs_age, examine_fee;
	read_sorted_DFile >> dogs_did >> dogs_age;

	read_sorted_EFile >> examine_vid >> examine_did >> examine_fee;

	Dogs d;
	Examine e;

	Join j;

	d.did = dogs_did;
	d.age = dogs_age;

	e.vid = examine_vid;
	e.did = examine_did;
	e.fee = examine_fee;

	cout << "Joining Dogs and Examine" << endl;

	while (!read_sorted_DFile.eof() && !read_sorted_EFile.eof()) 
        {

		if (d.did < e.did) 
                {
			d = Dogs();
			read_sorted_DFile >> dogs_did >> dogs_age;

			d.did = dogs_did;
			d.age = dogs_age;
		}

		else if (d.did > e.did) 
                {
			e = Examine();
			read_sorted_EFile >> examine_vid >> examine_did >> examine_fee;

			e.vid = examine_vid;
			e.did = examine_did;
			e.fee = examine_fee;
		}

		else 
                {
			j.vid = e.vid;
			j.did = d.did;
			j.age = d.age;
			j.fee = e.fee;

			join_list.push_back(j);

			read_sorted_DFile >> dogs_did >> dogs_age;

			d.did = dogs_did;
			d.age = dogs_age;

			read_sorted_EFile >> examine_vid >> examine_did >> examine_fee;

			e.vid = examine_vid;
			e.did = examine_did;
			e.fee = examine_fee;

		}
	}

	cout << "Size of the Joined Dogs and Examine list " << join_list.size() << endl << endl;
	sort(join_list.begin(), join_list.end(), Compare_age_join);

	int cur_age = -1, prev_age = -1, sum = 0, cur_fee = 0;

	for (int i = 0; i < join_list.size(); i++) 
          {

		cur_age = join_list[i].age;
		cur_fee = join_list[i].fee;

		if (prev_age == -1) 
                {
			prev_age = cur_age;
		}

		if (cur_age != prev_age) 
                {
			cout << "Age  " << setw(3) << prev_age << ",  Sum of Fee  " << sum << endl;

			sum = 0;
			prev_age = cur_age; 
			sum += cur_fee;

		}

		else if (cur_age = prev_age) 
                {
			prev_age = cur_age;
			sum += cur_fee;
		}

		if (i == join_list.size() - 1)
                {
			cout << "Age : " << setw(3) << prev_age << ",  Sum of Fee : " << sum << endl;
		}

	}

	printf("\n\nTime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	char c;
	cin >> c;

	return 0;
}

