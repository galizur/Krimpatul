#include "krpch.hpp"

#include "Window.hpp"

auto main(int argc, char **argv) -> int
{
    Win win;
    win.show();
    nana::exec();
    return 0;
}
