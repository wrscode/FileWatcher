/*
 * File name: InotifyEventIterator.cpp
 * author: wrscode
 */

#include "InotifyEventIterator.h"
#include "InotyfyWatcher.h"

namespace Inotify {

EventIterator::EventIterator(std::unordered_map<int, Watcher*>& MapWatcher, char const* BuffBegin, char const* BuffEnd) :
        mMapWatcher(MapWatcher), mBuffCurr(BuffBegin), mBuffEnd(BuffEnd) {
}

EventIterator::~EventIterator() {
}

struct inotify_event const* EventIterator::getRaw() {
    return NotifyEventElement(mBuffCurr);
}

Watcher* EventIterator::getWatcher(){
    return mMapWatcher.at(NotifyEventElement(mBuffCurr)->wd);
}

bool EventIterator::next() {
    auto length = NotifyEventElement(mBuffCurr)->len + sizeof(struct inotify_event);
    mBuffCurr = mBuffCurr + length;
    if(mBuffCurr < mBuffEnd) {
        return true;
    }
    return false;
}

}  // namespace Inotify
