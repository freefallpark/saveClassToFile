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

template <typename D>
int saveDataTypeToFile(D*data, const std::string& fileName){
    auto file = std::fstream(fileName,std::ios::out | std::ios::binary);
    if(!file.is_open()){
	    std::cout << "Failed to Open File '" + fileName + "'" << std::endl;
	    return 1;
    }
    file.write((char*)data, sizeof(*data));
    file.close();
    return 0;
}

template <typename D>
int readDataFromFile(D*data, const std::string&fileName){
    std::ifstream file(fileName, std::ios::out | std::ios::binary);
    if(!file){
        std::cout <<"Failed to Open File"<< std::endl;
	return 1;
    }
    file.read((char*)data,sizeof(*data));
    file.close();
    if(!file.good()){
        std::cout << "failed to read file" << std::endl;
	return 1;
    }
    return 0;
}
int main(){
	//Create Data To save out
	data d; 
	d.set_iVal(1234);
	d.getData();

	//Save Data out to file
	if(saveDataTypeToFile(&d, "testFile.dat")){
		//HANDLE ERRORS
	}

	//Create Data to Read into
	data readD;
	std::cout << "readD Before Reading: " << std::endl;
	readD.getData();

	//Read Data from filee
	if(readDataFromFile(&readD, "testFile.dat")){
		//HANDLE ERRORS
	}

	//Prove we successfully changed the data
	std::cout << "readD After Reading: " <<std::endl;
	readD.getData();

	return 1;
}

