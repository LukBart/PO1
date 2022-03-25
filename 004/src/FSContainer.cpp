#include "FSContainer.h"

FSContainer& FSContainer::operator+= (const FlatShape* shape)
{
    _v.push_back(shape);
    return *this;
}

std::ostream& operator<< (std::ostream& strm, FSContainer obj)
{
    strm << "W kontenerze znajduja sie:\n";
    for (const FlatShape* shape : obj._v){
        strm << *shape;
    }
    return strm;
}