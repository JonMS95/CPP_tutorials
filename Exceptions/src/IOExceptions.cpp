/********* Include statements *********/

#include "ExceptionTypes.hpp"

/**************************************/

// When it comes to reading files in C++, they can be read/written by using fstream standard library module.
// There are three main methods for such purposes:
//     ·std::ifstream:  read data from a file.
//     ·std::ofstream:  write data to a file. Creates file if missing, overwrites by default.
//     ·std::fstream:   both read and write from/to a file.  Creates file if missing, overwrites by default.
//                      Open modes can be controlled by using std::ios::in/out/app.
//
// Something remarkable (although undesirable) about the methods mentioned above is that they tend to fail
// silently, it's to say, they don't throw expression by themselves. Instead, they set internal error flags
// that can be later checked manually:
// ·eofbit:     end of file reached.
// ·failbit:    logical I/O error (like format mismatch).
// ·badbit:     r/w operation failed (either hardware failure or hardware corruption).
// ·goodbit:    no errors.
// These bits' values can be easily retrieved by using .is_open(), .is_fail(), .bad(), .good() respectively.
//
// Luckily, exceptions can be enabled for file operations per stream object, by using file.exceptions() and
// passing an or-mask of the error bits to be watched (see below):
// file.exceptions(std::ios::failbit | std::ios::badbit)

/********* Define statements *********/



/**************************************/

/***** Private function prototypes ****/



/**************************************/

/******** Function definitions *********/



/**************************************/
