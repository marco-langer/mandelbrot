#include "Mandelbrot.hpp"

#include "Write.hpp"

#include <fmt/core.h>

#include <filesystem>


int main()
{
    const Params params{ .size{ .width{ 1280 }, .height{ 720 } },
                         .region{ .x{ -2.5F }, .y{ -1.0F }, .width{ 3.5F }, .height{ 2.0F } },
                         .maxIterations{ 100 },
                         .threshhold{ 1000.0F } };

    const std::filesystem::path filePath{ "mandelbrot.png" };

    if (const auto writeResult{ write(createMandelbrot(params), filePath) }; !writeResult) {
        fmt::print(
            "error writing file '{}': {}\n",
            reinterpret_cast<const char*>(filePath.u8string().c_str()),
            writeResult.error());
    }
}
