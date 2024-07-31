#include <Python.h>

#ifndef __has_attribute
#  define __has_attribute(x) 0  // Compatibility with non-clang compilers.
#endif

// Define Py_EXPORTED_SYMBOL to be the appropriate symbol for exporting, it's not set in Python 3.8.
#ifndef Py_EXPORTED_SYMBOL
#  if defined(_WIN32) || defined(__CYGWIN__)
#    define Py_EXPORTED_SYMBOL __declspec(dllexport)
#  elif (defined(__GNUC__) && (__GNUC__ >= 4)) ||\
        (defined(__clang__) && __has_attribute(visibility))
#    define Py_EXPORTED_SYMBOL __attribute__ ((visibility ("default")))
#  else
#    define Py_EXPORTED_SYMBOL
#  endif
#endif
