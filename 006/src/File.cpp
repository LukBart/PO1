#include "File.h"

void File::StreamOfElements (std::ostream& strm, int counter) const
{
	while (counter-- > 0){
		strm << "  ";
	}
	strm << _name << " (FILE)" << std::endl;
}
