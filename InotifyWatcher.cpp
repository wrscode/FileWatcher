/*
 * File name: Watcher.cpp
 * author: wrscode
 */

#include "Inotify.h"
#include "InotyfyWatcher.h"

namespace Inotify {
Watcher::Watcher(const std::string& PathToWatch, const Mask Mask_) :
        mPath{PathToWatch}, mMask { Mask_ }, mInotify{nullptr}, mDesc { -1 }{
}

Watcher::~Watcher() {
    if(isConnect2Inotify()){
        mInotify->rmWatch(*this);
        mInotify = nullptr;
    }
}

} // namespace Inotify
