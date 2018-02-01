/*
 * File name: Inotify.h
 * author: wrscode
 */

#ifndef INOTIFY_H_
#define INOTIFY_H_

#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unordered_map>
#include <vector>

#include "InotifyEventIterator.h"
#include "InotyfyWatcher.h"

namespace Inotify {
class Inotify {
public:
    Inotify(const std::size_t SizeOfEventsBuffer);
    virtual ~Inotify();

    Inotify(const Inotify&) = delete;
    Inotify(Inotify&&) = delete;

    Inotify& operator=(const Inotify&) = delete;
    Inotify& operator=(Inotify&&) = delete;

    void init();
    void close();
    bool isOpen() const;

    void addWatch(Watcher& Watcher_);
    void rmWatch(Watcher& Watcher_);

    EventIterator getEvents();
private:
    std::unordered_map<int, Watcher*> mMapWatcher;
    std::vector<char> mEventsBuffer;
    int mDesc;
};
} // namespace Inotify

#endif /* INOTIFY_H_ */
