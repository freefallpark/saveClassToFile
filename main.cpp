#include <iostream>
#include <fstream>

class data{
	private:
		int i = 69;
		bool b = true;
		float f = 420.69;
		double d = 666.666;
	public:
		data() = default;
		~data()= default;
		void set_iVal(int num){
			i = num;
		}
		void getData(){
			std::cout << "i: " << i << " b: " << b << " f: " << f << " d: " << d << std::endl;
		}
};

int main(){
	data d; 
	d.set_iVal(33);
	d.getData();
	std::cout << "size: " << sizeof(d) << std::endl;
	auto myFile = std::fstream("file.binary",std::ios::out | std::ios::binary);
	myFile.write((char*)&d, sizeof(d));
	myFile.close();

	data readD;
	readD.getData();
	std::ifstream rf("file.binary", std::ios::out | std::ios::binary);
	if(!rf){
		std::cout << "Failed to open file" << std::endl;
	}
	rf.read((char*)&readD, sizeof(readD));
	rf.close();
	if(!rf.good()){
		std::cout << "failed to read file" << std::endl;
	}
	readD.getData();



	return 1;
}

