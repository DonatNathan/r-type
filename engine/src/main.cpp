
#include "../includes/main.hpp"
#include "../includes/Ecs.hpp"

int main(int argc, char **argv)
{
    Ecs ecs(argc, argv);
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;
    std::chrono::high_resolution_clock::time_point elapsed_time;

    ecs.Create();

    while(true)
    {
        start_time = std::chrono::high_resolution_clock::now();
        ecs.Update();
        end_time =  std::chrono::high_resolution_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count();
        if (elapsed_time < (1.0 / 60))
            std::this_thread::sleep_for(std::chrono::duration<double>((1.0 / 60) - elapsed_time));
    }
}