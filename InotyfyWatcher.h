/*
 * File name: Watcher.h
 * author: wrscode
 */

#ifndef INOTYFYWATCHER_H_
#define INOTYFYWATCHER_H_

#include "InotifyTypes.h"
#include <string>
#include <memory>

namespace Inotify {

class Inotify;
class Watcher {
public:
    friend class Inotify;
    using RPtr = Watcher*;
    using UPtr = std::unique_ptr<Watcher>;

public:
    Watcher(const std::string& PathToWatch, const Mask Mask_);

    Watcher(const Watcher&) = delete;
    Watcher(Watcher&&) = delete;

    Watcher& operator=(const Watcher&) = delete;
    Watcher& operator=(Watcher&&) = delete;

    virtual ~Watcher();

    bool isConnect() const {
        return (-1 < mDesc);
    }

    const std::string& getPath() const {
        return mPath;
    }

    Mask getFlags() const {
        return mMask;
    }

protected:
    void setDesciptor(const int NewDesc) {
        mDesc = NewDesc;
    }

    int getDesciptor() const {
        return mDesc;
    }

    bool isConnect2Inotify() const {
        return (mInotify != nullptr);
    }

private:
    std::string mPath;
    Mask mMask;

    Inotify* mInotify;
    int mDesc;
};
} // namespace Inotify

#endif /* INOTYFYWATCHER_H_ */
