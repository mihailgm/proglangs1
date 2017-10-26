#include "widgets.h"

#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QVBoxLayout>


#include <cstdio>


extern "C" {

int argc = 1;
char* first_arg = "new application";

struct Application* Application_New() {
    return (struct Application*) (struct QObject*) new QApplication(argc, &first_arg);
}

struct Widget* Widget_New(struct Widget* parent) {
    auto res = new QWidget((struct QWidget*)(struct QObject*) parent);
    return (struct Widget*)(struct QObject*) res;
}

struct VBoxLayout* VBoxLayout_New(struct Widget* parent) {
    return (struct VBoxLayout*)(struct QObject*) new QVBoxLayout((struct QWidget*)(struct QObject*) parent);
}

struct Label* Label_New(struct Widget* parent) {
    return (struct Label*)(struct QObject*) new QLabel((struct QWidget*)(struct QObject*) parent);
}

struct PushButton* PushButton_New(struct Widget* parent) {
    return (struct PushButton*)(struct QObject*) new QPushButton((struct QWidget*)(struct QObject*) parent);
}

const char* Object_GetClassName(struct Object* object) {
    return ((struct QObject*) object)->metaObject()->className() + 1;
}

void Widget_SetLayout(struct Widget* widget, struct Layout* layout) {
    ((struct QWidget*)(struct QObject*) widget)->setLayout((struct QLayout*)(struct QObject*) layout);
}

void Label_SetText(struct Label* label, const char * text) {
    ((struct QLabel*)(struct QObject*) label)->setText(QString::fromUtf8(text));
}

void Layout_AddWidget(struct Layout* layout, struct Widget* widget) {
    ((struct QLayout*)(struct QObject*) layout)->addWidget((struct QWidget*)(struct QObject*) widget);
}

void PushButton_SetText(struct PushButton* push_button, const char * text) {
    ((struct QPushButton*)(struct QObject*) push_button)->setText(QString::fromUtf8(text));
}

void Widget_SetWindowTitle(struct Widget* widget, const char * text) {
    ((struct QWidget*)(struct QObject*) widget)->setWindowTitle(QString::fromUtf8(text));
}

void Widget_SetSize(struct Widget* widget, int w, int h) {
    ((struct QWidget*)(struct QObject*) widget)->setFixedSize(w, h);
}

void Widget_SetVisible(struct Widget* widget, bool visible) {
    ((struct QWidget*)(struct QObject*) widget)->setVisible(visible);
}

int Application_Exec(Application* app) {
    return ((struct QApplication*)(struct QObject*)app)->exec();
}

void Object_Delete(Object* object) {
    delete ((struct QObject*) object);
}

void PushButton_SetOnClicked(struct PushButton* button, void (*func)(struct Object*)) {
    QObject::connect((struct QPushButton*)(struct QObject*) button, &QPushButton::clicked, [=](){
        func((struct Object*)button);
    });
}

}
