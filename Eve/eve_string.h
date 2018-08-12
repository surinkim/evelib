#ifndef _EVE_STRING_
#define _EVE_STRING_

#include <string>

#include "eve_type.h"

namespace eve
{

template <typename Elem>
tstring<Elem>& LTrim(tstring<Elem>& str, const Elem ch)
{
    str.erase(0, str.find_first_not_of(ch));
    return str;
}

template <typename Elem>
tstring<Elem>& RTrim(tstring<Elem>& str, const Elem ch)
{
    str.erase(str.find_last_not_of(ch) + 1);
    return str;
}

template <typename Elem>
tstring<Elem>& Trim(tstring<Elem>& str, const Elem ch)
{
    return LTrim(RTrim(str, ch), ch);
}

}

#endif // !_EVE_STRING_