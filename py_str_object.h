#ifndef _PY_STR_OBJECT_H_
#define _PY_STR_OBJECT_H_
#include "py_type_object.h"

typedef struct tagPyStrObject
{
    PyObject_HEAD;
    int length;
    long hashValue;
    char value[50];
} PyStringObject;

PyObject* PyStrCreate(const char* value);

extern PyTypeObject PyString_Type;

#endif
