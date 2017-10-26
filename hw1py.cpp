extern "C" {
#include <Python.h>
}
#include "widgets.h"

extern "C" {


PyObject* Py_Application_New(PyObject* module, PyObject* args)
{
    if (!PyArg_ParseTuple(args, "")) {
        return nullptr;
    }
    struct Application* app = Application_New();
    long long int_repr = reinterpret_cast<long long>(app);
    PyObject * py_result = PyLong_FromLong(int_repr);
    return py_result;
}

PyObject* Py_Widget_New(PyObject* module, PyObject* args)
{
    long long int_arg_repr = 0;
    if (!PyArg_ParseTuple(args, "|l", &int_arg_repr)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(int_arg_repr);
    struct Widget* widget = Widget_New(object_ptr);
    long long int_repr = reinterpret_cast<long long>(widget);
    PyObject * py_result = PyLong_FromLong(int_repr);
    return py_result;
}

PyObject* Py_VBoxLayout_New(PyObject* module, PyObject* args)
{
    long long int_arg_repr = 0;
    if (!PyArg_ParseTuple(args, "|l", &int_arg_repr)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(int_arg_repr);
    struct VBoxLayout* widget = VBoxLayout_New(object_ptr);
    long long int_repr = reinterpret_cast<long long>(widget);
    PyObject * py_result = PyLong_FromLong(int_repr);
    return py_result;
}

PyObject* Py_Label_New(PyObject* module, PyObject* args)
{
    long long int_arg_repr = 0;
    if (!PyArg_ParseTuple(args, "|l", &int_arg_repr)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(int_arg_repr);
    struct Label* widget = Label_New(object_ptr);
    long long int_repr = reinterpret_cast<long long>(widget);
    PyObject * py_result = PyLong_FromLong(int_repr);
    return py_result;
}

PyObject* Py_PushButton_New(PyObject* module, PyObject* args)
{
    long long int_arg_repr = 0;
    if (!PyArg_ParseTuple(args, "|l", &int_arg_repr)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(int_arg_repr);
    struct PushButton* widget = PushButton_New(object_ptr);
    long long int_repr = reinterpret_cast<long long>(widget);
    PyObject * py_result = PyLong_FromLong(int_repr);
    return py_result;
}

PyObject* Py_Object_Delete(PyObject* module, PyObject* args)
{
    long long int_arg_repr;
    if (!PyArg_ParseTuple(args, "l", &int_arg_repr)) {
        return nullptr;
    }
    Object* object_ptr = reinterpret_cast<Object*>(int_arg_repr);
    Object_Delete(object_ptr);
    Py_RETURN_NONE;
}

PyObject* Py_Object_GetClassName(PyObject* module, PyObject* args)
{
    long long int_arg_repr;
    if (!PyArg_ParseTuple(args, "l", &int_arg_repr)) {
        return nullptr;
    }
    Object* object_ptr = reinterpret_cast<Object*>(int_arg_repr);
    const char* name = Object_GetClassName(object_ptr);
    PyObject * py_result = PyUnicode_FromString(name);
    return py_result;
}

PyObject* Py_Widget_SetLayout(PyObject* module, PyObject* args)
{
    long long int_arg1_repr = 0;
    long long int_arg2_repr = 0;
    if (!PyArg_ParseTuple(args, "ll", &int_arg1_repr, &int_arg2_repr)) {
        return nullptr;
    }
    Widget* object1_ptr = reinterpret_cast<Widget*>(int_arg1_repr);
    Layout* object2_ptr = reinterpret_cast<Layout*>(int_arg2_repr);
    Widget_SetLayout(object1_ptr, object2_ptr);
    Py_RETURN_NONE;
}

PyObject* Py_Label_SetText(PyObject* module, PyObject* args)
{
    long long int_arg_repr = 0;
    const char *text;
    if (!PyArg_ParseTuple(args, "ls", &int_arg_repr, &text)) {
        return nullptr;
    }
    Label* object_ptr = reinterpret_cast<Label*>(int_arg_repr);
    Label_SetText(object_ptr, text);
    Py_RETURN_NONE;
}

PyObject* Py_Layout_AddWidget(PyObject* module, PyObject* args)
{
    long long int_arg1_repr = 0;
    long long int_arg2_repr = 0;
    if (!PyArg_ParseTuple(args, "ll", &int_arg1_repr, &int_arg2_repr)) {
        return nullptr;
    }
    Layout* object1_ptr = reinterpret_cast<Layout*>(int_arg1_repr);
    Widget* object2_ptr = reinterpret_cast<Widget*>(int_arg2_repr);
    Layout_AddWidget(object1_ptr, object2_ptr);
    Py_RETURN_NONE;
}

PyObject* Py_PushButton_SetText(PyObject* module, PyObject* args)
{
    long long int_arg_repr = 0;
    const char *text;
    if (!PyArg_ParseTuple(args, "ls", &int_arg_repr, &text)) {
        return nullptr;
    }
    PushButton* object_ptr = reinterpret_cast<PushButton*>(int_arg_repr);
    PushButton_SetText(object_ptr, text);
    Py_RETURN_NONE;
}

PyObject* Py_Widget_SetWindowTitle(PyObject* module, PyObject* args)
{
    long long int_arg_repr = 0;
    const char *text;
    if (!PyArg_ParseTuple(args, "ls", &int_arg_repr, &text)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(int_arg_repr);
    Widget_SetWindowTitle(object_ptr, text);
    Py_RETURN_NONE;
}

PyObject* Py_Widget_SetSize(PyObject* module, PyObject* args)
{
    long long int_arg_repr = 0;
    int width;
    int height;
    if (!PyArg_ParseTuple(args, "lii", &int_arg_repr, &width, &height)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(int_arg_repr);
    Widget_SetSize(object_ptr, width, height);
    Py_RETURN_NONE;
}

PyObject* Py_Widget_SetVisible(PyObject* module, PyObject* args)
{
    long long int_arg_repr = 0;
    int visibility;
    if (!PyArg_ParseTuple(args, "li", &int_arg_repr, &visibility)) {
        return nullptr;
    }
    Widget* object_ptr = reinterpret_cast<Widget*>(int_arg_repr);
    Widget_SetVisible(object_ptr, visibility);
    Py_RETURN_NONE;
}

PyObject* Py_Application_Exec(PyObject* module, PyObject* args)
{
    long long int_arg_repr = 0;
    if (!PyArg_ParseTuple(args, "l", &int_arg_repr)) {
        return nullptr;
    }
    Application* object_ptr = reinterpret_cast<Application*>(int_arg_repr);
    long long return_code = Application_Exec(object_ptr);
    PyObject * py_result = PyLong_FromLong(return_code);
    return py_result;
}

PyObject* last_callback = nullptr;

void button_on_click(Object* widget) {
    PyObject* temp = PyObject_CallObject(last_callback, nullptr);
    Py_XDECREF(temp);
}

PyObject* Py_PushButton_SetOnClicked(PyObject* module, PyObject* args) {
    long long int_arg_repr;
    PyObject* temp;
    if (!PyArg_ParseTuple(args, "lO", &int_arg_repr, &temp)) {
        return NULL;
    }
    if (!PyCallable_Check(temp)) {
        PyErr_SetString(PyExc_TypeError, "parameter must be callable");
        return NULL;
    }
    Py_XINCREF(temp);
    Py_XDECREF(last_callback);
    last_callback = temp;
    PushButton* object_ptr = reinterpret_cast<PushButton*>(int_arg_repr);
    PushButton_SetOnClicked(object_ptr, button_on_click);
    Py_RETURN_NONE;
}

}

PyMODINIT_FUNC PyInit__pywidgets() {

    static PyMethodDef methods[] = {
        {"Application_New", Py_Application_New, METH_VARARGS, "New application"},
        {"Object_GetClassName", Py_Object_GetClassName, METH_VARARGS, "Get class name of object"},
        {"Widget_New", Py_Widget_New, METH_VARARGS, "New widget"},
        {"VBoxLayout_New", Py_VBoxLayout_New, METH_VARARGS, "New VBoxLayout"},
        {"Label_New", Py_Label_New, METH_VARARGS, "New Label"},
        {"PushButton_New", Py_PushButton_New, METH_VARARGS, "New PushButton"},
        {"Object_Delete", Py_Object_Delete, METH_VARARGS, "Delete object"},
        {"Widget_SetLayout", Py_Widget_SetLayout, METH_VARARGS, "Set layout for widget"},
        {"Label_SetText", Py_Label_SetText, METH_VARARGS, "Set text for label"},
        {"Layout_AddWidget", Py_Layout_AddWidget, METH_VARARGS, "Add widget to layout"},
        {"PushButton_SetText", Py_PushButton_SetText, METH_VARARGS, "Set text for PushButton"},
        {"Widget_SetWindowTitle", Py_Widget_SetWindowTitle, METH_VARARGS, "Set title for widget"},
        {"Widget_SetSize", Py_Widget_SetSize, METH_VARARGS, "Set size of widget"},
        {"Widget_SetVisible", Py_Widget_SetVisible, METH_VARARGS, "Set visibility of widget"},
        {"Application_Exec", Py_Application_Exec, METH_VARARGS, "Execute application"},
        {"PushButton_SetOnClicked", Py_PushButton_SetOnClicked, METH_VARARGS, "Set onClicked for button"},
        {NULL, NULL, 0, NULL}
    };

    static PyModuleDef modDef = {
        PyModuleDef_HEAD_INIT,
        "_pywidgets",
        "My cool module!!!",
        -1, methods
    };

    PyObject* mod = PyModule_Create(&modDef);
    return mod;
}
