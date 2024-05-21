#include "Grib.h"

int main() {
    GribDecoder decoder;
    decoder.display_info();
    decoder.decode("example.grib");

    return 0;
}
