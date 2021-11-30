#ifndef BANJO_GAME_IO_HPP
#define BANJO_GAME_IO_HPP

#include <functional>
#include <iostream>
#include <string>

namespace spic::io {
    bool DirectoryExists(const std::string& path);

    bool CreateDirectory(const std::string& path);

    bool FileExists(const std::string& path);

    /**
     * Open the file with the path and call the given writing function.
     *
     * @param path The path of the file.
     * @param writingFn A function to be called with the ostream of the file, in which you can write content to the
     * file.
     */
    void OpenFileForWriting(const std::string& path, const std::function<void(std::ostream&)>& writingFn);

    void OpenFileForReading(const std::string& path, const std::function<void(std::istream&)>& readingFn);
}

#endif
