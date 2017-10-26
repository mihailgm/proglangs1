#include <stdbool.h>

struct Object;
struct Application;
struct Widget;
struct Label;
struct Layout;
struct PushButton;
struct VBoxLayout;

#ifdef __cplusplus
extern "C" {
#endif

struct Application* Application_New();

struct Widget* Widget_New(struct Widget* parent);

struct VBoxLayout* VBoxLayout_New(struct Widget* parent);

struct Label* Label_New(struct Widget* parent);

struct PushButton* PushButton_New(struct Widget* parent);

struct Label* Label_New(struct Widget* parent);

const char* Object_GetClassName(struct Object* object);

void Widget_SetLayout(struct Widget* widget, struct Layout* layout);

void Label_SetText(struct Label* label, const char * text);

void Layout_AddWidget(struct Layout* layout, struct Widget* widget);

void PushButton_SetText(struct PushButton* push_button, const char * text) ;

void Widget_SetWindowTitle(struct Widget* widget, const char * text);

void Widget_SetSize(struct Widget* widget, int w, int h);

void Widget_SetVisible(struct Widget* widget, bool visible);

int Application_Exec(struct Application* app);

void Object_Delete(struct Object* object);

void PushButton_SetOnClicked(struct PushButton* button, void (*func)(struct Object*));

#ifdef __cplusplus
}

#endif
