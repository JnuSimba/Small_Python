#ifndef _PY_OBJECT_H_
#define _PY_OBJECT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;

using std::cin;
using std::cout;
using std::endl;

#define PyObject_HEAD \
    int refCount; \
    struct tagPyTypeObject* type

#define PyObject_HEAD_INIT(typePtr) \
    0, typePtr

typedef struct tagPyObject
{
    PyObject_HEAD;
} PyObject;


#endif
