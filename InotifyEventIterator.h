/*
 * File name: InotifyEventBuffer.h
 * author: wrscode
 */

#ifndef INOTIFYEVENTITERATOR_H_
#define INOTIFYEVENTITERATOR_H_

#include <sys/inotify.h>
#include <unordered_map>
#include <cstdint>

namespace Inotify {

#define NotifyEventElement(elem) reinterpret_cast<struct inotify_event const*>((elem))

class Watcher;
class EventIterator {
public:
    EventIterator(std::unordered_map<int, Watcher*>& MapWatcher, char const* BuffBegin, char const* BuffEnd);
    ~EventIterator();

    EventIterator(const EventIterator&) = delete;
    EventIterator(EventIterator&&) = default;

    EventIterator& operator=(const EventIterator&) = delete;
    EventIterator& operator=(EventIterator&&) = delete;

    struct inotify_event const* getRaw();
    Watcher* getWatcher();

    bool next();

private:
    std::unordered_map<int, Watcher*>& mMapWatcher;
    char const *mBuffCurr;
    char const *const mBuffEnd;
};
}
  // namespace Inotify

#endif /* INOTIFYEVENTITERATOR_H_ */
