#include "Grib.h"
#include <iostream>
#include <fstream>

void GribDecoder::decode(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);
	if (!file.is_open())
	{
		std::cerr << "Nie mozno otworzyc plik" << filename << std::endl;
		return;

	}
	std::vector<char> data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	decode_section1(data);
	decode_section2(data);
	decode_section3(data);
	decode_section4(data);


}


void GribDecoder::display_info() {
	std::cout << "Displaying information..." << std::endl;
}

void GribDecoder::decode_section1(const std::vector<char>& data) 
{
	int offset = 0;

	std::string section1_info = read_section1_info(data, offset);

	std::cout << "======================" << std::endl;
	std::cout << "==  Section 1 Data  ==" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << section1_info << std::endl;
}
std::string GribDecoder::read_section1_info(const std::vector<char>& data, int offset) {
	std::string section1_info(data.begin() + offset, data.begin() + offset + 100);
	return section1_info;
}
void GribDecoder::decode_section2(const std::vector<char>& data) 
{
	int offset = 0;
	int num_grid_points = 0;
	for (int i = 0; i < 4; ++i) 
	{
		num_grid_points <<= 8; 
		num_grid_points |= static_cast<unsigned char>(data[offset + i]);
	}

	double resolution = 0.0;

	std::cout << "======================" << std::endl;
	std::cout << "==  Section 2 Data  ==" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "\nNumber of Grid Points: " << num_grid_points << std::endl;
	std::cout << "Resolution: " << resolution << std::endl;
}

void GribDecoder::decode_section3(const std::vector<char>& data) 
{
	int offset = 0;
	std::vector<double> section3_data = read_section3_data(data, offset);


	std::cout << "======================" << std::endl;
	std::cout << "==  Section 3 Data  ==" << std::endl;
	std::cout << "======================" << std::endl;
	for (int i = 0; i < section3_data.size(); ++i) {
		std::cout << "Data " << i + 1 << ": " << section3_data[i] << std::endl;
	}

}

std::vector<double> GribDecoder::read_section3_data(const std::vector<char>& data, int offset) 
{


	std::vector<double> section3_data;



	return section3_data;
}

void GribDecoder::decode_section4(const std::vector<char>& data) 
{
	int offset = 0;

	
	std::vector<double> section4_data = read_section4_data(data, offset);


	std::cout << "======================" << std::endl;
	std::cout << "==  Section 4 Data  ==" << std::endl;
	std::cout << "======================" << std::endl;
	for (int i = 0; i < section4_data.size(); ++i) {
		std::cout << "Data " << i + 1 << ": " << section4_data[i] << std::endl;
	}
}
std::vector<double> GribDecoder::read_section4_data(const std::vector<char>& data, int offset) {
	std::vector<double> section4_data;


	return section4_data;
}