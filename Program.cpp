#include "Program.hpp"

void Program::Run()
{
    Memory* memory = new Memory(1000, 1000);
    while (memory->window.isOpen())
    {
        Handler::Update(*memory);
        GUI::Render(*memory);
    }
    delete memory;
}
