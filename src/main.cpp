#include "scoped_timer.h"
#include "scoped_file.h"

#include <thread>
#include <iostream>

void SimulatedWork()
{
    ScopedTimer timer("SimulatedWork");
    std::this_thread::sleep_for(std::chrono::milliseconds(120));
}

void WriteMessage()
{
    ScopedFile file("example.txt", "w");
    if (!file.is_open())
    {
        std::perror("Error opening file");
        return;
    }

    std::fputs("Hello from ScopedFile\n", file.get());
}

int main()
{
    {
        ScopedTimer timer("Main Scope");
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    SimulatedWork();

    {
        ScopedTimer timer("Move Test");
        ScopedTimer movedTimer = std::move(timer);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }

    WriteMessage();

    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}
