#ifndef _PY_TYPE_OBJECT_H_
#define _PY_TYPE_OBJECT_H_
#include "py_object.h"

typedef void (*PrintFun) (PyObject* object);
typedef PyObject* (*AddFun)(PyObject* left, PyObject* right);
typedef long (*HashFun)(PyObject* object);

typedef struct tagPyTypeObject
{
    PyObject_HEAD;
    const char* name;
    PrintFun print;
    AddFun add;
    HashFun hash;
} PyTypeObject;

extern PyTypeObject PyType_Type;

#endif
