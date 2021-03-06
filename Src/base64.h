/**********************************************************\ 
Original Author: Dan Weatherford

Imported into FireBreath:    Oct 4, 2010
License:    Dual license model; choose one of two:
			New BSD License
			http://www.opensource.org/licenses/bsd-license.php
			- or -
			GNU Lesser General Public License, version 2.1
			http://www.gnu.org/licenses/lgpl-2.1.html

Copyright 2010 Dan Weatherford and Facebook, Inc
\**********************************************************/

#pragma once
#include <string>

namespace LinphoneWeb {

std::string base64_encode(std::string const &indata);
std::string base64_decode(std::string const &indata);

} // LinphoneWeb
