#include <iostream>
#include <string.h>
using namespace std;
namespace pet
{
    typedef string kind;
    typedef string petname;
    typedef string voice;
    typedef class dog
    {
    private:
        kind m_kindName;

    protected:
        petname m_dogName;
        int m_age;
        voice m_voice;
        void setVoice(kind name);

    public:
        dog(kind name);
        void sound();
        void setName(petname name);
    } Dog, DOG;
    void dog::setVoice(kind name)
    {
        if (name == "北京犬")
        {
            m_voice = "嗷嗷";
        }
        else if (name == "狼犬")
        {
            m_voice = "嗷呜";
        }
        else if (name == "黄丹犬")
        {
            m_voice = "呜嗷";
        }
    }
    dog::dog(kind name)
    {
        m_kindName = name;
        m_dogName = name;
        setVoice(name);
    }
    void dog::sound()
    {
        cout << m_dogName << "发出" << m_voice << "的叫声" << endl;
    }
    void dog::setName(petname name)
    {
        m_dogName = name;
    }
}
using pet::dog;
using pet::DOG;
int main()
{
    dog a = dog("北京犬");
    pet::DOG b = pet::Dog("狼犬");
    pet::DOG c = pet::DOG("黄丹犬");
    a.setName("小白");
    c.setName("阿黄");
    a.sound();
    b.sound();
    c.sound();
    system("pause");
    return 0;
}