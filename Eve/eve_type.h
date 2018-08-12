#ifndef _EVE_TYPE_
#define _EVE_TYPE_

#include <string>

namespace eve
{

template <class Elem>
using tstring = std::basic_string<Elem, std::char_traits<Elem>,
    std::allocator<Elem>>;

}

#endif // !_EVE_TYPE_