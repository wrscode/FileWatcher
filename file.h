/*
 * File name: file.h
 * author: wrscode
 */

#ifndef FILE_H_
#define FILE_H_

#include <string>
#include <fcntl.h>
#include <unistd.h>

namespace wrscode {
class File {

public:
    File(std::string Name) :
            mName { std::move(Name) }, mDesc { -1 } {
    }

    ~File() {
        if (isOpen()) {
            close();
        }
    }

    void open(const int flags) {
        mDesc = ::open(mName.c_str(), flags);
    }

    inline void close() {
        if (isOpen()) {
            ::close(mDesc);
        }
    }

    inline bool isOpen() {
        return (-1 < mDesc);
    }

    std::string const& getName() {
        return mName;
    }

private:
    std::string mName;
    int mDesc;
};
} //namespace wrscode

#endif /* FILE_H_ */
