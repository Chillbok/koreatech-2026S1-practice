#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <fstream>
using std::ifstream; using std::ofstream;
#include <string>
using std::string;

int main() {
	string nameof_infile1 = "Infile1.txt";
	string nameof_infile2 = "Infile2.txt";
	string nameof_outfile = "Outfile.txt";
	ifstream in_file1(nameof_infile1);
	ifstream in_file2(nameof_infile2);
	ofstream out_file(nameof_outfile);

	if (!in_file1) {
		std::cerr << nameof_infile1 << " 파일이 없습니다." << endl;
		return 1;
	}
	else if (!in_file2) {
		std::cerr << nameof_infile2 << " 파일이 없습니다." << endl;
		return 1;
	}

	string first_line, second_line, line_sum;

	while(true) {
		bool file1_line_empty = !getline(in_file1, first_line);
		bool file2_line_empty = !getline(in_file2, second_line);

		if (file1_line_empty && file2_line_empty) break;
		if (file1_line_empty) line_sum = second_line;
		if (file2_line_empty) line_sum = first_line;

		if (!file1_line_empty && !file2_line_empty) line_sum = first_line + " " + second_line;
		out_file << line_sum << endl;
		cout << line_sum << endl;
	}
	in_file1.close(); in_file2.close();
	out_file.close();
	return 0;
}