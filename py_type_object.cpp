#include "py_type_object.h"

PyTypeObject PyType_Type = 
{
    PyObject_HEAD_INIT(&PyType_Type),
    "type",
    NULL,
    NULL,
    NULL
};
