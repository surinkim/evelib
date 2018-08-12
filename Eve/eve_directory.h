#ifndef _EVE_DIRECTORY_
#define _EVE_DIRECTORY_

#include <string>
#include <functional>
#include <experimental\filesystem>

namespace fs = std::experimental::filesystem;
namespace eve
{

using Result = std::pair<bool, std::string>;

const Result CreateDirectory(const fs::path& dir)
{
    auto err = std::error_code{};
    auto ret = fs::create_directory(dir, err);
    return Result(ret, err.message());
}

const Result RemoveDirectory(const fs::path& dir)
{
    auto err = std::error_code{};
    auto ret = fs::remove_all(dir, err) != static_cast<std::uintmax_t>(-1);
    return Result(ret, err.message());
}

const Result EnumerateDirectory(const fs::path& dir, 
                                std::function<void(const std::string&)> dirFunc,
                                std::function<void(const std::string&)> fileFunc)
{
    if (!fs::exists(dir) || !fs::is_directory(dir))
    {
        return Result(false, 
                      dir.string() + " is not a directory.");
    }

    for (auto const & entry : fs::directory_iterator(dir))
    {
        auto fileName = entry.path().filename();
        if (fs::is_directory(entry.status()))
        {
            dirFunc(fileName.string());
        }
        else if (fs::is_regular_file(entry.status()))
        {
            fileFunc(fileName.string());
        }
        else
        {
            continue;
        }
    }

    return Result(true, "");
}

}

#endif // !_EVE_DIRECTORY_