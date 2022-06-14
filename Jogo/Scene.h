//////////////////////////////////////////////////////////////////////////
#ifndef SCENE
#define SCENE

#include <list>
using std::list;
class Object;

//////////////////////////////////////////////////////////////////////////
class Scene
{
private:
	list <Object*> objects;
	list <Object*>::iterator next;
	list <Object*>::iterator it;

public:
    Scene();
    ~Scene();

    void Add(Object* obj);
    void Update();
    void Draw();

    void Begin();
    Object* Next();
    void Remove();
};

//////////////////////////////////////////////////////////////////////////

#endif