#ifndef BANJO_GAME_IO_HPP
#define BANJO_GAME_IO_HPP

#include <functional>
#include <iostream>
#include <string>

namespace spic::io {
    /**
     * Check if a directory exists.
     *
     * @param path The path of the directory.
     * @return TRUE if the directory exists, FALSE if not.
     */
    bool DirectoryExists(const std::string& path);

    /**
     * Create a directory.
     *
     * @param path The path of the directory.
     * @return TRUE if the creation was successful, FALSE if not.
     */
    bool CreateDirectory(const std::string& path);

    /**
     * Check if a file exists.
     *
     * @param path The path of the file.
     * @return TRUE if the file exists, FALSE if not.
     */
    bool FileExists(const std::string& path);

    /**
     * Open the file with the path and call the given writing function.
     *
     * @param path The path of the file.
     * @param writingFn A function to be called with the ostream of the file, in which you can write content to the
     * file.
     */
    void OpenFileForWriting(const std::string& path, const std::function<void(std::ostream&)>& writingFn);

    /**
     * Open the file for reading.
     *
     * @param path The path of the file.
     * @param readingFn A function to be called with the istream of the file, in which you can read the data from the
     * file.
     */
    void OpenFileForReading(const std::string& path, const std::function<void(std::istream&)>& readingFn);
}

#endif
