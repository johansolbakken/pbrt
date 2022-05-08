//
//  Error.hpp
//  pbrt
//
//  Created by Johan Solbakken on 06/05/2022.
//

#ifndef Error_hpp
#define Error_hpp

#include <iostream>
#include <cassert>

#ifdef NDEBUG
#define Assert(expr) ((void) 0)
#else
#define Assert(expr) if (!(expr)) {std::cerr << "Assertion '" << #expr << "' failed on line " << __LINE__ << " in file " << __FILE__ << std::endl; assert(false);}
//#define Assert(expr) ((expr) ? (void)0 : Severe("Assertion \"%s\" failed in %s, line %d", #expr, __FILE__, __LINE__))
#endif

#endif /* Error_hpp */