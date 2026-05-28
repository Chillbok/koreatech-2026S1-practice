#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <fstream>
#include <string>
using std::string;

int main() {
	std::ifstream in_file("Infile.dat");
	std::ofstream out_file("Outfile.dat");
	
	if (!in_file) {
		std::cerr << "입력 파일을 열 수 없습니다." << endl;
		return 1;
	}
	
	string line;
	int line_num = 1;

	while (getline(in_file, line)) {
		cout << line_num << ": " << line << endl;
		out_file << line_num << ": " << line << endl;
		line_num++;
	}
	
	in_file.close();
	out_file.close();
	
	cout << "행 번호가 추가된 파일을 Outfile.dat에 저장했습니다." << endl;

	return 0;
}