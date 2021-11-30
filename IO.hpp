#ifndef BANJO_GAME_IO_HPP
#define BANJO_GAME_IO_HPP

#include <string>

namespace spic::io {
    bool DirectoryExists(const std::string& path);

    bool CreateDirectory(const std::string& path);

    bool FileExists(const std::string& path);
}

#endif
