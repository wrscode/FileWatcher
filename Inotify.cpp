/*
 * File name: Inotify.cpp
 * author: wrscode
 */

#include "Inotify.h"
#include "InotifyTypes.h"
#include <sstream>


namespace Inotify {

Inotify::Inotify(const std::size_t SizeOfEventsBuffer) : mEventsBuffer(SizeOfEventsBuffer, 0),
        mDesc { -1 } {
}

Inotify::~Inotify() {
    if (isOpen()) {
        close();
    }
}

void Inotify::init() {
    mDesc = inotify_init();
    if(mDesc < 0){
        std::ostringstream oss;
        oss << __PRETTY_FUNCTION__ << " " << __FILE__ << __LINE__ << "descriptor: " << mDesc << "errno: " << errno;
        throw std::runtime_error(oss.str());
    }
}

void Inotify::close() {
    ::close(mDesc);
}

inline bool Inotify::isOpen() const {
    return (-1 < mDesc);
}

void Inotify::addWatch(Watcher& Watcher_) {

    Watcher_.mDesc = inotify_add_watch(mDesc, Watcher_.mPath.c_str(), cast(Watcher_.mMask));
    if(Watcher_.mDesc < 0){
        std::ostringstream oss;
        oss << __PRETTY_FUNCTION__ << " " << __FILE__ << __LINE__ << "errno: " << errno;
        throw std::runtime_error(oss.str());
    }

    auto result = mMapWatcher.insert(std::make_pair(Watcher_.mDesc, &Watcher_));
    if(!result.second){
        std::ostringstream oss;
        oss << __PRETTY_FUNCTION__ << " " << __FILE__ << __LINE__ << "Can't add Watcher to map";
        throw std::runtime_error(oss.str());
    }
}

void Inotify::rmWatch(Watcher& Watcher_) {

    auto retValue =  inotify_rm_watch(mDesc, Watcher_.mDesc);
    if(retValue == -1){
        std::ostringstream oss;
        oss << __PRETTY_FUNCTION__ << " " << __FILE__ << __LINE__ << "errno: " << errno;
        throw std::runtime_error(oss.str());
    }

    mMapWatcher.erase(Watcher_.mDesc);
}

EventIterator Inotify::getEvents() {

    ssize_t size = ::read(mDesc, mEventsBuffer.data(), mEventsBuffer.size());
    if(size < 0){
        std::ostringstream oss;
        oss << __PRETTY_FUNCTION__ << " " << __FILE__ << __LINE__ << "errno: " << errno;
    }

    return EventIterator{mMapWatcher, mEventsBuffer.data(), mEventsBuffer.data() + size};
}

}  // namespace Inotify
