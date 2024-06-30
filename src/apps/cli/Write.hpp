#pragma once

#include "PixelBuffer.hpp"

#include <tl/expected.hpp>

#include <filesystem>
#include <string>


tl::expected<void, std::string>
write(const PixelBuffer& pixelBuffer, const std::filesystem::path& filePath);
