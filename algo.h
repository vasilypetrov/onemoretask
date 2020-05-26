#include <string>
#include <set>

//
// Method to search transformations from in to out
// Input parameters:
//	in - input string
//	out - output string
//	dict - dictionary
// Return value:
//	true - if success
//	false - if something's failed
bool SearchForPath(const std::string& in, const std::string& out, const std::set<std::string>& dict);
