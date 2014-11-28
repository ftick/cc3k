#include <iostream>

#ifdef DEBUG
# undef DEBUG
# define DEBUG_PREFIX "[DEBUG|" << __FILE__ << ":" << __LINE__ << "] "
# define DEBUG(str) std::cerr << DEBUG_PREFIX << str << std::endl
#else
# undef DEBUG
# define DEBUG(str)
#endif
