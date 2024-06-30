#pragma once

#include <cstdlib>
#include <optional>
#include <vector>


using Pixel = std::optional<float>;

class PixelBuffer
{
public:
    PixelBuffer(std::size_t width, std::size_t height)
        : m_width{ width }
        , m_height{ height }
    {
        m_data.resize(width * height);
    }

    std::size_t width() const { return m_width; }

    std::size_t height() const { return m_height; }

    const Pixel& at(std::size_t i, std::size_t j) const { return m_data[j * m_width + i]; }

    Pixel& at(std::size_t i, std::size_t j) { return m_data[j * m_width + i]; }

private:
    std::size_t m_width;
    std::size_t m_height;
    std::vector<Pixel> m_data;
};
