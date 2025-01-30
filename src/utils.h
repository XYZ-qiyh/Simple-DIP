#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

// Function to get the filename without the extension
std::string getFilenameWithoutExtension(const std::string& filepath) {
    // Find the last occurrence of the directory separator
    size_t lastSlashPos = filepath.find_last_of("/\\");
    if (lastSlashPos == std::string::npos) {
        lastSlashPos = 0; // If no slash, start from the beginning
    } else {
        lastSlashPos++; // Move past the slash
    }

    // Extract the filename (with extension)
    std::string filename = filepath.substr(lastSlashPos);

    // Find the last occurrence of the dot (.)
    size_t lastDotPos = filename.find_last_of('.');
    if (lastDotPos == std::string::npos) {
        // If no dot, return the entire filename
        return filename;
    }

    // Return the filename without the extension
    return filename.substr(0, lastDotPos);
}


bool createDirectoryIfNotExists(const std::string& path) {
#ifdef _WIN32
    // Windows implementation
    if (CreateDirectory(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
        return true;
    }
#else
    // Unix-like implementation
    mode_t mode = 0755;
    if (mkdir(path.c_str(), mode) == 0 || errno == EEXIST) {
        return true;
    }
#endif
    return false;
}
