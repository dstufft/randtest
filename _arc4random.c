#include <stdlib.h>
#include <Python.h>


static PyObject *
arc4random_arc4random_float(PyObject *self)
{
    return PyFloat_FromDouble((double)arc4random() / UINT_MAX);
}


static PyMethodDef ARC4RandomMethods[] = {
    {"arc4random_float", (PyCFunction)arc4random_arc4random_float, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL},
};


static struct PyModuleDef arc4randommodule = {
   PyModuleDef_HEAD_INIT, "_arc4random", NULL, -1, ARC4RandomMethods,
};


PyMODINIT_FUNC
PyInit__arc4random(void)
{
    PyObject *m;

    m = PyModule_Create(&arc4randommodule);
    if (m == NULL)
        return NULL;

    return m;
}
