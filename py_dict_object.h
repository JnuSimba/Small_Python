#ifndef _PY_DICT_OBJECT_H_
#define _PY_DICT_OBJECT_H_
#include "py_type_object.h"

typedef struct tagPyDictObject
{
    PyObject_HEAD;
    map<long, PyObject*> dict;
} PyDictObject;

PyObject* PyDictCreate();
PyObject* PyDict_GetItem(PyObject* target, PyObject* key);
int PyDict_SetItem(PyObject* target, PyObject* key, PyObject* value);
void Dealloc_Dict(PyObject* dict);

extern PyTypeObject PyDict_Type;

#endif
