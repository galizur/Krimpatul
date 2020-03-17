#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>

class Win : public nana::form
{
public:
    Win()
    {
        fm.caption("Hello World!");
        btn.create(*this, nana::rectangle(10, 10, 100, 20));
        btn.caption("Quit");
    }

private:
    nana::form   fm;
    nana::button btn;
};
