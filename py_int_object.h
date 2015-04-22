
#ifndef _PY_INT_OBJECT_H_
#define _PY_INT_OBJECT_H_
#include "py_type_object.h"

typedef struct tagPyIntObject
{
        PyObject_HEAD;
        int value;
} PyIntObject;

PyObject* PyIntCreate(int value);

extern PyTypeObject PyInt_Type;

#endif
