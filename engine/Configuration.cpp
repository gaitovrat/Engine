#include "Configuration.hpp"

float Configuration::playerSpeed = .05f;
float Configuration::sensivity = .1f;
float Configuration::level = 0;

#ifdef NDEBUG
ELogLevel Configuration::logLevel = WARNING;
#else
ELogLevel Configuration::logLevel = DEBUG;
#endif
