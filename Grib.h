#pragma once

#ifndef  GRIB_DECODER_H
#define GRIB_DECODER_H

#include <vector>
#include <string>

class GribDecoder
{
public:
	void decode(const std::string& filename);
	void display_info();

private:
	void decode_section1(const std::vector<char>& data);
	void decode_section2(const std::vector<char>& data);
	void decode_section3(const std::vector<char>& data);
	void decode_section4(const std::vector<char>& data);
	std::string read_section1_info(const std::vector<char>& data, int offset);
	std::vector<double> read_section3_data(const std::vector<char>& data, int offset);
	std::vector<double> read_section4_data(const std::vector<char>& data, int offset);
};



#endif // ! GRIB_DECODER_H
