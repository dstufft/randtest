#include <stdlib.h>
#include <Python.h>


static PyObject *
arc4random_arc4random_float(PyObject *self)
{
    PY_UINT32_T a = arc4random() >> 5;
    PY_UINT32_T b = arc4random() >> 6;
    double res53_random = (a * 67108864.0 + b) * (1.0 / 9007199254740992.0);
    return PyFloat_FromDouble(res53_random);
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
